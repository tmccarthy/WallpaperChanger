/******************************************************************************
    This file is part of WallpaperChanger
    Copyright (C) 2013 Timothy McCarthy

    WallpaperChanger is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    WallpaperChanger is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with WallpaperChanger.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#include "Utility.h"
#include "SystemCommandException.h"

#include <iostream>

#include <spawn.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>

Utility::Utility() {
}

int Utility::executeSystemCommand(std::string binaryName,
        std::vector<std::string> arguments) {
    
    pid_t processID;
    int spawnStatus;
    int processStatus;
    
    // In C++11, strings are stored in contiguous memory, so using the address
    // of the first character as an address for a c string is safe.
    
    std::vector<char*> argv(arguments.size() + 2);
    
    argv[0] = (&binaryName[0]);
    
    for (unsigned int i = 0; i < arguments.size(); i++) {
        argv[i + 1] = &(arguments[i])[0];
    }
    
    // The last element of the argv array has to be a null pointer (required by
    // posix_spawn).
    argv[arguments.size() + 1] = (char*) 0;
    
    // Suppress stdout and stderr
    posix_spawn_file_actions_t actions;
    posix_spawn_file_actions_init(&actions);
    posix_spawn_file_actions_addclose(&actions, STDOUT_FILENO);
    posix_spawn_file_actions_addclose(&actions, STDERR_FILENO);
    
    std::fflush(NULL);
    spawnStatus = posix_spawnp(&processID, binaryName.c_str(), &actions, NULL, 
            argv.data(), environ);
    posix_spawn_file_actions_destroy(&actions);
    
    
    if (spawnStatus == 0) {
        std::fflush(NULL);
        if (waitpid(processID, &processStatus, 0) != -1) {
            return processStatus;
        } else {
            throw SystemCommandException(
                    std::string("Following error occurred while waiting "
                    "for system process: \'") 
                    + std::string(strerror(errno)) 
                    + std::string("\'"));
        }
    } else {
        throw SystemCommandException(
                std::string("Following error occurred when attempting to spawn"
                "system process: \'")
                + std::string(strerror(spawnStatus))
                + std::string("\'"));
    }    
}

int Utility::executeSystemCommand(std::string binaryName,
        std::string argument) {
    std::vector<std::string> arguments = {argument};
    return Utility::executeSystemCommand(binaryName, arguments);
}

std::string Utility::fullPath(std::string path) {
    return boost::filesystem::absolute(boost::filesystem::path(path)).string();
}
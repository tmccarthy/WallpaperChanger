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

#ifndef UTILITY_H
#define	UTILITY_H

#include <string>
#include <vector>

/**
 * Utility class providing static methods used by the rest of the application
 */
class Utility {
public:
    
    /**
     * Execute a system command using the given binary and arguments.
     * @return -2 if the system process failed to spawn, -1 if there was an 
     *         error waiting for the process to finish, and the return value of
     *         the system call otherwise.
     */
    static int executeSystemCommand(std::string binaryName,
            std::vector<std::string> arguments);
    
    /**
     * Execute a system command using the given binary and argument. Otherwise
     * this method behaves in the same way as the above method.
     */
    static int executeSystemCommand(std::string binaryName,
            std::string argument);
    
    /**
     * Return the absolute path name of the given path.
     */
    static std::string fullPath(std::string path);
private:
    Utility();

};

#endif	/* UTILITY_H */


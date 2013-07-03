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

#include <vector>
#include <string>

#include "XfceSwitcher.h"

#include "Wallpaper.h"
#include "Utility.h"
#include "SwitcherException.h"

XfceSwitcher::XfceSwitcher() : Switcher() {
}

XfceSwitcher::~XfceSwitcher() {
}

void XfceSwitcher::performSwitch(Wallpaper& wallpaper) throw
(SwitcherException) {

    try {

        std::string binaryName = "xfconf-query";

        // Try to change wallpaper of first monitor.
        std::vector<std::string> arguments
                = this->getSystemCallArguments(wallpaper, 0);

        if (Utility::executeSystemCommand(binaryName, arguments) != 0) {
            throw SwitcherException(
                    "System command to switch wallpaper indicated error");
        }

        // Try to change wallpaper of other monitors. We simply loop up through
        // the monitor numbers until the system call to change wallpapers 
        // returns an error.
        int monitorNum = 1;
        bool badMonitor = false;

        do {
            arguments = this->getSystemCallArguments(wallpaper, monitorNum++);

            badMonitor = 
                    Utility::executeSystemCommand(binaryName, arguments) != 0;
        } while (!badMonitor);
        
    } catch (SystemCommandException & e) {
        throw SwitcherException(
                std::string("System command failed with following error: \'")
                + std::string(e.what()) + std::string("\'"));
    }

}

std::vector<std::string> XfceSwitcher::getSystemCallArguments(
        Wallpaper & wallpaper, int monitorNum) {
    std::vector<std::string> arguments;

    arguments.push_back("-c");
    arguments.push_back("xfce4-desktop");
    arguments.push_back("-p");
    arguments.push_back("/backdrop/screen0/monitor"
            + std::to_string(monitorNum) + "/image-path");
    arguments.push_back("-s");
    arguments.push_back(wallpaper.getFilePath());

    return arguments;
}
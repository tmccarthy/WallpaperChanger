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

#include "LxdeSwitcher.h"

#include <string>
#include <vector>

#include "Wallpaper.h"
#include "Utility.h"
#include "SwitcherException.h"

LxdeSwitcher::LxdeSwitcher() : Switcher() {
}

LxdeSwitcher::~LxdeSwitcher() {
}

void LxdeSwitcher::performSwitch(Wallpaper & wallpaper) throw
(SwitcherException) {
    std::string binaryName = "pcmanfm";
    std::string argument = std::string("--set-wallpaper=") + wallpaper.getFilePath();

    try {
        if (Utility::executeSystemCommand(binaryName, argument) != 0) {
            throw SwitcherException(
                    "System command to switch wallpaper indicated error");
        }
    } catch (SystemCommandException& e) {
        throw SwitcherException(
                std::string("System command failed with following error: \'") 
                + std::string(e.what()) + std::string("\'"));
    }
}

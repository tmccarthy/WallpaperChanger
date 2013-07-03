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

#include "Switcher.h"

#include <memory>
#include <iostream>

#include "DesktopSession.h"
#include "LxdeSwitcher.h"
#include "XfceSwitcher.h"
#include "UnknownSessionException.h"

Switcher::Switcher() {
}

Switcher::~Switcher() {
}

void Switcher::switchWallpaperTo(Wallpaper& wallpaper)
throw (SwitcherException) {

    if (wallpaper.isFile()) {
        std::cout << "Switch to " << wallpaper.getFilePath() << std::endl;

        this->performSwitch(wallpaper);
    } else {
        throw SwitcherException(std::string("\'") + wallpaper.getFilePath()
                + std::string("\' does not exist or is not a file."));
    }
}

std::unique_ptr<Switcher> Switcher::generate() throw (UnknownSessionException) {

    DesktopSession::DesktopSessionType dType = DesktopSession::getType();

    if (dType == DesktopSession::LUBUNTU || dType == DesktopSession::LXDE) {
        return std::unique_ptr<Switcher>(new LxdeSwitcher());
    } else if (dType == DesktopSession::XFCE
            || dType == DesktopSession::XUBUNTU) {
        return std::unique_ptr<Switcher>(new XfceSwitcher());
    }

    switch (DesktopSession::getType()) {
        case DesktopSession::LUBUNTU:
            return std::unique_ptr<Switcher>(new LxdeSwitcher());
            break;
        case DesktopSession::LXDE:
            return std::unique_ptr<Switcher>(new LxdeSwitcher());
            break;
        case DesktopSession::XFCE:
            return std::unique_ptr<Switcher>(new XfceSwitcher());
        default:
            throw UnknownSessionException(std::string("Unrecognised session \'" 
                    + DesktopSession::getDesktopSessionEnvVar() + "\'"));
            return std::unique_ptr<Switcher>();
            break;
    }
}
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

#ifndef XFCESWITCHER_H
#define	XFCESWITCHER_H

#include <vector>
#include <string>

#include "Switcher.h"
#include "Wallpaper.h"
#include "SwitcherException.h"

/**
 * Class for switching the wallpaper in an XFCE desktop session.
 */
class XfceSwitcher : public Switcher {
public:
    XfceSwitcher();
    virtual ~XfceSwitcher();

    /**
     * Switch the desktop wallpaper to the given wallpaper.
     */
    virtual void performSwitch(Wallpaper & wallpaper) throw
        (SwitcherException);

private:

    /**
     * Returns a vector of arguments suitable for passing into 
     * Utility::execureSystemCommand() with the "xfconf-query" binary.
     * @param monitorNum the monitor whose wallpaper will be changed
     */
    std::vector<std::string> getSystemCallArguments(Wallpaper & wallpaper, 
            int monitorNum);
    
};

#endif	/* XFCESWITCHER_H */


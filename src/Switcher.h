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

#ifndef SWITCHER_H
#define	SWITCHER_H

#include <memory>
#include "SwitcherException.h"
#include "Wallpaper.h"
#include "SystemCommandException.h"
#include "UnknownSessionException.h"

/**
 * Abstract superclass for Switchers. Implementations for particular desktop
 * sessions implement the switchWallpaperTo() method of this class.
 */
class Switcher {
public:
    virtual ~Switcher();

    /**
     * Switch the desktop wallpaper to the given wallpaper.
     */
    void switchWallpaperTo(Wallpaper & wallpaper) throw (SwitcherException);
    
    /**
     * Factory method for generating Switchers based on the current desktop 
     * session.
     */
    static std::unique_ptr<Switcher> generate() throw (UnknownSessionException);

protected:
    Switcher();

    virtual void performSwitch(Wallpaper & wallpaper) throw
        (SwitcherException) = 0;

};

#endif	/* SWITCHER_H */

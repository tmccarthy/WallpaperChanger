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

#ifndef WALLPAPER_H_
#define WALLPAPER_H_

#include<string>

/**
 * Class representing a wallpaper.
 */
class Wallpaper {
public:
    /**
     * Constructor, constructs a Wallpaper object representing the image at the
     * given location. Upon construction, the file path is resolved into an 
     * absolute pathname and is henceforth stored as such.
     */
    Wallpaper(std::string filePath);
    
    virtual ~Wallpaper();

    /**
     * Returns the file path of this Wallpaper.
     */
    std::string getFilePath();
    
    /**
     * Indicates whether the file path associated with this Wallpaper references
     * a file that actually exists.
     */
    bool doesExist();

    /**
     * Indicates whether the filepath associated with this Wallpaper references
     * a file or symlink that actually exists.
     */
    bool isFile();
    
private:
    std::string filePath_;
};

#endif /* WALLPAPER_H_ */

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

#ifndef UNKNOWNSESSIONEXCEPTION_H_
#define UNKNOWNSESSIONEXCEPTION_H_

#include <exception>
#include <string>

/**
 * Exception indicating the current desktop session is not recognised.
 */
class UnknownSessionException : public std::exception {
public:

    /**
     * Constructor, associates the given message with this exception.
     */
    UnknownSessionException(std::string message);
    
    virtual ~UnknownSessionException() throw ();

    /**
     * Returns the message associated with this exception.
     * @return 
     */
    virtual const char * what() const throw ();
private:

    static const std::string DEFAULT_MESSAGE;

    std::string message_;
};

#endif /* UNKNOWNSESSIONEXCEPTION_H_ */

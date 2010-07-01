/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file SessionFileStorage.cpp
 * Ultraviolet CGI Session File storage class definition.
 *
 * Provides layer for retrieving session data from a file
 */

#include <fstream>
#include <iostream>
#include <string>

#include "SessionFileStorage.h"

/**
 *  
 */
uv::SessionFileStorage::SessionFileStorage()
{
    // TODO(Jansen) : set correct path for OS
    this->setPath("/tmp");
}

/**
 *
 */
std::string uv::SessionFileStorage::load(std::string sessionId)
{
    std::string filename = this->path;
    filename.append("/");
    filename.append(sessionId);

    std::fstream fs;
    fs.open(filename.c_str(), std::fstream::in | std::fstream::out);

    std::string sessdata;

    if (fs.is_open()) {
        while (!fs.eof()) {
            getline(fs, sessdata);
        }
        fs.close();
    }

    return sessdata;
}

/**
 *  
 */
bool uv::SessionFileStorage::save(std::string sessionId, std::string data)
{
    std::string filename = this->path;
    filename.append("/");
    filename.append(sessionId);

    std::fstream fs;
    fs.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
    fs << data;

    fs.close();
    return true;
}

/**
 *  
 */
void uv::SessionFileStorage::setPath(std::string path)
{
    this->path = path;
}


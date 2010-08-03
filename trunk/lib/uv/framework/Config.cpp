/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Config.cpp
 * Ultraviolet Core Config class definition.
 *
 * Store configuration variables
 */

#include <string>
#include <iostream>

#include "Config.h"
#include "core/Strlib.h"
#include "core/Ini.h"

/**
 *  
 */
uv::Config::Config(std::string filename)
{
    this->source = uv::Ini(filename);
}

/**
 *  
 */
uv::Config::~Config()
{
}

/**
 *  
 */
std::string uv::Config::get(std::string key, std::string section)
{
    return this->source.get(key, section);
}

std::string uv::Config::list()
{
    return this->source.list();
}

/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Input.cpp
 * Ultraviolet CGI Input class definition.
 *
 * Input is a wrapper for input passed to initialization of the CGI system.
 */

#include <iostream>
#include <cstdlib>

#include "Input.h"

size_t uv::Input::read(char *data, size_t length)
{
    std::cin.read(data, length);
    return std::cin.gcount();
}

/**
 *  
 */
std::string uv::Input::getenv(const char *varName)
{
    char *var = std::getenv(varName);
    return (0 == var) ? std::string("") : var;
}

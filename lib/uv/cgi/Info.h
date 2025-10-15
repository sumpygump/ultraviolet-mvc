/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file Info.h
 * Ultraviolet CGI Info class header file.
 *
 * @see Info.cpp
 */

#ifndef UV_INFO_H_
#define UV_INFO_H_

#include "Environment.h"

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * Info is a class to aggregate vars for display
 *
 * @author Jansen Price <jansen.price@sierra-bravo.com>
 */
class Info
{
public:

    /**
     * Default constructor
     */
    Info();

    /**
     * Display environment vars
     */
    static std::string displayEnvironment(Environment env);

    /**
     * Format an attribute value pair in a table row
     */
    static std::string avPairRow(const std::string &attr, const std::string &value);

}; // class Info

} // namespace uv

#endif // UV_INFO_H_
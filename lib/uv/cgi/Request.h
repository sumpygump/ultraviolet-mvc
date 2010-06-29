/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Request.h
 * Ultraviolet CGI Request class header file.
 *
 * @see Request.cpp
 */

#ifndef UV_REQUEST_H_
#define UV_REQUEST_H_

#include <string>
#include <vector>
#include <map>

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * The Request class is used for storing parameters
 * as part of the HTTP request (GET method)
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Request
{
  public:
    /**
     * Storage for the request vars 
     */
    std::map<std::string, std::string> vars;

    /**
     * Parse the input and store the vars
     */
    void parseInput(std::string value);

    /**
     * Return whether a key exists in this object's vars
     */
    bool keyExists(std::string key);

    /**
     * Return the value for a param, if it exists
     */
    std::string getParam(std::string key);

    /**
     * Operator [] to retrieve params
     */
    std::string operator[](const std::string name);

    /**
     * Generate a list of the vars stored in this object
     */
    std::string list();

}; // class Request

} // uv namespace

#endif // UV_REQUEST

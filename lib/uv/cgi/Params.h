/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file Params.h
 * Ultraviolet CGI Params class header file.
 *
 * @see Params.cpp
 */

#ifndef UV_PARAMS_H_
#define UV_PARAMS_H_

#include <string>
#include <map>

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * The Params class is used for storing parameters
 * as part of the HTTP request (GET method)
 *
 * @author Jansen Price <jansen.price@gmail.com>
 */
class Params
{
public:

    /**
     * Parse the input and store the vars
     */
    void parseInput(const std::string &value);

    /**
     * Return whether a key exists in this object's vars
     */
    bool keyExists(const std::string &key);

    /**
     * Return the value for a param, if it exists
     */
    std::string getParam(const std::string &key);

    /**
     * Operator [] to retrieve params
     */
    std::string operator[](const std::string &name);

    /**
     * Generate a list of the vars stored in this object
     */
    std::string list();

protected:

    /**
     * Storage for the request vars 
     */
    std::map<std::string, std::string> vars;

}; // class Params

} // uv namespace

#endif // UV_PARAMS_H_
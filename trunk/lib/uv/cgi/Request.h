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

//#include <string>
//#include <vector>
//#include <map>

#include "cgi/Environment.h"
#include "cgi/CookieJar.h"
#include "cgi/Params.h"
#include "cgi/Post.h"
#include "cgi/Input.h"

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
     * Default constructor
     */
    Request();

    /**
     * Environment object
     */
    uv::Environment env;

    /**
     * CookieJar object
     */
    uv::CookieJar cookies;

    /**
     * Get params object
     */
    uv::Params get;

    /**
     * Post params object
     */
    uv::Post post;

    /**
     * Raw input from std in
     */
    std::string rawInput;

  protected:

    /**
     * Initialize post params
     */
    void initPost();

    /**
     * Read rawinput from stdin
     */
    void readRawInput();

}; // class Request

} // uv namespace

#endif // UV_REQUEST_H

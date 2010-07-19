/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Response.h
 * Ultraviolet CGI Response class header file.
 *
 * @see Response.cpp
 */

#ifndef UV_RESPONSE_H_
#define UV_RESPONSE_H_

#include "cgi/Headers.h"
#include "cgi/CookieJar.h"

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * The Response class stores object used for the HTTP response
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Response
{
  public:
    /**
     * Default constructor
     */
    Response();

    /**
     * Headers object
     */
    uv::Headers headers;

    /**
     * CookieJar object for outgoing cookies
     */
    uv::CookieJar cookies;

}; // class Response

} // namespace uv

#endif // UV_RESPONSE_H

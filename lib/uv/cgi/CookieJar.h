/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file CookieJar.h
 * Ultraviolet CGI CookieJar class header file.
 *
 * @see CookieJar.cpp
 */

#ifndef UV_COOKIEJAR_H_
#define UV_COOKIEJAR_H_

#include <vector>

#include "Cookie.h"

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * Cookie Jar is a container class for HTTP Cookie objects
 *
 * See rfc 2109 for version 1 of HTTP Cookies
 * http://www.w3.org/Protocols/rfc2109/rfc2109.txt
 * 
 * @author Jansen Price <jansen.price@sierra-bravo.com>
 * @version $Id$
 */
class CookieJar
{
  public:

    /**
     * Default constructor
     */
    CookieJar();

    /**
     * Parse the cookie header and set cookies
     */
    void readCookies(std::string cookieString);

    /**
     * Add a cookie to the jar
     */
    int addCookie(Cookie * cookie);

    /**
     *  
     */
    std::string list();

  protected:

    /**
     * Storage for cookies
     */
    std::vector<Cookie*> cookies;

}; // class CookieJar

} // namespace uv

#endif // UV_COOKIEJAR_H_

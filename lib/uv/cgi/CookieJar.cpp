/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file CookieJar.cpp
 * Ultraviolet CGI CookieJar class definition.
 *
 * A CookieJar object is a container for Cookie objects.
 *
 * @see uv::Cookie
 */

#include <string>
#include <iostream>
#include <vector>

#include "CookieJar.h"
#include "Cookie.h"
#include "core/Strlib.h"

/**
 *  
 */
uv::CookieJar::CookieJar()
{
}

/**
 *  
 */
uv::CookieJar::~CookieJar()
{
    std::vector<Cookie*>::const_iterator cookieIterator;
    const auto cookieBegin = cookies.begin();
    const auto cookieEnd = cookies.end();

    for (cookieIterator = cookieBegin; cookieIterator < cookieEnd; ++cookieIterator) {
        delete *cookieIterator;
    }
}

/**
 *  
 */
void uv::CookieJar::readCookies(const std::string &cookieString)
{
    std::string::size_type pos = 0;
    std::string::size_type oldPos, limit;
    const std::string::size_type sepLen = std::string(";").length();
    std::string name, value;

    oldPos = pos;

    while (true) {
        pos = cookieString.find('=', oldPos);

        if (std::string::npos == pos) {
            break;
        }

        limit = cookieString.find(';', pos);

        if (std::string::npos == limit) {
            limit = cookieString.length();
        }

        // Create a new cookie
        auto *cookie = new Cookie();

        // Retrieve the cookie name
        name = cookieString.substr(oldPos, pos - oldPos);
        Strlib::trim(name);

        // Retrieve the cookie value
        value = cookieString.substr(pos + 1, limit - pos - 1);

        // If the value is enclosed in quotes, remove the quotes
        if (value.substr(0, 1) == "\""
            && value.substr(value.length() - 1, 1) == "\""
        ) {
            value = value.substr(1, value.length() - 2);
        }

        cookie->setName(name);
        cookie->setValue(value);

        // Add cookie to the jar
        addCookie(cookie);

        oldPos = limit + sepLen;
    }
}

/**
 *  
 */
int uv::CookieJar::addCookie(Cookie *cookie)
{
    cookies.push_back(cookie);
    return static_cast<int>(cookies.size());
}

/**
 *  
 */
uv::Cookie *uv::CookieJar::retrieve(const std::string &name)
{
    std::vector<Cookie*>::const_iterator cookieIterator;
    const auto cookieBegin = cookies.begin();
    const auto cookieEnd = cookies.end();

    for (cookieIterator = cookieBegin; cookieIterator < cookieEnd; ++cookieIterator) {
        if ((*cookieIterator)->getName() == name) {
            // Return pointer to the cookie object
            return (*cookieIterator);
        }
    }

    // Return null when there's no cookie available
    return nullptr;
}

/**
 *  
 */
std::string uv::CookieJar::list()
{
    std::vector<Cookie*>::const_iterator cookieIterator;
    const auto cookieBegin = cookies.begin();
    const auto cookieEnd = cookies.end();
    std::string output;

    for (cookieIterator = cookieBegin; cookieIterator < cookieEnd; ++cookieIterator) {
        output.append((*cookieIterator)->toString());
        output.append("\n");
    }

    return output;
}
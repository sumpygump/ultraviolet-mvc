/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Request.cpp
 * Ultraviolet CGI Request class definition.
 *
 * Handles parsing HTTP requests.
 */

#include <iostream>

#include "Request.h"

/**
 *
 */
uv::Request::Request()
{
    // Read cookies
    this->cookies.readCookies(env[Environment::kHttpCookie]);

    // Set up GET params
    this->get.parseInput(env[Environment::kQueryString]);

    // Set up POST
    if (this->env.get(Environment::kRequestMethod) == "POST") {
        initPost();
    }
}

/**
 *  
 */
void uv::Request::initPost()
{
    this->readRawInput();

    this->post.parseInput(this->rawInput, this->env.get(Environment::kContentType));
}

/**
 *  
 */
void uv::Request::readRawInput()
{
    uv::Input input;
    std::vector<char> data(this->env.getContentLength());

    input.read(&data[0], this->env.getContentLength());
    this->rawInput = std::string(&data[0], this->env.getContentLength());
}

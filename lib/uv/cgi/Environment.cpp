/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Environment.cpp
 * Ultraviolet CGI Environment class definition.
 *
 * A wrapper class that provides access to environment variables
 */

#include <string>
#include <cstdlib>

#include "Environment.h"

const std::string uv::Environment::kDocumentRoot   = "DOCUMENT_ROOT";
const std::string uv::Environment::kContentLength  = "CONTENT_LENGTH";
const std::string uv::Environment::kContentType    = "CONTENT_TYPE";
const std::string uv::Environment::kHttpCookie     = "HTTP_COOKIE";
const std::string uv::Environment::kHttpHost       = "HTTP_HOST";
const std::string uv::Environment::kHttpReferer    = "HTTP_REFERER";
const std::string uv::Environment::kHttpUserAgent  = "HTTP_USER_AGENT";
const std::string uv::Environment::kHttps          = "HTTPS";
const std::string uv::Environment::kPath           = "PATH";
const std::string uv::Environment::kQueryString    = "QUERY_STRING";
const std::string uv::Environment::kRemoteAddr     = "REMOTE_ADDR";
const std::string uv::Environment::kRemoteHost     = "REMOTE_HOST";
const std::string uv::Environment::kRemotePort     = "REMOTE_PORT";
const std::string uv::Environment::kRemoteUser     = "REMOTE_USER";
const std::string uv::Environment::kRequestMethod  = "REQUEST_METHOD";
const std::string uv::Environment::kRequestUri     = "REQUEST_URI";
const std::string uv::Environment::kScriptFilename = "SCRIPT_FILENAME";
const std::string uv::Environment::kScriptName     = "SCRIPT_NAME";
const std::string uv::Environment::kServerAdmin    = "SERVER_ADMIN";
const std::string uv::Environment::kServerName     = "SERVER_NAME";
const std::string uv::Environment::kServerPort     = "SERVER_PORT";
const std::string uv::Environment::kServerSoftware = "SERVER_SOFTWARE";

/**
 *  
 */
uv::Environment::Environment()
{
    init();
}

/**
 *  
 */
void uv::Environment::init()
{
    // Store the content length as a long
    contentLength = atol(
        this->get(Environment::kContentLength).c_str()
    );
}


/**
 *  
 */
std::string uv::Environment::get(const std::string name)
{
    return input.getenv(name.c_str());
}

/**
 *  
 */
std::string uv::Environment::operator[](const std::string name)
{
    return this->get(name);
}

/**
 *  
 */
unsigned long uv::Environment::getContentLength()
{
    return contentLength;
}

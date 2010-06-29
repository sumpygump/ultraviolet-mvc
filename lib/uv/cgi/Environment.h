/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Environment.h
 * Ultraviolet CGI Environment class header file.
 *
 * @see Environment.cpp
 */

#ifndef UV_ENVIRONMENT_H_
#define UV_ENVIRONMENT_H_

#include "Input.h"

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * Environment class provides an interface into CGI Environment Variables
 *
 * @author Adam Ranfelt <adamRenny@gmail.com> 
 * @author Jansen Price <jansen.price@gmail.com> 
 * @version $Id$
 */
class Environment
{
  public:
    /**
     * Stores CGI environment variable for the document root 
     */
    static const std::string kDocumentRoot;

    /**
     * Stores CGI environment variable for the content length
     */
    static const std::string kContentLength;

    /**
     * Stores CGI environment variable for the content type
     */
    static const std::string kContentType;

    /**
     * Stores CGI environment variable for the http header of cookies
     */
    static const std::string kHttpCookie;

    /**
     * Stores CGI environment variable for the host
     */
    static const std::string kHttpHost;

    /**
     * Stores CGI environment variable for the referer
     */
    static const std::string kHttpReferer;

    /**
     * Stores CGI environment variable for the user agent
     */
    static const std::string kHttpUserAgent;

    /**
     * Stores CGI environment variable for the https protocol
     */
    static const std::string kHttps;

    /**
     * Stores CGI environment variable for the path
     */
    static const std::string kPath;

    /**
     * Stores CGI environment variable for the query string
     */
    static const std::string kQueryString;

    /**
     * Stores CGI environment variable for the client remote address
     */
    static const std::string kRemoteAddr;

    /**
     * Stores CGI environment variable for the remote host
     */
    static const std::string kRemoteHost;

    /**
     * Stores CGI environment variable for the remote port
     */
    static const std::string kRemotePort;

    /**
     * Stores CGI environment variable for the remote user
     */
    static const std::string kRemoteUser;

    /**
     * Stores CGI environment variable for the request method
     */
    static const std::string kRequestMethod;

    /**
     * Stores CGI environment variable for the request URI
     */
    static const std::string kRequestUri;

    /**
     * Stores CGI environment variable for the script filename called
     */
    static const std::string kScriptFilename;

    /**
     * Stores CGI environment variable for the script name
     */
    static const std::string kScriptName;

    /**
     * Stores CGI environment variable for the server admin
     */
    static const std::string kServerAdmin;

    /**
     * Stores CGI environment variable for the server name
     */
    static const std::string kServerName;

    /**
     * Stores CGI environment variable for the server port
     */
    static const std::string kServerPort;

    /**
     * Stores CGI environment variable for the server software
     */
    static const std::string kServerSoftware;

    /**
     * Content length of the http request
     */
    unsigned long contentLength;

    /**
     * Stores the input object
     */
    uv::Input input;

    /**
     * Constructor
     */
    Environment();

    /**
     * Initialize method (called after construction)
     *
     * @return void
     */
    void init();

    /**
     * Returns the environment variable for the supplied environment variable name.
     * Returns "" if a value does not exist
     *
     * @param name Environment Variable Name
     * @return Found Environment Variable Value
     */
    std::string get(const std::string name);

    /**
     * Overloads the [] operator and calls the Environment::get function
     *
     * @param name Environment Variable Name
     * @return Found Environment Variable Value
     */
    std::string operator[] (const std::string name);

    /**
     * Retrieve the content length of the http request
     *
     * @return Content length in bytes
     */
    unsigned long getContentLength();
};

} // namespace uv

#endif // UV_ENVIRONMENT_H_

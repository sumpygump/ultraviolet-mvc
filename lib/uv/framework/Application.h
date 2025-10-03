/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file Application.h
 * Ultraviolet Framework Application class header file.
 *
 * @see Application.cpp
 */

#ifndef UV_FRAMEWORK_APPLICATION_H_
#define UV_FRAMEWORK_APPLICATION_H_

#include "cgi/Request.h"
#include "cgi/Response.h"
#include "cgi/Session.h"

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * uv::framework Namespace
 */
namespace framework
{

/**
 * Ultraviolet Application
 *
 * Provides main application class
 */
class Application
{
  public:
    /**
     * Default constructor
     */
    Application();

    /**
     * Request object
     */
    uv::Request request;

    /**
     * Response object
     */
    uv::Response response;

    /**
     * Session object
     */
    uv::Session session;

}; // class Application

} // namespace framework

} // namespace uv

#endif // UV_FRAMEWORK_APPLICATION_H_
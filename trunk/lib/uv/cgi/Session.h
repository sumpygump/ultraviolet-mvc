/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Session.h
 * Ultraviolet CGI Session class header file.
 *
 * @see Session.cpp
 */

#ifndef UV_SESSION_H_
#define UV_SESSION_H_

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * Session
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Session
{       
  public:

    /**
     * Default constructor
     */
    Session();

    /**
     * Create the session id
     */
    std::string createId();
};

} // namespace uv

#endif // UV_SESSION_H_


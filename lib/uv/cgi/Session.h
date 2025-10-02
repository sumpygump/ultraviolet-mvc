/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file Session.h
 * Ultraviolet CGI Session class header file.
 *
 * @see Session.cpp
 */

#ifndef UV_SESSION_H_
#define UV_SESSION_H_

#include "Params.h"

/**
 * Ultraviolet Namespace
 */
namespace uv
{

class SessionFileStorage;

/**
 * Session
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Session : public Params
{
public:

    /**
     * Default constructor
     */
    Session();

    /**
     * Destructor
     */
    ~Session();

    /**
     * Constructor - with session id
     *
     * @param setSessionId The session id
     */
    explicit Session(const std::string &setSessionId);

    /**
     * Create the session id
     */
    std::string createId();

    /**
     * Retrieve the session id
     */
    std::string getId();

    /**
     * Set param (supports storing strings)
     */
    void setParam(const std::string &name, std::string value);

    /**
     * Set session id
     */
    void setId(const std::string &setSessionId);

    /**
     * Load data via session storage
     */
    void load();

    /**
     * Save this session
     */
    void save();

protected:

    /**
     * Session id
     */
    std::string sessionId;

    /**
     * Storage for the session storage object
     */
    uv::SessionFileStorage* storage;

    /**
     * Initialize the storage object
     */
    void initStorage();
};

} // namespace uv

#endif // UV_SESSION_H_
/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file ISessionStorage.h
 * Ultraviolet CGI interface for session storage header file.
 */

#ifndef UV_ISESSIONSTORAGE_H_
#define UV_ISESSIONSTORAGE_H_

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * Session storage interface
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class ISessionStorage
{
  public:
    /**
     * Destructor
     */
    virtual ~ISessionStorage() {}

    /**
     * Load the data for a given session id
     *
     * @param sessionId The session id
     */
    virtual std::fstream* load(std::string sessionId);

    /**
     * Save data for a given session id
     *
     * @param sessionId The session id
     * @param data A string with the data to save
     */
    virtual bool save(std::string sessionId, std::string data);

    /**
     * Set the path
     *
     * @param path The path
     */
    virtual void setPath(std::string path);

}; // class ISessionStorage

} // namespace uv

#endif // UV_ISESSIONSTORAGE_H_

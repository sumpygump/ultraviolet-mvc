/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file SessionFileStorage.h
 * Ultraviolet CGI Session File storage class file
 */

#ifndef UV_SESSIONFILESTORAGE_H_
#define UV_SESSIONFILESTORAGE_H_

#include <fstream>
#include <string>

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * Session storage in a file
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class SessionFileStorage
{
  public:

    /**
     * Default constructor
     */
    SessionFileStorage();

    /**
     * Load
     */
    std::string load(std::string sessionId);

    /**
     * Save
     */
    bool save(std::string sessionId, std::string data);

    /**
     * Set the path
     */
    void setPath(std::string path);

  protected:

    /**
     * Path to session files
     */
    std::string path;

}; // class SessionFileStorage

} // namespace uv

#endif // UV_SESSIONFILESTORAGE_H_

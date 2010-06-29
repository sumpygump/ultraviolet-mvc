/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Input.h
 * Ultraviolet CGI Input class header file.
 *
 * @see Input.cpp
 */

#ifndef UV_INPUT_H_
#define UV_INPUT_H_

#include <string>

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * Input wrapper
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Input
{
  public:
    /**
     * Read from stdin
     */
    size_t read(char *data, size_t length);

    /**
     * Get an environment variable
     */
    virtual std::string getenv(const char *varName);

}; // class Input

} // namespace uv

#endif // UV_INPUT_H_

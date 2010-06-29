/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Url.h
 * Ultraviolet CGI Url class header file.
 *
 * @see Url.cpp
 */
 
#ifndef UV_URL_H_
#define UV_URL_H_

#include <string>

/**
 * Ultraviolet namespace
 */
namespace uv
{

/**
 * The Url class is utilities for encoding and decoding URL strings
 */
class Url
{
  public:

    /**
     * Encode a URL
     */
    static std::string encode(std::string input);

    /**
     * Decode a URL
     */
    static std::string decode(std::string input);

}; // class Url

} // namespace uv

#endif // UV_URL_H_

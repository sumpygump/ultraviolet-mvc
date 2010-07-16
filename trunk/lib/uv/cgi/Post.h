/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Post.h
 * Ultraviolet CGI Post class header file.
 *
 * @see Post.cpp
 */

#ifndef UV_POST_H_
#define UV_POST_H_

#include "Params.h"
#include "File.h"

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * The Post class is for handling input from the http request
 * using the POST request method.
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Post : public Params
{
  public:
    /**
     * Parse input and populate vars
     *
     * The input string will be a string in querystring format
     * e.g. "name=value&anothername=anothervalue"
     * or multipart/form-data format
     * e.g. "------boundary839489348934893 Content-Disposition: ..."
     *
     * The contentType is important to determine whether to use
     * multipart/form-data format or regular querystring format
     * 
     * @param input The input string
     * @param contentType The content type of the http request
     */
    void parseInput(std::string input, std::string contentType);

    /**
     * Parse the input via a stream
     *
     * This is not yet implemented
     */
    void parseInput(std::ios stream);

    /**
     * Get the boundary from a header string
     */
    std::string getBoundary(std::string data);

    /**
     * Parse values from a multipart form field
     */
    void parseFormField(std::string data);

    /**
     * Parse values from a multipart header
     */
    std::map<std::string, std::string> parseMultipartHeader(std::string data);

    /**
     * File uploads container
     */
    std::map<std::string, uv::File> files;
};

} // namespace uv

#endif // UV_POST_H

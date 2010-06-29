/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Headers.h
 * Ultraviolet CGI Headers class header file.
 *
 * @see Headers.cpp
 */

#ifndef UV_HEADERS_H_
#define UV_HEADERS_H_

#include <vector>

/**
 * Ultraviolet Namespace
 */
namespace uv
{

/**
 * Headers class provides a representation of output HTTP headers
 *
 * @author Adam Ranfelt <adamRenny@gmail.com> 
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Headers
{       
  public:
    /**
     * Default Header Constructor
     */
    Headers ();

    /**
     * Sets a header with a value
     *
     * @param value Value of the header to be set
     */
    void set (std::string value);

    /**
     * Returns a converted string form of the Headers object
     *
     * @return Headers in String form
     */
    std::string toString ();

    /**
     * Overloaded stream output function to output to streams
     *
     * @param out Output Stream
     * @param header Header to be output
     * @return Stream written to
     */
    friend std::ostream& operator<< (std::ostream& out, Headers& header);

  protected:
    /**
     * Whether the string has been assembled
     */
    bool isAssembled;

    /**
     * Dynamic list of headers
     */
    std::vector<std::string> headerValues;

    /**
     * Header output string
     */
    std::string headers;

    /**
     * Generates the output string
     */
    void assemble ();
};

} // namespace uv

#endif // UV_HEADERS_H_

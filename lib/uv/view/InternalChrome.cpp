/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file InternalChrome.cpp
 * Ultraviolet View InternalChrome class definition.
 *
 * Provides default chrome layout functionality
 */

#include <sstream>

#include "InternalChrome.h"

/**
 *
 */
uv::InternalChrome::InternalChrome()
{
    title = "Ultraviolet MVC";
}

/**
 *  
 */
void uv::InternalChrome::setTitle(std::string title)
{
    this->title = title;
}

/**
 *  
 */
std::string uv::InternalChrome::wrapContent(std::string content)
{
    std::ostringstream oss (std::ostringstream::out);

    oss << "<html>"
        << "<head>"
        << "<title>" << title << "</title>" << std::endl
        << getStyles()
        << "</head>" << std::endl
        << "<body>" << std::endl
        << "<div id=\"contain\">" << std::endl
        << content << std::endl
        << "</div>" << std::endl
        << "</body>" << std::endl
        << "</html>" << std::endl;

    return oss.str();
}

/**
 *  
 */
std::string uv::InternalChrome::getStyles()
{
    std::ostringstream oss (std::ostringstream::out);

    oss << "<style type=\"text/css\">"
        "body{margin:0;font-size:13px;font-family:sans-serif;padding:0 2em;background-color:#e6ddd5;}"
        "#contain{background-color:#fff;max-width:65em;min-width:20em;margin:4em auto;padding:3em;-moz-border-radius:10px;-webkit-border-radius:10px;border:1px solid threedshadow;}"
        "h1{border-bottom:1px solid #e6ddd5;font-size:160%;font-weight:normal;margin:0 0 0.6em;}"
        "h2{border-bottom:1px solid #e6ddd5;font-size:120%;font-weight:normal;margin:0.6em 0;}"
        "td.uv-attr{font-size:13px;font-weight:bold;text-align:right;padding-right:1em;}"
        "td.uv-value{font-family:monospace;width:80%;word-wrap:break-word;}"
        ".error{color:#f00;}"
        ".error-message{font-size:130%;}"
        "</style>" << std::endl;

    return oss.str();
}

/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
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
void uv::InternalChrome::setTitle(const std::string &titleInput)
{
    this->title = titleInput;
}

/**
 *  
 */
std::string uv::InternalChrome::wrapContent(const std::string &content) const
{
    std::ostringstream oss(std::ostringstream::out);

    oss << "<html>"
        << "<head>"
        << "<title>" << title << "</title>" << std::endl
        << getStyles()
        //<< "<script type=\"text/javascript\" src=\"http://code.jquery.com/jquery-1.4.2.min.js\"></script>" << std::endl
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
    std::ostringstream oss(std::ostringstream::out);

    oss << "<style type=\"text/css\">"
        "body{margin:0;font-size:13px;font-family:sans-serif;padding:0 2em;background:#8d6b9c;background:linear-gradient(122deg, rgba(141, 107, 156, 1) 0%, rgba(163, 5, 89, 1) 100%);}"
        "#contain{background-color:#fff;max-width:65em;min-width:20em;margin:4em auto;padding:3em;-moz-border-radius:10px;-webkit-border-radius:10px;border:1px solid threedshadow;}"
        "h1{border-bottom:1px solid #e6ddd5;font-size:160%;font-weight:normal;margin:0 0 0.6em;}"
        "h2{border-bottom:1px solid #e6ddd5;font-size:120%;font-weight:normal;margin:0.6em 0;}"
        "pre{overflow-x:auto;}"
        ".uv-table{overflow-x:auto;}"
        "td.uv-attr{font-size:13px;font-weight:bold;text-align:right;padding-right:1em;padding-bottom:4px;min-width:120px;vertical-align:top;}"
        "td.uv-value{font-family:monospace;width:80%;word-wrap:break-word;padding-bottom:4px;}"
        ".error{color:#f00;}"
        ".error-message{font-size:130%;}"
        "</style>" << std::endl;

    return oss.str();
}

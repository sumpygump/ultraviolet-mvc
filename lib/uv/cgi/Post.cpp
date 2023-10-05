/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Post.cpp
 * Ultraviolet CGI Post class definition.
 *
 * Handles a form post via HTTP POST request.
 *
 * @see uv::Params
 */

#include <iterator>

#include "Post.h"
#include "File.h"
#include "core/Strlib.h"

/**
 * Parse input
 */
void uv::Post::parseInput(std::string input, std::string contentType)
{
    // Detect whether multipart/form-data
    if (contentType.substr(0, 9) == "multipart") {
        // get boundary
        std::string boundary = getBoundary(contentType);

        std::string fieldSeparator = "--";
        fieldSeparator.append(boundary);
        fieldSeparator.append("\r\n");

        std::string terminatorSeparator = "--";
        terminatorSeparator.append(boundary);
        terminatorSeparator.append("--\r\n");

        std::string::size_type pos;
        std::string::size_type start = input.find(fieldSeparator);
        std::string::size_type fsLen = fieldSeparator.length();
        std::string::size_type oldPos = start + fsLen;

        while (true) {
            pos = input.find(fieldSeparator, oldPos);

            if (std::string::npos == pos) {
                break;
            }

            // parse the data here
            parseFormField(input.substr(oldPos, pos - oldPos));

            // move position
            oldPos = pos + fsLen;
        }

        // Find terminator boundary
        pos = input.find(terminatorSeparator, oldPos);

        // Parse data here if found
        if (std::string::npos != pos) {
            parseFormField(input.substr(oldPos, pos - oldPos));
        }
    } else {
        Params::parseInput(input);
    }
}

/**
 *
 */
std::string uv::Post::getBoundary(std::string data)
{
    std::string boundaryString = "boundary=";
    std::string::size_type pos = data.find(boundaryString);

    if (pos == std::string::npos) {
        return std::string("");
    }

    std::string boundary = data.substr(pos + boundaryString.length());
    return boundary;
}

/**
 *
 */
void uv::Post::parseFormField(std::string data)
{
    std::string value;
    std::string::size_type valueStart;
    std::string fieldValueTerminator = "\r\n";
    std::string headerTerminator = "\r\n\r\n";
    std::string::size_type headLimit = data.find(headerTerminator, 0);

    if (std::string::npos == headLimit) {
        // error
    }

    valueStart = headLimit + headerTerminator.length();
    value = data.substr(valueStart, data.length());
    value = Strlib::trim(value);

    std::map<std::string, std::string> header = parseMultipartHeader(data.substr(0, headLimit));

    // save the value
    if (header.find("filename") != header.end() && header["filename"] != "") {
        // is a file upload
        files.insert(
            std::map<std::string, uv::File>::value_type (header["name"], uv::File(header["filename"], value, header["content-type"]))
        );
    } else {
        // is a regular form field
        vars[header["name"]] = value;
    }
}

/**
 *
 */
std::map<std::string, std::string> uv::Post::parseMultipartHeader(std::string data)
{
    std::string::size_type quotemark = std::string("\"").length();
    std::map<std::string, std::string> params;
    std::vector<std::string> lines;
    std::vector<std::string> pairs;
    std::vector<std::string> parts;
    int i;
    int line;

    // A regular multipart header will look like this:
    // Content-Disposition: form-data; name="field2"\r\n\r\n
    //
    // A multipart header for a file upload will look like this:
    // Content-Disposition: form-data; name="testfile"; filename="SomeFile.php"\r\n
    // Content-Type: application/x-php\r\n\r\n
    //
    // so, we're gonna parse through this and return a vector with the values
    // we found

    lines = Strlib::explode("\r\n", data);

    for (line = 0; line < lines.size(); line++) {

        if (lines[line].find("Content-Type:") == 0) {
            if (lines[line].find(": ") != std::string::npos) {
                parts = Strlib::explode(": ", lines[line]);
                params["content-type"] = Strlib::trim(parts[1]);
            }
        }

        pairs = Strlib::explode(";", lines[line]);

        // The zeroth item is just "Content-Disposition: form-data"
        for (i = 1; i < pairs.size(); i++) {
            if (pairs[i].find("=") != std::string::npos) {
                parts = Strlib::explode("=", pairs[i]);
                parts[0] = Strlib::trim(parts[0]);
                parts[1] = Strlib::trim(parts[1]);

                params[parts[0]] = parts[1].substr(quotemark, parts[1].length() - quotemark - 1);
            }
        }
    }

    return params;
}

/**
 *
 */
void uv::Post::parseInput(std::ios &stream)
{
}

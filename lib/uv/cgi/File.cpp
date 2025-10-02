/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file File.cpp
 * Ultraviolet CGI File class definition.
 *
 * A File object represents a form uploaded file
 */

#include <fstream>

#include "File.h"
#include "core/Random.h"
#include "core/Strlib.h"

/**
 *  
 */
uv::File::File(const std::string &infilename, const std::string &infiledata, const std::string &inContentType)
{
    filename = infilename;
    filedata = infiledata;
    filesize = infiledata.length();
    contentType = inContentType;
    init();
}

/**
 *  
 */
void uv::File::init()
{
    this->generateTempFilename();
    saveTempFile();
}

/**
 *  
 */
std::string uv::File::generateTempFilename()
{
    // TODO(Jansen) Correctly determine the temp dir
    const std::string tempDir = "/tmp/";

    tempFilename = uv::Random::generateString(8);
    tempFilename.insert(0, tempDir + "uvfile");

    return tempFilename;
}

/**
 *  
 */
void uv::File::saveTempFile() const
{
    std::fstream fs;
    fs.open(tempFilename.c_str(), std::fstream::out | std::fstream::trunc);
    fs << filedata;
    fs.close();
}

/**
 *  
 */
std::string uv::File::list() const
{
    std::string out;

    out.append(
        "   [filename] => " + filename + "\n"
        + "   [tempname] => " + tempFilename + "\n"
        + "   [content-type] => " + contentType + "\n"
        + "   [filesize] => " + Strlib::sizeToString(filesize) + "\n"
    );

    return out;
}

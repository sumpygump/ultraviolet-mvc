/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Strlib.cpp
 * Ultraviolet Core Strlib class definition.
 *
 * String library functions
 */

#include <iostream>
#include <sstream>
#include <vector>

#include "Strlib.h"

/**
 *  
 */
std::vector<std::string> uv::Strlib::explode(std::string delimiter, std::string str)
{
    std::vector<std::string> arr;

    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng == 0) {
        return arr;//no change
    }

    int i = 0; 
    int k = 0;

    while (i < strleng) {
        int j = 0;
        while (i + j < strleng
            && j < delleng
            && str[i + j] == delimiter[j]
        ) {
            j++;
        }

        if (j == delleng) {
            arr.push_back(str.substr(k, i - k));
            i += delleng;
            k = i;
        } else {
            i++;
        }
    }

    arr.push_back(str.substr(k, i - k));
    return arr;
}

/**
 *  
 */
std::string uv::Strlib::trim(std::string& str)
{
    // Trim Both leading and trailing whitespace

    size_t startpos = str.find_first_not_of(" \t\r\n");
    size_t endpos = str.find_last_not_of(" \t\r\n");
 
    // if all spaces or empty return an empty string
    if ((std::string::npos == startpos)
        || (std::string::npos == endpos)
    ) {
        str = "";
    } else {
        str = str.substr(startpos, endpos - startpos + 1);
    }
    return str;
}

/**
 *  
 */
char uv::Strlib::hexToChar(char first, char second) {
    int digit;

    digit = (first >= 'A' ? ((first & 0xDF) - 'A') + 10 : (first - '0'));
    digit *= 16;
    digit += (second >= 'A' ? ((second & 0xDF) - 'A') + 10 : (second - '0'));
    return static_cast<char>(digit);
}

/**
 *
 */
std::string uv::Strlib::sizeToString(size_t sz)
{
    std::stringstream ss;
 
    ss << sz;
 
    return ss.str();
}

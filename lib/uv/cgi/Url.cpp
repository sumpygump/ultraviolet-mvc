/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Url.cpp
 * Ultraviolet CGI Url class definition.
 *
 * Utilities for dealing with URL.
 */

#include <cctype>

#include "Url.h"
#include "core/Strlib.h"

/**
 *  
 */
std::string uv::Url::encode(std::string input)
{
    // TODO(Jansen): implement this method
}

/**
 *  
 */
std::string uv::Url::decode(std::string input)
{
    std::string result;
    int i;

    for (i = 0; i < input.length(); i++) {
        switch (input[i]) {
        case '+':
            result.append(1, ' ');
            break;
        case '%':
            if (i + 2 < input.length()
                && std::isxdigit(input[i + 1])
                && std::isxdigit(input[i + 2])
            ) {
                result.append(1, Strlib::hexToChar(input[i + 1], input[i + 2]));
                i += 2;
            } else {
                result.append(1, '%');
            }
            break;
        default:
            result.append(1, input[i]);
            break;
        }
    }

    return result;
}

/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Random.cpp
 * Ultraviolet Core Random class definition.
 *
 * Generate random things.
 */

#include <cstdlib>
#include <string>
#include <ctime>

#include "Random.h"

/**
 *  
 */
uv::Random::Random()
{
    isSeeded = false;
}

/**
 *  
 */
uv::Random::Random(int seed)
{
    isSeeded = false;
    setSeed(seed);
}

/**
 *  
 */
void uv::Random::setSeed(int seed)
{
    srand(seed);
    isSeeded = true;
}

void uv::Random::setSeed()
{
    time_t timeSeed = time(NULL);
    
    this->setSeed(timeSeed);
}

/**
 *  
 */
std::string uv::Random::generateString(int length)
{
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string result;
    result.resize(length);

    for (int i = 0; i < length; i++) {
        result[i] = charset[rand() % charset.length()];
    }

    return result;
}

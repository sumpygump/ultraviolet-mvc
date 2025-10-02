/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
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

bool uv::Random::isSeeded = false;

/**
 *  
 */
void uv::Random::setSeed(const unsigned int seed)
{
    srand(seed);
    isSeeded = true;
}

void uv::Random::setSeed()
{
    const time_t timeSeed = time(nullptr);
    
    setSeed(static_cast<unsigned int>(timeSeed));
}

/**
 *  
 */
std::string uv::Random::generateString(const size_t length)
{
    if (!isSeeded) {
        setSeed();
    }
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string result;
    result.resize(length);

    for (size_t i = 0; i < length; i++) {
        result[i] = charset[rand() % charset.length()];
    }

    return result;
}
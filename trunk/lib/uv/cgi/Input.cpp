/**
 *
 */

#include <iostream>
#include <cstdlib>

#include "Input.h"

size_t uv::Input::read(char *data, size_t length)
{
    std::cin.read(data, length);
    return std::cin.gcount();
}

/**
 *  
 */
std::string uv::Input::getenv(const char *varName)
{
    char *var = std::getenv(varName);
    return (0 == var) ? std::string("") : var;
}

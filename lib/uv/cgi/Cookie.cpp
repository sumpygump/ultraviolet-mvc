/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file Cookie.cpp
 * Ultraviolet CGI Cookie class definition.
 *
 * A Cookie object represents a HTTP Cookie
 */

#include <iostream>
#include <string>
#include <utility>

#include "Cookie.h"

uv::Cookie::Cookie()
{
    this->name = "";
    this->value = "";
}

uv::Cookie::Cookie(const Cookie &cookie)
{
    this->name = cookie.name;
    this->value = cookie.value;
}

std::string uv::Cookie::getName()
{
    return this->name;
}

void uv::Cookie::setName(std::string inputName)
{
    this->name = std::move(inputName);
}

std::string uv::Cookie::getValue()
{
    return this->value;
}

void uv::Cookie::setValue(std::string inputValue)
{
    this->value = std::move(inputValue);
}

std::string uv::Cookie::toString() const
{
    return this->name + "=" + this->value + ";";
}

namespace uv
{
std::ostream &operator <<(std::ostream &out, Cookie &cookie)
{
    return out << cookie.toString() << std::endl;
}
} // namespace uv
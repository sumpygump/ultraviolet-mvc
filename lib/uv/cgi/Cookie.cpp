/**
 *
 */

#include <iostream>
#include <string>

#include "Cookie.h"
#include "Environment.h"

uv::Cookie::Cookie()
{
    this->name  = "";
    this->value = "";
}

uv::Cookie::Cookie(std::string httpCookie)
{
    this->name  = "";
    this->value = "";
}

uv::Cookie::Cookie(const Cookie& cookie)
{
    this->name  = "";
    this->value = "";
}

std::string uv::Cookie::getName()
{
    return this->name;
}

void uv::Cookie::setName(std::string name)
{
    this->name = name;
}

std::string uv::Cookie::getValue()
{
    return this->value;
}

void uv::Cookie::setValue(std::string value)
{
    this->value = value;
}

std::string uv::Cookie::toString()
{
    return this->name + ": " + this->value;
}

namespace uv
{

std::ostream& operator << (std::ostream& out, Cookie& cookie)
{
    return out << cookie.toString() << std::endl;
}

} // namespace uv

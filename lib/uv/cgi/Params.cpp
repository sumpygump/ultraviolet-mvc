/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file Params.cpp
 * Ultraviolet CGI Params class definition.
 *
 * Handles parsing HTTP requests.
 */

#include "Params.h"
#include "Url.h"
#include "core/Strlib.h"

/**
 * Parse the input and store the vars
 */
void uv::Params::parseInput(const std::string &value)
{
    if (value.empty()) {
        return;
    }

    const std::vector<std::string> pairs = Strlib::explode("&", value);
    std::vector<std::string> parts;

    const size_t pairslen = pairs.size();

    for (size_t i = 0; i < pairslen; i++) {
        parts = Strlib::explode("=", pairs[i]);
        if (parts.size() > 1 && !parts[1].empty()) {
            vars[parts[0]] = Url::decode(parts[1]);
        }
    }
}

/**
 *  
 */
bool uv::Params::keyExists(const std::string &key)
{
    if (vars.find(key) != vars.end()) {
        return true;
    }
    return false;
}

/**
 *  
 */
std::string uv::Params::getParam(const std::string &key)
{
    if (!keyExists(key)) {
        return "";
    }
    return vars[key];
}

/**
 *  
 */
std::string uv::Params::operator[](const std::string &name)
{
    return this->getParam(name);
}

/**
 *  
 */
std::string uv::Params::list()
{
    if (vars.empty()) {
        return "Empty.";
    }

    std::string out;

    std::map<std::string, std::string>::iterator curr, end;
    for (curr = vars.begin(), end = vars.end(); curr != end; ++curr) {
        out.append(" [" + curr->first + "] => " + curr->second + "\n");
    }

    return out;
}
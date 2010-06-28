/**
 *  
 */

#include <iostream>

#include "Request.h"
#include "Url.h"
#include "../core/Strlib.h"

/**
 * Parse the input and store the vars
 */
void uv::Request::parseInput(std::string value)
{
    if (value == "") {
        return;
    }

    std::vector<std::string> pairs = Strlib::explode("&", value);
    std::vector<std::string> parts;

    int pairslen = pairs.size();
    int i;

    for (i = 0; i < pairslen; i++) {
        parts = Strlib::explode("=", pairs[i]);
        if (parts.size() > 1 && parts[1] != "") {
            vars[parts[0]] = Url::decode(parts[1]);
        }
    }
}

/**
 *  
 */
bool uv::Request::keyExists(std::string key)
{
    if (vars.find(key) != vars.end()) {
        return true;
    }
    return false;
}

/**
 *  
 */
std::string uv::Request::getParam(std::string key)
{
    if (!keyExists(key)) {
        return "";
    }
    return vars[key];
}

/**
 *  
 */
std::string uv::Request::list()
{
    if (vars.empty()) {
        return "Empty.";
    }

    int i;
    std::string out;

    std::map<std::string, std::string>::iterator curr, end;
    for (curr = vars.begin(), end = vars.end(); curr != end; curr++) {
       out.append(" [" + curr->first + "] => " + curr->second + "\n");
    }

    return out;
}

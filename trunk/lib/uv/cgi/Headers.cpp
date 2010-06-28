/**
 *  
 */

#include <string>
#include <vector>
#include <iostream>

#include "Headers.h"

/**
 *  
 */
uv::Headers::Headers ()
{
    isAssembled = false;
}

/**
 *  
 */
void uv::Headers::set (std::string value)
{
    headerValues.push_back(value);
    isAssembled = false;
}

/**
 *  
 */
void uv::Headers::assemble ()
{
    std::vector<std::string>::const_iterator headerIterator;
    std::vector<std::string>::const_iterator headerBegin = headerValues.begin();
    std::vector<std::string>::const_iterator headerEnd = headerValues.end();

    for (headerIterator = headerBegin; headerIterator < headerEnd; headerIterator++) {
        headers.append(*headerIterator);

        // TODO: Refactor to use streams, and replace \n with endl to make more robust
        headers.append("\n");
    }

    isAssembled = true;
}

/**
 *  
 */
std::string uv::Headers::toString ()
{
    if (!isAssembled) {
        assemble();
    }

    return headers;
}

namespace uv
{

/**
 *  
 */
std::ostream& operator << (std::ostream& out, Headers& header)
{
    return out << header.toString() << std::endl;
}

} // namespace uv

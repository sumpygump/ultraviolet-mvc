/** @file Strlib.h
 * Header file for Strlib class
 */

#ifndef UV_CORE_STRLIB_H_
#define UV_CORE_STRLIB_H_

#include <vector>

/**
 * UltraViolet namespace 
 */
namespace uv
{

/**
 * Provides library functions for strings
 * 
 * @author Jansen Price <jansen.price@sierra-bravo.com>
 * @version $Id$
 */
class Strlib
{
  public:
    /**
     * Split a string by a delimiter
     *
     * @param delimiter A string as separtor
     * @param str The string to split
     * @return a vector of the items
     */
    static std::vector<std::string> explode(std::string delimiter, std::string str);

    /**
     * Trim leading and trailing whitespace from a string
     */
    static std::string trim(std::string& str);

    /**
     * Convert hex to char
     */
    static char hexToChar(char first, char second);

    /**
     * Convert a size_t to a string 
     */
    static std::string sizeToString(size_t sz);

}; // class Strlib

} // namespace uv

#endif // UV_CORE_STRLIB_H_

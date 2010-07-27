/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Ini.h
 * Ultraviolet Core Ini class header file
 *
 * @see Ini.cpp
 */

#ifndef UV_INI_H_
#define UV_INI_H_

#include <string>
#include <map>

/**
 * Ultraviolet namespace
 */
namespace uv
{

/**
 * Read and parse an ini file
 * 
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Ini
{
  protected:

    /**
     * Key-value pairs map
     */
    std::map<std::string, std::string> keyValuePairs;
    
    /**
     * Storage for filename of .ini file
     */
    std::string filename;
    
    /**
     * Read the file
     */
    void readFile();

    /**
     * Read a line
     *
     * @param line The line to read
     */
    int readLine(std::string line);

    /**
     * Set a pair
     *
     * @param key The key
     * @param value A value
     */
    void setPair(std::string key, std::string value);
    
  public:
    /**
     * Default constructor
     *
     * @param filename Name of file (path)
     */
    Ini(std::string filename);
    
    /**
     * Get pairs
     *
     * @param Retrieve all the pairs in this ini file
     */
    std::map<std::string, std::string> getPairs();

    /**
     * List the key value pairs
     */
    std::string list();

}; // class Ini

} // namespace uv

#endif // UV_INI_H_

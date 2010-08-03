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
 *  
 */
typedef std::map<std::string, std::string> iniPairs;

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
    std::map<std::string, uv::iniPairs> keyValuePairs;

    /**
     * Storage for the current section (during parsing)
     */
    std::string currentSection;
    
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
     * @param key Key name
     * @param value A value
     * @param section The name of the section
     */
    void setPair(std::string key, std::string value, std::string section);
    
  public:

    /**
     * Default constructor
     */
    Ini();

    /**
     * Constructor with filename
     *
     * @param filename Name of file (path)
     */
    Ini(std::string filename);
    
    /**
     * Get pairs
     *
     * @param Retrieve all the pairs in this ini file
     */
    std::map<std::string, iniPairs> getPairs();

    /**
     * Get a single value
     *
     * @param Key name
     * @param Section name
     */
    std::string get(std::string key, std::string section);

    /**
     * Get a section
     *
     * @param Section name
     */
    uv::iniPairs getSection(std::string section);

    /**
     * List the key value pairs
     */
    std::string list();

}; // class Ini

} // namespace uv

#endif // UV_INI_H_

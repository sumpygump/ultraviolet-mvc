/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
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
    void setPair(const std::string &key, const std::string &value, const std::string &section);

public:

    /**
     * Default constructor
     */
    Ini();

    /**
     * Constructor with filename
     *
     * @param filenameInput Name of file (path)
     */
    explicit Ini(const std::string &filenameInput);

    /**
     * Get pairs
     */
    std::map<std::string, iniPairs> getPairs();

    /**
     * Get a single value
     *
     * @param key name
     * @param section name
     */
    std::string get(const std::string &key, const std::string &section);

    /**
     * Get a section
     *
     * @param section name
     */
    uv::iniPairs getSection(const std::string &section);

    /**
     * List the key value pairs
     */
    std::string list();

}; // class Ini

} // namespace uv

#endif // UV_INI_H_
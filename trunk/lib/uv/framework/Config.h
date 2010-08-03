/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Config.h
 * Ultraviolet Config object
 *
 * @see Config.cpp
 */

#ifndef UV_CONFIG_H_
#define UV_CONFIG_H_

#include <string>
#include <map>

#include "core/Ini.h"

/**
 * Ultraviolet namespace
 */
namespace uv
{

/**
 * Store configuration variables
 * 
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Config
{
  protected:

    /**
     *  
     */
    Ini source;

  public:

    /**
     *  
     */
    Config(std::string filename);

    /**
     *  
     */
    ~Config();

    /**
     *  
     */
    std::string get(std::string key, std::string section);

    /**
     *  
     */
    std::string list();

}; // class Config

} // namespace uv

#endif // UV_CONFIG_H_

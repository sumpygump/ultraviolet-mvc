/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Random.h
 * Ultraviolet Core Random class header file.
 *
 * @see Random.cpp
 */

#ifndef UV_CORE_RANDOM_H_
#define UV_CORE_RANDOM_H_

/**
 * Ultraviolet namespace
 */
namespace uv
{

/**
 * Random provides functionality for generating random things
 * 
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Random
{
  public:

    /**
     * Default constructor
     */
//    Random();

    /**
     * Constructor with seed
     */
//    Random(int seed);

    /**
     * Set the randomize seed
     */
    static void setSeed(int seed);
    
    /**
     * Set the randomize seed
     */
    static void setSeed();

    /**
     * Generate a random string with specifed length
     */
    static std::string generateString(int length);

  protected:

    /**
     * Indicates whether the seed has been set
     */
    static bool isSeeded;

}; // class Random

} //namespace uv

#endif // UV_CORE_RANDOM_H_

/** @file Random.h
 * Header file for Random class (uv core)
 */

#ifndef UV_CORE_RANDOM_H_
#define UV_CORE_RANDOM_H_

/**
 * UltraViolet namespace
 */
namespace uv
{

/**
 * Random provides functionality for generating random things
 * 
 * @author Jansen Price <jansen.price@sierra-bravo.com>
 * @version $Id$
 */
class Random
{
  public:

    /**
     * Default constructor
     */
    Random();

    /**
     * Constructor with seed
     */
    Random(int seed);

    /**
     * Set the randomize seed
     */
    void setSeed(int seed);
    
    /**
     * Set the randomize seed
     */
    void setSeed();

    /**
     * Generate a random string with specifed length
     */
    static std::string generateString(int length);

  protected:

    /**
     * Indicates whether the seed has been set
     */
    bool isSeeded;

}; // class Random

} //namespace uv

#endif // UV_CORE_RANDOM_H_

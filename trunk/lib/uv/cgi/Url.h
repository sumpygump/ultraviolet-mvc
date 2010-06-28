/**
 * Url class
 *  
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
 
#ifndef UV_URL_H_
#define UV_URL_H_

#include <string>

/**
 * Namespace uv
 */
namespace uv
{

/**
 * Url class
 */
class Url
{
  public:
    /**
     * Encode a URL
     */
    static std::string encode(std::string input);

    /**
     * Decode a URL
     */
    static std::string decode(std::string input);

}; // class Url

} // namespace uv

#endif // UV_URL_H_

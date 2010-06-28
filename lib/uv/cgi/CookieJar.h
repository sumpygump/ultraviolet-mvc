/**
 * Cookie Jar class header file
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */

#ifndef UV_COOKIEJAR_H_
#define UV_COOKIEJAR_H_

#include <vector>

#include "Cookie.h"

/**
 * UltraViolet Namespace
 */
namespace uv
{

/**
 * Cookie Jar is a container class for HTTP Cookie objects
 *
 * See rfc 2109 for version 1 of HTTP Cookies
 * http://www.w3.org/Protocols/rfc2109/rfc2109.txt
 * 
 * @author Jansen Price <jansen.price@sierra-bravo.com>
 * @version $Id$
 */
class CookieJar
{
  public:

    /**
     * Default constructor
     */
    CookieJar();

    /**
     * Parse the cookie header and set cookies
     */
    void readCookies(std::string cookieString);

    /**
     * Add a cookie to the jar
     */
    int addCookie(Cookie * cookie);

    /**
     *  
     */
    std::string list();

  protected:

    /**
     * Storage for cookies
     */
    std::vector<Cookie*> cookies;

}; // class CookieJar

} // namespace uv

#endif // UV_COOKIEJAR_H_

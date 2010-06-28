/**
 * Cookie class header file
 *
 * @author Adam Ranfelt <adamRenny@gmail.com>
 * @version $Id$
 */

#ifndef UV_COOKIE_H_
#define UV_COOKIE_H_

/**
 * UltraViolet Namespace
 */
namespace uv
{

/**
 * Cookie class provides an interface into HTTP cookies
 *
 * See rfc 2109 for version 1 of HTTP Cookies
 * http://www.w3.org/Protocols/rfc2109/rfc2109.txt
 *
 * @author Adam Ranfelt <adamRenny@gmail.com> 
 * @version $Id$
 */
class Cookie
{
  public:

    /**
     * Default Cookie Constructor
     */
    Cookie();
    
    /**
     * Cookie Constructor from the HTTP Header String
     *
     * @param httpCookie Single Cookie String from the header
     */
    Cookie(std::string httpCookie);
    
    /**
     * Copy Constructor from the Cookie Object
     *
     * @param cookie Single Cookie String from the header
     */
    Cookie(const Cookie& cookie);
    
    /**
     * Cookie Name Get Method
     *
     * @return Name of the Cookie
     */
    std::string getName();
    
    /**
     * Cookie Name Set Method
     *
     * @param name New Cookie Name
     * @return void
     */
    void setName(std::string name);
    
    /**
     * Cookie Value Get Method
     *
     * @return Value of the Cookie
     */
    std::string getValue();
    
    /**
     * Cookie Value Get Method
     *
     * @param value New Cookie Value
     * @return void
     */
    void setValue(std::string value);
    
    /**
     * String Representation of the Cookie
     *
     * @return Cookie String
     */
    std::string toString();
    
    /**
     * Stream output
     *
     * @param out Output stream
     * @param cookie Cookie to be output
     * @return Value of the Cookie
     */
    friend std::ostream& operator<< (std::ostream& out, Cookie& cookie);
    
  protected:

    /**
     * Cookie Name
     */
    std::string name;
    
    /**
     * Cookie Value
     */
    std::string value;
};

} // Namespace uv

#endif // UV_COOKIE_H_

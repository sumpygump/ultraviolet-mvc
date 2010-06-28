/**
 * Headers class header file
 *
 * @author Adam Ranfelt <adamRenny@gmail.com>
 * @author Jansen Price <sumpygump@gmail.com>
 * @version $Id$
 */

#ifndef UV_HEADERS_H_
#define UV_HEADERS_H_

#include <vector>

/**
 * UltraViolet Namespace
 */
namespace uv
{

/**
 * Headers class provides a representation of output HTTP headers
 *
 * @author Adam Ranfelt <adamRenny@gmail.com> 
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Headers
{       
  public:
    /**
     * Default Header Constructor
     */
    Headers ();

    /**
     * Sets a header with a value
     *
     * @param value Value of the header to be set
     */
    void set (std::string value);

    /**
     * Returns a converted string form of the Headers object
     *
     * @return Headers in String form
     */
    std::string toString ();

    /**
     * Overloaded stream output function to output to streams
     *
     * @param out Output Stream
     * @param header Header to be output
     * @return Stream written to
     */
    friend std::ostream& operator<< (std::ostream& out, Headers& header);

  protected:
    /**
     * Whether the string has been assembled
     */
    bool isAssembled;

    /**
     * Dynamic list of headers
     */
    std::vector<std::string> headerValues;

    /**
     * Header output string
     */
    std::string headers;

    /**
     * Generates the output string
     */
    void assemble ();
};

} // namespace uv

#endif // UV_HEADERS_H_

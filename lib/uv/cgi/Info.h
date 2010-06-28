/**
 * Info class header file
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */

#ifndef UV_INFO_H_
#define UV_INFO_H_

#include "Environment.h"

/**
 * UltraViolet Namespace
 */
namespace uv
{

/**
 * Info is a class to aggregate vars for display
 *
 * @author Jansen Price <jansen.price@sierra-bravo.com>
 * @version $Id$
 */
class Info
{
  public:

    /**
     * Default constructor
     */
    Info();

    /**
     * Display environment vars
     */
    static std::string displayEnvironment(Environment env);

    /**
     * Format an attribute value pair in a table row
     */
    static std::string avPairRow(std::string attr, std::string value);

}; // class Info

} // namespace uv

#endif // UV_INFO_H_

/**
 *
 */

#ifndef UV_INPUT_H_
#define UV_INPUT_H_

#include <string>

/**
 * UltraViolet Namespace
 */
namespace uv
{

/**
 * Input wrapper
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class Input
{
  public:
    /**
     * Read from stdin
     */
    size_t read(char *data, size_t length);

    /**
     * Get an environment variable
     */
    virtual std::string getenv(const char *varName);

}; // class Input

} // namespace uv

#endif // UV_INPUT_H_

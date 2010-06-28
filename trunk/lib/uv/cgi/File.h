/**
 * File upload header class file
 *
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */

#ifndef UV_FILE_H_
#define UV_FILE_H_

#include <string>

/**
 * UltraViolet Namespace
 */
namespace uv
{

// forward declaration
class Random;

/**
 * The File class represents a file upload
 * 
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class File
{
  public:
    /**
     * The name of the file from the form post
     */
    std::string filename;

    /**
     * The temporary storage for the file
     */
    std::string tempFilename;

    /**
     * The raw filedata to be saved to file
     */
    std::string filedata;

    /**
     * The filesize in bytes
     */
    size_t filesize;

    /**
     * The MIME type of the file
     */
    std::string contentType;

    /**
     * Default constructor
     */
    File();

    /**
     * Constructor
     */
    File(std::string infilename, std::string infiledata, std::string inContentType);

    /**
     * Initialize object (called after construction)
     */
    void init();

    /**
     * Generate a temp file name
     */
    std::string generateTempFilename();

    /**
     * Save the temp file
     */
    void saveTempFile();

    /**
     * List file data
     */
    std::string list();

  protected:

    /**
     * The random object
     */
    static uv::Random randomizer;
    
}; // class File

} // namespace uv

#endif // UV_FILE_H_

/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file InternalChrome.h
 * Ultraviolet View InternalChrome class header file.
 *
 * @see InternalChrome.cpp
 */

#ifndef UV_INTERNALCHROME_H_
#define UV_INTERNALCHROME_H_

#include <string>
#include <sstream>

/**
 * Ultraviolet namespace
 */
namespace uv
{

/**
 * Internal chrome for default layout
 * 
 * @author Jansen Price <jansen.price@gmail.com>
 * @version $Id$
 */
class InternalChrome
{
  public:

    /**
     * Default constructor
     */
    InternalChrome();

    /**
     * Wrap content
     *
     * @param content The page contents
     * @return String with chrome (html)
     */
    std::string wrapInChrome(std::string content);

    /**
     * Set title
     *
     * @param title The page title
     * @return void
     */
    void setTitle(std::string title);

  protected:

    /**
     * Page title
     */
    std::string title;

    /**
     * Get styles for the html output
     *
     * @return String including html style tag
     */
    std::string getStyles();
}; // class InternalChrome

} // namespace uv

#endif // UV_INTERNALCHROME_H_

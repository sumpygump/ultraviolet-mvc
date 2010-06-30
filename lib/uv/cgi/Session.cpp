/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

/** @file Session.cpp
 * Ultraviolet CGI Session class definition.
 *
 * Provides access to browser sessions
 */

#include <string>
#include <sstream>
#include <ctime>

#include "cgi/Session.h"
#include "cgi/Environment.h"
#include "hashlibpp/hl_md5wrapper.h"

/**
 *  
 */
uv::Session::Session ()
{
}

/**
 *
 */
std::string uv::Session::createId()
{
    hashwrapper *h = new md5wrapper();
    Environment *env = new Environment();

    h->test(); // This ensures the library is working

    time_t seconds = time(NULL);
    std::stringstream ss;

    ss << env->get(Environment::kRemoteAddr)
        << env->get(Environment::kServerName)
        << seconds;
    
    std::string md5 = h->getHashFromString(ss.str());

    delete h;
    delete env;

    return md5;
}

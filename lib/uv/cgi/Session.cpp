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
#include <iostream>

#include "cgi/Session.h"
#include "cgi/Environment.h"
#include "cgi/SessionFileStorage.h"
#include "hashlibpp/hl_md5wrapper.h"

/**
 *  
 */
uv::Session::Session()
{
    this->sessionId = "";
}

/**
 *  
 */
uv::Session::~Session()
{
    delete this->storage;
}

/**
 *  
 */
uv::Session::Session(std::string sessionId)
{
    this->setId(sessionId);
    this->load();
}

/**
 *  
 */
void uv::Session::load()
{
    // load data from storage
    this->initStorage();

    std::string sessdata = this->storage->load(this->sessionId);

    this->parseInput(sessdata);
}

/**
 *  
 */
void uv::Session::setId(std::string sessionId)
{
    this->sessionId = sessionId;

    // validate sessionid?
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
    
    this->sessionId = h->getHashFromString(ss.str());

    delete h;
    delete env;

    return this->sessionId;
}

/**
 *  
 */
std::string uv::Session::getId()
{
    return this->sessionId;
}

/**
 *  
 */
void uv::Session::setParam(std::string name, std::string value)
{
    this->vars[name] = value;
}

/**
 *  
 */
void uv::Session::save()
{
    this->initStorage();
    this->storage->save(this->sessionId, std::string("flower=Germanium"));
}

/**
 *  
 */
void uv::Session::initStorage()
{
    this->storage = new SessionFileStorage();
}

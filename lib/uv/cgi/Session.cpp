/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Lost Mind Software
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/** @file Session.cpp
 * Ultraviolet CGI Session class definition.
 *
 * Provides access to browser sessions
 */

#include <string>
#include <sstream>
#include <ctime>
#include <utility>

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
    this->storage = nullptr;
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
uv::Session::Session(const std::string &setSessionId)
{
    this->storage = nullptr;
    this->setId(setSessionId);
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
void uv::Session::setId(const std::string &setSessionId)
{
    this->sessionId = setSessionId;
    // TODO validate sessionId
}

/**
 *
 */
std::string uv::Session::createId()
{
    hashwrapper *h = new md5wrapper();
    auto *env = new Environment();

    h->test(); // This ensures the library is working

    const time_t seconds = time(nullptr);
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
void uv::Session::setParam(const std::string &name, std::string value)
{
    this->vars[name] = std::move(value);
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
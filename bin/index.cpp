/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Maru Mari Katana Sashimi
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

/**
 * @mainpage Ultraviolet C++ MVC Framework
 *
 * @section intro Introduction
 * Greetings fellow hyper-traveler! This is a web framework in C++.
 * Right now it is in its infancy. Currently the CGI system and other core
 * features are in development.
 */

#include <iostream>
#include <string>
#include <sstream>

#include "cgi/Environment.h"
#include "cgi/Info.h"
#include "cgi/Cookie.h"
#include "cgi/File.h"
#include "cgi/Session.h"
#include "cgi/Request.h"
#include "cgi/Response.h"
#include "view/InternalChrome.h"
#include "core/Ini.h"
#include "framework/Config.h"

/**
 * This is example code for illustrating and testing features of the application
 */
int main()
{
    uv::Request request;
    uv::Response response;

    if (!request.env["TERM"].empty()) {
        std::cout << "Cannot run Ultraviolet from a terminal." << std::endl
                  << "Exiting." << std::endl;
        return 1;
    }

    // Prepare headers
    response.headers.set("Content-type: text/html");
    response.headers.set("X-Powered-By: Ultraviolet/0.8");

    // Set up session
    uv::Session* session = nullptr;
    if (request.env["UV_AUTO_SESSION"] == "on") {
        uv::Cookie* sessionCookie = request.cookies.retrieve("UVSESSID");
        if (sessionCookie == nullptr) {
            session = new uv::Session();
            std::string sessionId = session->createId();
            response.headers.set("Set-Cookie: UVSESSID=" + sessionId);
            session->save();
        } else {
            session = new uv::Session(sessionCookie->getValue());
            session->setId(sessionCookie->getValue());
            session->load();
        }
    }

    std::string br = "<br />";
    std::ostringstream oss(std::ostringstream::out);
    uv::InternalChrome ic;

    oss << "<h1>Ultraviolet is Working</h1>" << std::endl;

    // Begin output (send headers)
    std::cout << response.headers << std::endl;
    std::cout << ic.wrapContent(oss.str());

    delete session;

    return 0;
}
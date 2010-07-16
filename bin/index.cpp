/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Maru Mari Katana Sashimi
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
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
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "cgi/Environment.h"
#include "cgi/Headers.h"
#include "cgi/Info.h"
#include "cgi/Cookie.h"
#include "cgi/Session.h"
#include "cgi/Request.h"
#include "view/InternalChrome.h"

/**
 * This is example code for illustrating and testing features of the application 
 */
int main()
{
    // Environment is required to access constants
    typedef uv::Environment Environment;

    uv::Request request;

    // Prepare headers
    uv::Headers headers;
    headers.set("Content-type: text/html");
    headers.set("X-Powered-By: Ultraviolet/0.8");
    headers.set("Set-Cookie: testcookie1=\"true\"; max-age=1024; comment=cookies have comments");
    headers.set("Set-Cookie: id=2454; max-age=1024; version=1");
    headers.set("Set-Cookie: userid=154844746557324485445; max-age=1024; version=1");
    headers.set("Set-Cookie: deleteme=; max-age=0"); // to delete a cookie, set max-age=0

    //std::cout << headers << "uv::cgi started.<br />";

    // Set up session
    uv::Session* session = new uv::Session();
    if (request.env["UV_AUTO_SESSION"] == "on") {
        uv::Cookie* sessionCookie = request.cookies.retrieve("UVSESSID");
        if (sessionCookie->getName() == "") {
            //uv::Session * session = new uv::Session();
            std::string sessionId = session->createId();
            headers.set("Set-Cookie: UVSESSID=" + sessionId);
            session->setParam("gravy", "thick");
            session->save();
        } else {
            //uv::Session * session = new uv::Session(sessionCookie->getValue());
            session->setId(sessionCookie->getValue());
            session->load();
        }
    }

    std::string br = "<br />";
    std::ostringstream oss (std::ostringstream::out);
    uv::InternalChrome ic;

    if (request.get.keyExists("test")) {
        if (request.get["test"] == "post") {
            ic.setTitle("test POST | Ultraviolet MVC");
            oss << "<h1>Ultraviolet : Test POST</h1>" << std::endl
                << "<p>Submit the form to test the POST request.</p>" << std::endl
                << "<form action=\"\" method=\"post\">"
                << "<label>field1 <input type=\"text\" name=\"field1\" value=\"test value\" /></label>" << br
                << "<label>field2 <input type=\"text\" name=\"field2\" value=\"test value 2\" /></label>" << br
                << "<label>check1 <input type=\"checkbox\" name=\"check1\" value=\"1\" /></label>" << br
                << "<input type=\"submit\" name=\"submit\" value=\"Submit\" />"
                << "</form>" << std::endl
                << "<p>Submit the form to test the multipart/form-data request.</p>" << std::endl
                << "<form action=\"\" method=\"post\" enctype=\"multipart/form-data\">"
                << "<label>field1 <input type=\"text\" name=\"field1\" value=\"test value\" /></label>" << br
                << "<label>field2 <input type=\"text\" name=\"field2\" value=\"test value 2\" /></label>" << br
                << "<label>testfile <input type=\"file\" name=\"testfile\" /></label>" << br
                << "<label>testfile2 <input type=\"file\" name=\"testfile2\" /></label>" << br
                << "<input type=\"submit\" name=\"submit\" value=\"Submit\" />"
                << "</form>" << std::endl
                << "<p>Use the querystring <a href=\"?test=post&amp;display-stdin=true\">?display-stdin=true</a> to display stdin data (for troubleshooting)</a></p>";
        } else if (request.get["test"] == "404") {
            headers.set("Status: 404"); // example of 404 status
            ic.setTitle("Error 404");
            oss << "<h1 class=\"error\">404 Not Found</h1>"
                << "<p class=\"error-message\">The file could not be found.</p>";
        }
    } else {
        oss << "<h1>Ultraviolet is Working</h1>" << std::endl
            << "<p><a href=\"?test=post\">Test POST</a></p>" << std::endl;
    }

    oss << "<h2>Environment</h2>\n"
        << uv::Info::displayEnvironment(request.env)
        << "<h2>Other Data:</h2>\n"
        << "<strong>GET vars</strong><pre>" << request.get.list() << "</pre>"
        << "<strong>POST vars</strong><pre>" << request.post.list() << "</pre>"
        << "<strong>Cookies</strong><pre>" << request.cookies.list() << "</pre>"
        << "<strong>Session</strong><pre>" << session->list() << "</pre>"
        << "<strong>FILES vars</strong><pre>";

    std::string filedump = "";
    std::map<std::string, uv::File>::iterator curr, end;
    for (curr = request.post.files.begin(), end = request.post.files.end(); curr != end; curr++) {
        filedump.append(" [" + curr->first + "] => \n" + curr->second.list() + "\n");
    }

    oss << filedump << "</pre>";

    if (request.get.getParam("display-stdin") == "true") {
        oss << "<pre>stdin:\n" << request.rawInput << "</pre>" << std::endl;
    }

    // Begin output (send headers)
    std::cout << headers << std::endl;
    std::cout << ic.wrapContent(oss.str());

    delete session;

    return 0;
}

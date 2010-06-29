/*~
 * Ultraviolet MVC
 * Copyright (C) 2010 Maru Mari Katana Sashimi
 *
 * Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 *
 * @version $Id$
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "Input.h"
#include "Environment.h"
#include "Headers.h"
#include "Request.h"
#include "Post.h"
#include "File.h"
#include "Info.h"
#include "Cookie.h"
#include "CookieJar.h"
#include "Random.h"
#include "InternalChrome.h"

/**
 *  
 */
int main()
{
    typedef uv::Environment Environment;
    
    Environment env;
    uv::Headers headers;

    srand(time(NULL));

    headers.set("Status: 404");
    headers.set("Content-type: text/html");
    headers.set("X-Powered-By: Ultraviolet/0.8");
    headers.set("Set-Cookie: testcookie1=\"true\"; max-age=1024; comment=cookies have comments");
    headers.set("Set-Cookie: id=2454; max-age=1024; version=1");
    headers.set("Set-Cookie: userid=154844746557324485445; max-age=1024; version=1");
    headers.set("Set-Cookie: deleteme=; max-age=0"); // to delete a cookie, set max-age=0

    //std::cout << headers << "uv::cgi started.<br />";

    uv::Request get;
    get.parseInput(env["QUERY_STRING"]);

    uv::CookieJar cookieJar;
    cookieJar.readCookies(env[Environment::kHttpCookie]);

    // Setup post
    uv::Post post;
    uv::Input input;
    std::string inputData;
    std::vector<char> data(env.getContentLength());

    input.read(&data[0], env.getContentLength());
    inputData = std::string(&data[0], env.getContentLength());
    post.parseInput(inputData, env.get("CONTENT_TYPE"));

    std::string br = "<br />";
    std::ostringstream oss (std::ostringstream::out);
    uv::InternalChrome ic;

    // Begin output (send headers)
    std::cout << headers << std::endl;

    if (get.keyExists("test") && get["test"] == "post") {
        ic.setTitle("test POST | Ultraviolet MVC");
        oss << "<h1>UltraViolet : Test POST</h1>" << std::endl
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
    } else {
        oss << "<h1>UltraViolet is Working</h1>" << std::endl
            << "<p><a href=\"?test=post\">Test POST</a></p>" << std::endl;
    }

    oss << "<h2>Environment</h2>\n"
        << uv::Info::displayEnvironment(env)
        << "<h2>Other Data:</h2>\n"
        << "<strong>GET vars</strong><pre>" << get.list() << "</pre>"
        << "<strong>POST vars</strong><pre>" << post.list() << "</pre>"
        << "<strong>Cookies</strong><pre>" << cookieJar.list() << "</pre>"
        << "<strong>FILES vars</strong><pre>";

    std::string filedump = "";
    std::map<std::string, uv::File>::iterator curr, end;
    for (curr = post.files.begin(), end = post.files.end(); curr != end; curr++) {
        filedump.append(" [" + curr->first + "] => \n" + curr->second.list() + "\n");
    }

    oss << filedump << "</pre>";

    if (get.getParam("display-stdin") == "true") {
        oss << "<pre>stdin:\n" << inputData << "</pre>" << std::endl;
    }

    std::cout << ic.wrapInChrome(oss.str());

    return 0;
}

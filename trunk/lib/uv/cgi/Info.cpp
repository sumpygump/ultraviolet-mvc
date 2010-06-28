/**
 *  
 */

#include <iostream>
#include <string>

#include "Info.h"

/**
 *  
 */
std::string uv::Info::displayEnvironment(Environment env)
{
    std::string output;

    output = "<table class=\"uv-av-list\" cellpadding=\"0\" cellspacing=\"0\" border=\"0\">\n";

    output.append(avPairRow("Http Host", env[Environment::kHttpHost]));
    output.append(avPairRow("Http Accept", env["HTTP_ACCEPT"]));
    output.append(avPairRow("Http Cache-Control", env["HTTP_CACHE_CONTROL"]));
    output.append(avPairRow("Http UserAgent", env[Environment::kHttpUserAgent]));
    output.append(avPairRow("Http Cookie", env[Environment::kHttpCookie]));
    output.append(avPairRow("Path", env[Environment::kPath]));
    output.append(avPairRow("Server name", env[Environment::kServerName]));
    output.append(avPairRow("Script name", env[Environment::kScriptName]));
    output.append(avPairRow("Request method", env[Environment::kRequestMethod]));
    output.append(avPairRow("Query string", env[Environment::kQueryString]));
    output.append(avPairRow("Content length", env[Environment::kContentLength]));
    output.append(avPairRow("Content type", env[Environment::kContentType]));

    output.append("</table>\n");

    return output;
}

/**
 *  
 */
std::string uv::Info::avPairRow(std::string attr, std::string value)
{
    std::string output = "<tr><td class=\"uv-attr\">";
    output.append(attr);
    output.append("</td><td class=\"uv-value\">");
    output.append(value);
    output.append("</td></tr>\n");

    return output;
}

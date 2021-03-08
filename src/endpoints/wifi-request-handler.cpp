#include "endpoints/wifi-request-handler.h"

using namespace dbuddy;

bool WifiRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool WifiRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/wifi.html")) {
        config->streamFile("/wifi.html", mimeHTML);
    } else if (requestUri.equals("/css/wifi.css")) {
        config->streamFile("/css/wifi.css", mimeCSS);
    } else if (requestUri.equals("/scripts/wifi.js")) {
        config->streamFile("/scripts/wifi.js", mimeJS);
    } else {
        return false;
    }

    return true;
}

#include "wifi-request-handler.h"

using namespace dbuddy;

bool WifiRequestHandler::canHandle(HTTPMethod method, String uri) {
    if (method == HTTP_GET
        && (uri.equals("/wifi.html")
            || uri.equals("/css/wifi.css")
            || uri.equals("/scripts/wifi.js"))) {
        return true;
    }

    return false;
}

bool WifiRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/wifi.html")) {
        manager->streamFile("/wifi.html", mimeHTML);
    } else if (requestUri.equals("/css/wifi.css")) {
        manager->streamFile("/css/wifi.css", mimeCSS);
    } else if (requestUri.equals("/scripts/wifi.js")) {
        manager->streamFile("/scripts/wifi.js", mimeJS);
    } else {
        return false;
    }

    return true;
}

#include "endpoints/index-request-handler.h"

using namespace dbuddy;

bool IndexRequestHandler::canHandle(HTTPMethod method, String uri) {
    if (method == HTTP_GET
        && (uri.equals("/")
            || uri.equals("/index.html")
            || uri.equals("/css/index.css")
            || uri.equals("/scripts/index.js"))) {
        return true;
    }

    return false;
}

bool IndexRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/") || requestUri.equals("/index.html")) {
        manager->streamFile("/index.html", mimeHTML);
    } else if (requestUri.equals("/css/index.css")) {
        manager->streamFile("/css/index.css", mimeCSS);
    } else if (requestUri.equals("/scripts/index.js")) {
        manager->streamFile("/scripts/index.js", mimeJS);
    }

    return true;
}

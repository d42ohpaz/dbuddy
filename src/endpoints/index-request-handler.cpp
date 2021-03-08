#include "endpoints/index-request-handler.h"

using namespace dbuddy;

bool IndexRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool IndexRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/") || requestUri.equals("/index.html")) {
        config->streamFile("/index.html", mimeHTML);
    } else if (requestUri.equals("/css/index.css")) {
        config->streamFile("/css/index.css", mimeCSS);
    } else if (requestUri.equals("/scripts/index.js")) {
        config->streamFile("/scripts/index.js", mimeJS);
    }

    return true;
}

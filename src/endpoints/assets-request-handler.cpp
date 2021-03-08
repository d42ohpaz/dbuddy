#include "endpoints/assets-request-handler.h"

using namespace dbuddy;

bool AssetsRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool AssetsRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/scripts/global.js")) {
        config->streamFile("/scripts/global.js", mimeJS);
    } else if (requestUri.equals("/scripts/vendor.js")) {
        config->streamFile("/scripts/vendor.js", mimeJS);
    } else if (requestUri.equals("/fonts/icons.woff")) {
        config->streamFile("/fonts/icons.woff", "font/woff");
    }

    return true;
}

#include "assets-request-handler.h"

using namespace dbuddy;

bool AssetsRequestHandler::canHandle(HTTPMethod method, String uri) {
    if (method == HTTP_GET
        && (uri.equals("/scripts/global.js")
            || uri.equals("/scripts/vendor.js")
            || uri.equals("/fonts/icons.woff"))) {
        return true;
    }

    return false;
}

bool AssetsRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/scripts/global.js")) {
        manager->streamFile("/scripts/global.js", mimeJS);
    } else if (requestUri.equals("/scripts/vendor.js")) {
        manager->streamFile("/scripts/vendor.js", mimeJS);
    } else if (requestUri.equals("/fonts/icons.woff")) {
        manager->streamFile("/fonts/icons.woff", "font/woff");
    }

    return true;
}

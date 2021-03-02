#include "endpoints/time-sync-request-handler.h"

using namespace dbuddy;

bool TimeSyncRequestHandler::canHandle(HTTPMethod method, String uri) {
    if (method == HTTP_GET
        && (uri.equals("/timesync.html")
            || uri.equals("/css/timesync.css")
            || uri.equals("/scripts/timesync.js"))) {
        return true;
    }

    return false;
}

bool TimeSyncRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/timesync.html")) {
        config->streamFile("/timesync.html", mimeHTML);
    } else if (requestUri.equals("/css/timesync.css")) {
        config->streamFile("/css/timesync.css", mimeCSS);
    } else if (requestUri.equals("/scripts/timesync.js")) {
        config->streamFile("/scripts/timesync.js", mimeJS);
    } else {
        return false;
    }

    return true;
}

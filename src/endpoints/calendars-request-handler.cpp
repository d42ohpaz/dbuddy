#include "calendars-request-handler.h"

using namespace dbuddy;

bool CalendarsRequestHandler::canHandle(HTTPMethod method, String uri) {
    if (method == HTTP_GET
        && (uri.equals("/calendars.html")
            || uri.equals("/css/calendars.css")
            || uri.equals("/scripts/calendars.js"))) {
        return true;
    }

    return false;
}

bool CalendarsRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/calendars.html")) {
        manager->streamFile("/calendars.html", mimeHTML);
    } else if (requestUri.equals("/css/calendars.css")) {
        manager->streamFile("/css/calendars.css", mimeCSS);
    } else if (requestUri.equals("/scripts/calendars.js")) {
        manager->streamFile("/scripts/calendars.js", mimeCSS);
    }

    return true;
}

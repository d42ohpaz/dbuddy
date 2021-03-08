#include "endpoints/abstract-request-handler.h"

using namespace dbuddy;

bool AbstractRequestHandler::canHandle(HTTPMethod method, String uri) {
    SPIFFS.begin();
    return SPIFFS.exists(uri);
}

bool AbstractRequestHandler::handle(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (!canHandle(requestMethod, requestUri)) {
        return false;
    }

    server.enableCORS(true);
    if (requestMethod == HTTP_GET) {
    }

    return setup(server, requestMethod, requestUri);
}

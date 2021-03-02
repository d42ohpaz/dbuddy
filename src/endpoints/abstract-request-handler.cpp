#include "endpoints/abstract-request-handler.h"

using namespace dbuddy;

bool AbstractRequestHandler::handle(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (!canHandle(requestMethod, requestUri)) {
        return false;
    }

    server.enableCORS(true);
    if (requestMethod == HTTP_GET) {
        server.sendHeader("Content-Encoding", "gzip");
    }

    return setup(server, requestMethod, requestUri);
}

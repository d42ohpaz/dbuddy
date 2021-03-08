#include "endpoints/time-sync-request-handler.h"

using namespace dbuddy;

bool TimeSyncRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool TimeSyncRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    return true;
}

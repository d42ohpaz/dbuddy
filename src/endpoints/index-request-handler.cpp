#include "endpoints/index-request-handler.h"

using namespace dbuddy;

bool IndexRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool IndexRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    return true;
}

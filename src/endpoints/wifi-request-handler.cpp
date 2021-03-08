#include "endpoints/wifi-request-handler.h"

using namespace dbuddy;

bool WifiRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool WifiRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    return true;
}

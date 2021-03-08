#include "endpoints/assets-request-handler.h"

using namespace dbuddy;

bool AssetsRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool AssetsRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    return true;
}

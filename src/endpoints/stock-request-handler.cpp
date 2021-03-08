#include "endpoints/stock-request-handler.h"

using namespace dbuddy;

bool StockRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool StockRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    return true;
}

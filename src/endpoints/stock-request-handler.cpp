#include "stock-request-handler.h"

using namespace dbuddy;

bool StockRequestHandler::canHandle(HTTPMethod method, String uri) {
    if (method == HTTP_GET
        && (uri.equals("/stock.html")
            || uri.equals("/css/stock.css")
            || uri.equals("/scripts/stock.js"))) {
        return true;
    }

    return false;
}

bool StockRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/stock.html")) {
        manager->streamFile("/stock.html", mimeHTML);
    } else if (requestUri.equals("/css/stock.css")) {
        manager->streamFile("/css/stock.css", mimeCSS);
    } else if (requestUri.equals("/scripts/stock.js")) {
        manager->streamFile("/scripts/stock.js", mimeJS);
    } else {
        return false;
    }

    return true;
}

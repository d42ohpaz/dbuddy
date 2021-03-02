#pragma once

#include <WebServer.h>
#include "abstract-request-handler.h"

namespace dbuddy {
    class StockRequestHandler : public AbstractRequestHandler {
    public:
        explicit StockRequestHandler(Config * config) : AbstractRequestHandler(config) {};

        bool canHandle(HTTPMethod method, String uri) final;
        bool setup(WebServer &server, HTTPMethod requestMethod, String requestUri) final;
    };
}

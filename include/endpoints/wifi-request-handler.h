#pragma once

#include <WebServer.h>
#include "abstract-request-handler.h"

namespace dbuddy {
    class WifiRequestHandler : public AbstractRequestHandler {
    public:
        explicit WifiRequestHandler(Config * config) : AbstractRequestHandler(config) {};

        bool canHandle(HTTPMethod method, String uri) final;
        bool setup(WebServer &server, HTTPMethod requestMethod, String requestUri) final;
    };
}

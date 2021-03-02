#pragma once

#include <WebServer.h>
#include "abstract-request-handler.h"

namespace dbuddy {
    class AssetsRequestHandler : public AbstractRequestHandler {
    public:
        explicit AssetsRequestHandler(Config * config) : AbstractRequestHandler(config) {};

        bool canHandle(HTTPMethod method, String uri) final;
        bool setup(WebServer &server, HTTPMethod requestMethod, String requestUri) final;
    };
}

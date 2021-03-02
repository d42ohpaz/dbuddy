#pragma once

#include <WebServer.h>
#include "config.h"

namespace dbuddy {
    class AbstractRequestHandler : public RequestHandler {
    public:
        explicit AbstractRequestHandler(Config * config) : config(config) {};

        bool handle(WebServer &server, HTTPMethod requestMethod, String requestUri) final;
    protected:
        Config * config;

        virtual bool setup(WebServer &server, HTTPMethod requestMethod, String requestUri) = 0;
    };
}

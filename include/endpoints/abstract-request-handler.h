#pragma once

#include <WebServer.h>
#include <ConfigManager.h>

namespace dbuddy {
    class AbstractRequestHandler : public RequestHandler {
    public:
        explicit AbstractRequestHandler(ConfigManager * manager) : manager(manager) {};

        bool handle(WebServer &server, HTTPMethod requestMethod, String requestUri) final;
    protected:
        ConfigManager * manager;

        virtual bool setup(WebServer &server, HTTPMethod requestMethod, String requestUri) = 0;
    };
}

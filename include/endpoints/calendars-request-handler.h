#pragma once

#include <WebServer.h>
#include "abstract-request-handler.h"

namespace dbuddy {
    class CalendarsRequestHandler : public AbstractRequestHandler {
    public:
        explicit CalendarsRequestHandler(Config * config) : AbstractRequestHandler(config) {};

        bool canHandle(HTTPMethod, String) final;
        bool setup(WebServer &, HTTPMethod, String) final;
    private:
        char * getCalendarsJson() const;
    };
}

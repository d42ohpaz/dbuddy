#include "endpoints/calendars-request-handler.h"

using namespace dbuddy;

bool CalendarsRequestHandler::canHandle(HTTPMethod method, String uri) {
    if (method == HTTP_GET && (uri.equals("/calendars") || AbstractRequestHandler::canHandle(method, uri))) {
        return true;
    }

    if (method == HTTP_POST
        && (uri.equals("/calendars.html"))) {
        return true;
    }

    return false;
}

bool CalendarsRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestMethod == HTTP_GET) {
        if (requestUri.equals("/calendars.html")) {
            config->streamFile("/calendars.html", mimeHTML);
        } else if (requestUri.equals("/css/calendars.css")) {
            config->streamFile("/css/calendars.css", mimeCSS);
        } else if (requestUri.equals("/scripts/calendars.js")) {
            config->streamFile("/scripts/calendars.js", mimeCSS);
        }
    }

    if (requestMethod == HTTP_POST) {
        if (requestUri.equals("/calendars.html")) {
            try {
                config->clear_calendars();

                for (int i = 0; i < server.args(); i += 3) {
                    config_cal_t calendar{};

                    for (int j = 0; j < 3; j++) {
                        String arg = server.argName(j);
                        const char * val = server.arg(j).c_str();

                        if (arg.startsWith("color")) {
                            strncpy(calendar.color, val, sizeof(calendar.color));
                        } else if (arg.startsWith("name")) {
                            strncpy(calendar.name, val, sizeof(calendar.name));
                        } else if (arg.startsWith("url")) {
                            strncpy(calendar.url, val, sizeof(calendar.url));
                        } else {
                            char * error_message = new char();
                            sprintf(error_message, R"(["error": "Bad parameter \"%s\" given."])", arg.c_str());

                            server.send(400, "application/json", error_message);
                            goto return_end;
                        }
                    }

                    config->add_calendar(&calendar);
                }

                config->save();

                // Give back the configuration values to prove success.
                String response = "[";
                for (int i = 0; i < CALENDARS; i++) {
                    config_cal_t * calendar = config->get_calendar(i);
                    char * r = new char();
                    sprintf(r, R"({"color": "%s", "name": "%s", "url": "%s"},)",
                            calendar->color,
                            calendar->name,
                            calendar->url
                    );
                    response += r;
                }

                response = response.substring(0, response.length() - 1);
                response += "]";
                server.send(200, "application/json", response);
            } catch (std::out_of_range & e) {
                char response[14 + strlen(e.what())];
                sprintf(response, R"(["error": "%s"])", e.what());
                server.send(500, "application/json", response);
            }
        }
    }

    return_end:
    return true;
}

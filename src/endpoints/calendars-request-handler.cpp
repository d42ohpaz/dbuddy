#include "endpoints/calendars-request-handler.h"

#include <ArduinoJson.h>

using namespace dbuddy;

bool CalendarsRequestHandler::canHandle(HTTPMethod method, String uri) {
    if (method == HTTP_GET && (uri.equals("/calendars") || AbstractRequestHandler::canHandle(method, uri))) {
        return true;
    }

    if (method == HTTP_POST && (uri.equals("/calendars"))) {
        return true;
    }

    return false;
}

bool CalendarsRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestMethod == HTTP_GET) {
        if (requestUri.equals("/calendars")) {
            char * output = getCalendarsJson();
            server.send(200, mimeJSON, output);
            free(output);
        }
    }

    if (requestMethod == HTTP_POST) {
        if (requestUri.equals("/calendars")) {
            try {
                processCalendarPost(server);

                // Give back the configuration values to prove success.
                char * output = getCalendarsJson();
                server.send(200, mimeJSON, output);
                free(output);
            } catch (const std::exception &e) {
                Serial.println(e.what());
                char * error = getResponseJson(e.what(), 500);
                server.send(500, mimeJSON, error);
            }
        }
    }

    return true;
}

char * CalendarsRequestHandler::getCalendarsJson() const {
    const uint8_t eln = config->length_calendars() + 1;
    const size_t capacity = JSON_ARRAY_SIZE(eln) + (eln * JSON_OBJECT_SIZE(CONFIG_CALENDARS_PROPERTY_LENGTH)) + 2;

    DynamicJsonDocument doc(capacity);
    JsonArray array;

    for (uint8_t i = 0; i < config->length_calendars(); i++) {
        const config_cal_t calendar = config->get_calendar(i);
        JsonObject row = doc.createNestedObject();

        row["color"] = calendar.color;
        row["name"] = calendar.name;
        row["url"] = calendar.url;
    }

    array = (doc.size() <= 0) ? doc.to<JsonArray>() : doc.as<JsonArray>();

    const size_t size = measureJson(array) + 1;
    char * output = (char *)malloc(sizeof(char) * size);

    serializeJson(array, output, size);
    return output;
}

char * CalendarsRequestHandler::getResponseJson(const char * message, const int code) {
    const size_t capacity = JSON_OBJECT_SIZE(2) + 2;

    StaticJsonDocument<capacity> doc;

    doc["message"] = message;
    doc["code"] = code;

    const size_t size = measureJson(doc) + 1;
    char * output = (char *)malloc(sizeof(char) * size);

    serializeJson(doc, output, size);
    return output;
}

void CalendarsRequestHandler::processCalendarPost(WebServer &server) {
    config->clear_calendars();

    JsonObject json = toJson(server);

    for (int i = 0; i < json["color"].size(); i++) {
        config_cal_t calendar = {};

        strncpy(calendar.color, json["color"][i], sizeof(calendar.color));
        strncpy(calendar.name, json["name"][i], sizeof(calendar.name));
        strncpy(calendar.url, json["url"][i], sizeof(calendar.url));

        config->add_calendar(calendar);
    }

    config->save();
}

JsonObject CalendarsRequestHandler::toJson(WebServer &server) {
    const unsigned int capacity = JSON_ARRAY_SIZE(CONFIG_CALENDARS_PROPERTY_LENGTH * CALENDARS) + JSON_OBJECT_SIZE(CONFIG_CALENDARS_PROPERTY_LENGTH) + 2;
    DynamicJsonDocument doc(capacity);
    auto obj = doc.to<JsonObject>();

    for (size_t i = 0; i < server.args(); i++) {
        const String name = server.argName(i);
        const String argn = server.argName(i).substring(0, name.indexOf("["));
        const size_t argc = name.substring(name.indexOf("[") + 1, name.indexOf("]")).toInt();
        const String argv = server.arg(i);

        if (name.indexOf("[") == -1) {
            obj[argn] = argv;
        } else {
            obj[argn][argc] = argv;
        }
    }

    return obj;
}

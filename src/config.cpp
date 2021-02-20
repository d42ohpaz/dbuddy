#include <stdexcept>

#include "config.h"
#include "endpoints/assets-request-handler.h"
#include "endpoints/calendars-request-handler.h"
#include "endpoints/index-request-handler.h"
#include "endpoints/stock-request-handler.h"
#include "endpoints/time-sync-request-handler.h"
#include "endpoints/wifi-request-handler.h"

using namespace dbuddy;

Config::Config(const char * ap_name, uint16_t port) {
    DEBUG_MODE = true;

    auto webserver_callback_handler = [this](WebServer * server) {
        server->addHandler(new AssetsRequestHandler(this->manager));
        server->addHandler(new CalendarsRequestHandler(this->manager));
        server->addHandler(new IndexRequestHandler(this->manager));
        server->addHandler(new StockRequestHandler(this->manager));
        server->addHandler(new TimeSyncRequestHandler(this->manager));
        server->addHandler(new WifiRequestHandler(this->manager));
    };

    manager = new ConfigManager();

    if (manager->getMode() == ap) {
        manager->setAPName(ap_name);
        manager->setAPFilename("/index.html");
        manager->setAPCallback(webserver_callback_handler);
    } else {
        manager->setAPICallback(webserver_callback_handler);
    }

    manager->setWebPort(port);

    manager->addParameter("timeserver", config->timeserver, sizeof(config->timeserver));
    manager->addParameter("update_interval", &config->timeinterval);
    manager->addParameter("timezone", config->timezone, sizeof(config->timezone));

    manager->addParameter("calendar_1_color", config->calendar1_color, sizeof(config->calendar1_color));
    manager->addParameter("calendar_1_name", config->calendar1_name, sizeof(config->calendar1_name));
    manager->addParameter("calendar_1_url", config->calendar1_url, sizeof(config->calendar1_url));

    manager->addParameter("calendar_2_color", config->calendar2_color, sizeof(config->calendar2_color));
    manager->addParameter("calendar_2_name", config->calendar2_name, sizeof(config->calendar2_name));
    manager->addParameter("calendar_2_url", config->calendar2_url, sizeof(config->calendar2_url));

    manager->addParameter("calendar_3_color", config->calendar3_color, sizeof(config->calendar3_color));
    manager->addParameter("calendar_3_name", config->calendar3_name, sizeof(config->calendar3_name));
    manager->addParameter("calendar_3_url", config->calendar3_url, sizeof(config->calendar3_url));

    manager->addParameter("calendar_4_color", config->calendar4_color, sizeof(config->calendar4_color));
    manager->addParameter("calendar_4_name", config->calendar4_name, sizeof(config->calendar4_name));
    manager->addParameter("calendar_4_url", config->calendar4_url, sizeof(config->calendar4_url));

    manager->addParameter("calendar_5_color", config->calendar5_color, sizeof(config->calendar5_color));
    manager->addParameter("calendar_5_name", config->calendar5_name, sizeof(config->calendar5_name));
    manager->addParameter("calendar_5_url", config->calendar5_url, sizeof(config->calendar5_url));

    manager->addParameter("calendar_6_color", config->calendar6_color, sizeof(config->calendar6_color));
    manager->addParameter("calendar_6_name", config->calendar6_name, sizeof(config->calendar6_name));
    manager->addParameter("calendar_6_url", config->calendar6_url, sizeof(config->calendar6_url));

    manager->addParameter("calendar_7_color", config->calendar7_color, sizeof(config->calendar7_color));
    manager->addParameter("calendar_7_name", config->calendar7_name, sizeof(config->calendar7_name));
    manager->addParameter("calendar_7_url", config->calendar7_url, sizeof(config->calendar7_url));

    manager->addParameter("calendar_8_color", config->calendar8_color, sizeof(config->calendar8_color));
    manager->addParameter("calendar_8_name", config->calendar8_name, sizeof(config->calendar8_name));
    manager->addParameter("calendar_8_url", config->calendar8_url, sizeof(config->calendar8_url));

    manager->addParameter("version", &meta->version, get);
}

void Config::begin() const {
    manager->begin(*config);
}

char * Config::calendar_color(calendar_t calendar) const {
    switch (calendar) {
        case CALENDAR_1:
            return config->calendar1_color;
        case CALENDAR_2:
            return config->calendar2_color;
        case CALENDAR_3:
            return config->calendar3_color;
        case CALENDAR_4:
            return config->calendar4_color;
        case CALENDAR_5:
            return config->calendar5_color;
        case CALENDAR_6:
            return config->calendar6_color;
        case CALENDAR_7:
            return config->calendar7_color;
        case CALENDAR_8:
            return config->calendar8_color;
        default:
            throw std::exception();
    }
}

void Config::calendar_color(calendar_t calendar, const char * color) {
    switch (calendar) {
        case CALENDAR_1:
            strncpy(config->calendar1_color, color, sizeof(config->calendar1_color) + 1);
            break;
        case CALENDAR_2:
            strncpy(config->calendar2_color, color, sizeof(config->calendar2_color) + 1);
            break;
        case CALENDAR_3:
            strncpy(config->calendar3_color, color, sizeof(config->calendar3_color) + 1);
            break;
        case CALENDAR_4:
            strncpy(config->calendar4_color, color, sizeof(config->calendar4_color) + 1);
            break;
        case CALENDAR_5:
            strncpy(config->calendar5_color, color, sizeof(config->calendar5_color) + 1);
            break;
        case CALENDAR_6:
            strncpy(config->calendar6_color, color, sizeof(config->calendar6_color) + 1);
            break;
        case CALENDAR_7:
            strncpy(config->calendar7_color, color, sizeof(config->calendar7_color) + 1);
            break;
        case CALENDAR_8:
            strncpy(config->calendar8_color, color, sizeof(config->calendar8_color) + 1);
            break;
        default:
            throw std::exception();
    }
}

char * Config::calendar_name(calendar_t calendar) const {
    switch (calendar) {
        case CALENDAR_1:
            return config->calendar1_name;
        case CALENDAR_2:
            return config->calendar2_name;
        case CALENDAR_3:
            return config->calendar3_name;
        case CALENDAR_4:
            return config->calendar4_name;
        case CALENDAR_5:
            return config->calendar5_name;
        case CALENDAR_6:
            return config->calendar6_name;
        case CALENDAR_7:
            return config->calendar7_name;
        case CALENDAR_8:
            return config->calendar8_name;
        default:
            throw std::exception();
    }
}

void Config::calendar_name(calendar_t calendar, const char * name) {
    switch (calendar) {
        case CALENDAR_1:
            strncpy(config->calendar1_name, name, sizeof(config->calendar1_name) + 1);
            break;
        case CALENDAR_2:
            strncpy(config->calendar2_name, name, sizeof(config->calendar2_name) + 1);
            break;
        case CALENDAR_3:
            strncpy(config->calendar3_name, name, sizeof(config->calendar3_name) + 1);
            break;
        case CALENDAR_4:
            strncpy(config->calendar4_name, name, sizeof(config->calendar4_name) + 1);
            break;
        case CALENDAR_5:
            strncpy(config->calendar5_name, name, sizeof(config->calendar5_name) + 1);
            break;
        case CALENDAR_6:
            strncpy(config->calendar6_name, name, sizeof(config->calendar6_name) + 1);
            break;
        case CALENDAR_7:
            strncpy(config->calendar7_name, name, sizeof(config->calendar7_name) + 1);
            break;
        case CALENDAR_8:
            strncpy(config->calendar8_name, name, sizeof(config->calendar8_name) + 1);
            break;
        default:
            throw std::exception();
    }
}

char * Config::calendar_url(calendar_t calendar) const {
    switch (calendar) {
        case CALENDAR_1:
            return config->calendar1_url;
        case CALENDAR_2:
            return config->calendar2_url;
        case CALENDAR_3:
            return config->calendar3_url;
        case CALENDAR_4:
            return config->calendar4_url;
        case CALENDAR_5:
            return config->calendar5_url;
        case CALENDAR_6:
            return config->calendar6_url;
        case CALENDAR_7:
            return config->calendar7_url;
        case CALENDAR_8:
            return config->calendar8_url;
        default:
            throw std::exception();
    }
}

void Config::calendar_url(calendar_t calendar, const char * url) {
    switch (calendar) {
        case CALENDAR_1:
            strncpy(config->calendar1_url, url, sizeof(config->calendar1_url) + 1);
            break;
        case CALENDAR_2:
            strncpy(config->calendar2_url, url, sizeof(config->calendar2_url) + 1);
            break;
        case CALENDAR_3:
            strncpy(config->calendar3_url, url, sizeof(config->calendar3_url) + 1);
            break;
        case CALENDAR_4:
            strncpy(config->calendar4_url, url, sizeof(config->calendar4_url) + 1);
            break;
        case CALENDAR_5:
            strncpy(config->calendar5_url, url, sizeof(config->calendar5_url) + 1);
            break;
        case CALENDAR_6:
            strncpy(config->calendar6_url, url, sizeof(config->calendar6_url) + 1);
            break;
        case CALENDAR_7:
            strncpy(config->calendar7_url, url, sizeof(config->calendar7_url) + 1);
            break;
        case CALENDAR_8:
            strncpy(config->calendar8_url, url, sizeof(config->calendar8_url) + 1);
            break;
        default:
            throw std::exception();
    }
}

bool Config::isAPIMode() const {
    return manager->getMode() == api;
}

bool Config::isAPMode() const {
    return manager->getMode() == ap;
}

void Config::loop() const {
    manager->loop();
}

void Config::save() {
    meta->version += 1;
    manager->save();
}

uint32_t Config::timeinterval() const {
    return config->timeinterval;
}

void Config::timeinterval(uint32_t interval) {
    config->timeinterval = interval;
}

char * Config::timeserver() const {
    return config->timeserver;
}

void Config::timeserver(const char * server) {
    strncpy(config->timeserver, server, sizeof(config->timeserver) + 1);
}

char * Config::timezone() const {
    return config->timezone;
}

void Config::timezone(const char * timezone) {
    strncpy(config->timezone, timezone, sizeof(config->timezone) + 1);
}

int8_t Config::version() const {
    return meta->version;
}

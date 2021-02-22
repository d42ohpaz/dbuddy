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
        server->enableDelay(true);
        server->addHandler(new AssetsRequestHandler(this->manager));
        server->addHandler(new CalendarsRequestHandler(this->manager));
        server->addHandler(new IndexRequestHandler(this->manager));
        server->addHandler(new StockRequestHandler(this->manager));
        server->addHandler(new TimeSyncRequestHandler(this->manager));
        server->addHandler(new WifiRequestHandler(this->manager));
    };

    manager = new ConfigManager();

    manager->setAPName(ap_name);
    manager->setAPFilename("/index.html");
    manager->setAPCallback(webserver_callback_handler);
    manager->setAPICallback(webserver_callback_handler);

    manager->setWebPort(port);

    manager->addParameter("timeserver", config->timeserver, sizeof(config->timeserver));
    manager->addParameter("timeinterval", &config->timeinterval);
    manager->addParameter("timezone", config->timezone, sizeof(config->timezone));

    for (int i = 0; i < CALENDARS; i++) {
        char cal_color[18], cal_name[18], cal_url[18];

        sprintf(cal_color, "calendar_color_%d", i);
        sprintf(cal_name, "calendar_name_%d", i);
        sprintf(cal_url, "calendar_url_%d", i);

        manager->addParameter(cal_color, config->calendar[i].color, sizeof(config->calendar[i].color) + 1);
        manager->addParameter(cal_name, config->calendar[i].name, sizeof(config->calendar[i].name) + 1);
        manager->addParameter(cal_url, config->calendar[i].url, sizeof(config->calendar[i].url) + 1);
    }

    manager->addParameter("version", &meta->version, get);
}

void Config::begin() const {
    manager->begin(*config);
}

char * Config::calendar_color(calendar_t calendar) const {
    return config->calendar[calendar].color;
}

void Config::calendar_color(calendar_t calendar, const char * color) {
    strncpy(config->calendar[calendar].color, color, sizeof(config->calendar[calendar].color));
}

char * Config::calendar_name(calendar_t calendar) const {
    return config->calendar[calendar].name;
}

void Config::calendar_name(calendar_t calendar, const char * name) {
    strncpy(config->calendar[calendar].name, name, sizeof(config->calendar[calendar].name));
}

char * Config::calendar_url(calendar_t calendar) const {
    return config->calendar[calendar].url;
}

void Config::calendar_url(calendar_t calendar, const char * url) {
    strncpy(config->calendar[calendar].url, url, sizeof(config->calendar[calendar].url));
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

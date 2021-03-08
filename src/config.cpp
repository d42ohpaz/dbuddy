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
        server->addHandler(new AssetsRequestHandler(this));
        server->addHandler(new CalendarsRequestHandler(this));
        server->addHandler(new IndexRequestHandler(this));
        server->addHandler(new StockRequestHandler(this));
        server->addHandler(new TimeSyncRequestHandler(this));
        server->addHandler(new WifiRequestHandler(this));
    };

    manager = new ConfigManager();

    manager->setAPName(ap_name);
    manager->setAPFilename("/");
    manager->setAPCallback(webserver_callback_handler);
    manager->setAPICallback(webserver_callback_handler);

    manager->setWebPort(port);

    manager->addParameter("timeserver", config.timeserver, sizeof(config.timeserver));
    manager->addParameter("timeinterval", &config.timeinterval);
    manager->addParameter("timezone", config.timezone, sizeof(config.timezone));

    for (int i = 0; i < CALENDARS; i++) {
        char cal_color[18], cal_name[18], cal_url[18];

        sprintf(cal_color, "calendar_color_%d", i);
        sprintf(cal_name, "calendar_name_%d", i);
        sprintf(cal_url, "calendar_url_%d", i);

        config_cal_t * calendar = &config.calendar[i];
        manager->addParameter(cal_color, calendar->color, sizeof(calendar->color) + 1);
        manager->addParameter(cal_name, calendar->name, sizeof(calendar->name) + 1);
        manager->addParameter(cal_url, calendar->url, sizeof(calendar->url) + 1);
    }

    manager->addParameter("calendars", &config.calendars);
    manager->addParameter("version", &meta.version, get);

    meta.version = 1;
}

void Config::begin() {
    manager->begin(*config);
}

uint Config::add_calendar(config_cal_t * calendar) {
    if (config.calendars >= CALENDARS) {
        throw std::out_of_range("Exceeded maximum number of calendars");
    }

    memcpy(&config.calendar[config.calendars++], calendar, sizeof(config_cal_t));
    return config.calendars;
}

void Config::update_calendar(uint idx, config_cal_t * calendar) {
    if (idx >= CALENDARS) {
        throw std::out_of_range("Exceeded maximum number of calendars");
    }

    memcpy(&config.calendar[idx], calendar, sizeof(config_cal_t));
}

void Config::clear_calendars() {
    for (int i = 0; i < CALENDARS; i++) {
        memcpy(&config.calendar[i], new config_cal_t(), sizeof(config_cal_t));
        config.calendars--;
    }
}

config_cal_t * Config::get_calendar(uint calendar) const {
    if (calendar >= CALENDARS) {
        char * message = new char();
        sprintf(message, "Only %d calendars are allowed", CALENDARS);
        throw std::out_of_range(message);
    }

    return &config.calendar[calendar];
}

const config_cal_t * Config::get_calendars() const {
    auto * calendars = new config_cal_t[CALENDARS];
    for (int i = 0; i < CALENDARS; i++) {
        memcpy(&calendars[i], &config.calendar[i], sizeof(config_cal_t));
    }

    return calendars;
}

int Config::length_calendars() const {
    return config.calendars;
}

bool Config::isAPIMode() {
    return manager->getMode() == api;
}

bool Config::isAPMode() {
    return manager->getMode() == ap;
}

void Config::loop() {
    manager->loop();
}

void Config::save() {
    manager->save();
}

void Config::streamFile(const char* file, const char mime[]) {
    manager->streamFile(file, mime);
}

uint32_t Config::timeinterval() const {
    return config.timeinterval;
}

void Config::timeinterval(uint32_t interval) {
    config.timeinterval = interval;
}

char * Config::timeserver() const {
    return (char *)config.timeserver;
}

void Config::timeserver(const char * server) {
    strncpy(config.timeserver, server, sizeof(config.timeserver) + 1);
}

char * Config::timezone() const {
    return (char *)config.timezone;
}

void Config::timezone(const char * timezone) {
    strncpy(config.timezone, timezone, sizeof(config.timezone) + 1);
}

int8_t Config::version() const {
    return meta.version;
}

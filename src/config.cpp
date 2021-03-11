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

    manager.setAPName(ap_name);
    manager.setAPFilename("/wifi.html.gz");
    manager.setAPCallback(webserver_callback_handler);
    manager.setAPICallback(webserver_callback_handler);

    manager.setWebPort(port);

    manager.addParameter("timeserver", config.timeserver, sizeof(config.timeserver));
    manager.addParameter("timeinterval", &config.timeinterval);
    manager.addParameter("timezone", config.timezone, sizeof(config.timezone));

    for (uint8_t i = 0; i < CALENDARS; i++) {
        char cal_color[18], cal_name[18], cal_url[18];

        sprintf(cal_color, "calendar_color_%d", i);
        sprintf(cal_name, "calendar_name_%d", i);
        sprintf(cal_url, "calendar_url_%d", i);

        if (has_calendar(i)) {
            config_cal_t calendar = get_calendar(i);
            manager.addParameter(cal_color, calendar.color, sizeof(config_cal_t::color));
            manager.addParameter(cal_name, calendar.name, sizeof(config_cal_t::name));
            manager.addParameter(cal_url, calendar.url, sizeof(config_cal_t::url));
        } else {
            manager.addParameter(cal_color, (char *)"", sizeof(config_cal_t::color));
            manager.addParameter(cal_name, (char *)"", sizeof(config_cal_t::name));
            manager.addParameter(cal_url, (char *)"", sizeof(config_cal_t::url));
        }
    }

    manager.addParameter("calendars", &config.calendars);
    manager.addParameter("version", &meta.version, get);

    meta.version = 1;
}

void Config::begin() {
    manager.begin(config);
}

uint8_t Config::add_calendar(config_cal_t &calendar) {
    if (config.calendars > CALENDARS) {
        throw std::out_of_range("Exceeded maximum number of calendars");
    }

    config.calendar[config.calendars] = calendar;
    return config.calendars++;
}

void Config::clear_calendars() {
    config.calendars = 0;
}

config_cal_t Config::get_calendar(uint8_t idx) const {
    if (idx > CALENDARS) {
        char * message = new char();
        sprintf(message, "A maximum of %u calendars allowed; requested %u\n", CALENDARS, idx);
        throw std::out_of_range(message);
    }

    if (idx > config.calendars) {
        char * message = new char();
        sprintf(message, "Only %u calendars defined; requested %u\n", config.calendars, idx);
        throw std::out_of_range(message);
    }

    return config.calendar[idx];
}

const config_cal_t * Config::get_calendars() const {
    auto * calendars = new config_cal_t[CALENDARS];
    for (uint8_t i = 0; i < config.calendars; i++) {
        memcpy(&calendars[i], &config.calendar[i], sizeof(config_cal_t));
    }

    return calendars;
}

bool Config::has_calendar(uint8_t i) const {
    return i < config.calendars;
}

uint8_t Config::length_calendars() const {
    return config.calendars;
}

bool Config::isStation() {
    return manager.getMode() == station;
}

bool Config::isAccessPoint() {
    return manager.getMode() == ap;
}

void Config::loop() {
    manager.loop();
}

void Config::save() {
    manager.save();
}

void Config::streamFile(const char* file, const char mime[]) {
    manager.streamFile(file, mime);
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

uint8_t Config::version() const {
    return meta.version;
}

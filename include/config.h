#pragma once

#include <ConfigManager.h>

#define CONFIG_DEFAULT_TIMESERVER ("time.nist.gov")
#define CONFIG_DEFAULT_TIMEZONE ("America/New_York")

namespace dbuddy {
    const uint8_t CALENDARS = 8;

    typedef struct configuration_calendar_t {
        char name[100];
        char color[8];
        char url[200];
    } config_cal_t;

    typedef struct configuration_t {
        char timeserver[200];
        char timezone[32];
        unsigned int timeinterval;

        uint8_t calendars;
        config_cal_t calendar[CALENDARS];
    } config_t;

    typedef struct metadata_t {
        int8_t version = 0;
    } meta_t;

    class Config {
    public:
        explicit Config(const char *, uint16_t);

        char * timeserver() const;
        uint32_t timeinterval() const;
        char * timezone() const;

        int8_t version() const;

        void timeserver(const char *);
        void timeinterval(uint32_t);
        void timezone(const char *);

        uint add_calendar(config_cal_t * config);
        void update_calendar(uint calendar, config_cal_t * config);

        void clear_calendars();
        config_cal_t * get_calendar(uint) const;
        const config_cal_t * get_calendars() const;
        int length_calendars() const;

        void begin();
        bool isStation();
        bool isAccessPoint();
        void loop();
        void save();

        void streamFile(const char* file, const char mime[]);
    private:
        ConfigManager * manager{};
        config_t config{};
        meta_t meta{};
    };
}

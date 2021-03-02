#pragma once

#include <ConfigManager.h>

#define CONFIG_DEFAULT_TIMESERVER ("time.nist.gov")
#define CONFIG_DEFAULT_TIMEZONE ("America/New_York")

namespace dbuddy {
    const uint8_t CALENDARS = 8;

    enum calendar_t {
        CALENDAR_1,
        CALENDAR_2,
        CALENDAR_3,
        CALENDAR_4,
        CALENDAR_5,
        CALENDAR_6,
        CALENDAR_7,
        CALENDAR_8,
    };

    typedef struct configuration_calendar_t {
        char name[100];
        char color[8];
        char url[200];
    } config_cal_t;

    typedef struct configuration_t {
        char timeserver[200] = "time.nist.gov";
        uint32_t timeinterval = 3600;
        char timezone[32] = "America/New_York";

        config_cal_t calendar[CALENDARS]{};
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

        char * calendar_color(calendar_t) const;
        char * calendar_name(calendar_t) const;
        char * calendar_url(calendar_t) const;

        int8_t version() const;

        void timeserver(const char *);
        void timeinterval(uint32_t);
        void timezone(const char *);

        void calendar_color(calendar_t, const char *);
        void calendar_name(calendar_t, const char *);
        void calendar_url(calendar_t, const char *);

        void begin() const;
        bool isAPIMode() const;
        bool isAPMode() const;
        void loop() const;
        void save();

        void streamFile(const char* file, const char mime[]) const;
    private:
        ConfigManager * manager{};
        configuration_t * config = new configuration_t;
        metadata_t * meta = new metadata_t;
    };
}

#pragma once

#include <ConfigManager.h>

#define CONFIG_DEFAULT_TIMESERVER ("time.nist.gov")
#define CONFIG_DEFAULT_TIMEZONE ("America/New_York")

#define CONFIG_DEFAULT_TIMESERVER_LENGTH (sizeof(CONFIG_DEFAULT_TIMESERVER) + 1)
#define CONFIG_DEFAULT_TIMEZONE_LENGTH (sizeof(CONFIG_DEFAULT_TIMEZONE) + 1)

namespace dbuddy {
    enum calendar_t {
        CALENDAR_1  = 0x01,
        CALENDAR_2  = 0x02,
        CALENDAR_3  = 0x03,
        CALENDAR_4  = 0x04,
        CALENDAR_5  = 0x05,
        CALENDAR_6  = 0x06,
        CALENDAR_7  = 0x07,
        CALENDAR_8  = 0x08,
    };

    typedef struct configuration_t {
        char timeserver[200]{};
        uint32_t timeinterval = 3600;
        char timezone[32]{};

        char calendar1_name[100]{};
        char calendar1_color[8]{};
        char calendar1_url[200]{};

        char calendar2_name[100]{};
        char calendar2_color[8]{};
        char calendar2_url[200]{};

        char calendar3_name[100]{};
        char calendar3_color[8]{};
        char calendar3_url[200]{};

        char calendar4_name[100]{};
        char calendar4_color[8]{};
        char calendar4_url[200]{};

        char calendar5_name[100]{};
        char calendar5_color[8]{};
        char calendar5_url[200]{};

        char calendar6_name[100]{};
        char calendar6_color[8]{};
        char calendar6_url[200]{};

        char calendar7_name[100]{};
        char calendar7_color[8]{};
        char calendar7_url[200]{};

        char calendar8_name[100]{};
        char calendar8_color[8]{};
        char calendar8_url[200]{};
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
        void loop() const;
        void save();
    private:
        ConfigManager * manager{};
        configuration_t * config = new configuration_t;
        metadata_t * meta = new metadata_t;
    };
}

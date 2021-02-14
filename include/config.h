#pragma once

#define CONFIG_DEFAULT_TIMESERVER ("time.nist.gov")
#define CONFIG_DEFAULT_TIMEZONE ("America/New_York")

#define CONFIG_DEFAULT_TIMESERVER_LENGTH (sizeof(CONFIG_DEFAULT_TIMESERVER) + 1)
#define CONFIG_DEFAULT_TIMEZONE_LENGTH (sizeof(CONFIG_DEFAULT_TIMEZONE) + 1)

namespace dbuddy {
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
}

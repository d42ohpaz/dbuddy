#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <time.h>

typedef struct time_config_t {
    int flash;
    int format24;
    int meridiem;
    int screensaver;
} time_config_t;

typedef struct cal_event_t {
    char * desc;
    char * summary;

    struct tm dt_start;
    struct tm dt_end;

    char * tz_id;
} cal_event_t;

typedef struct cal_config_t {
    char * url;
    char * name;

    lv_color_t color;

    cal_event_t events[];
} cal_config_t;

typedef struct config_t {
    time_config_t time;

    cal_config_t calendars[];
} configuration_t;

static inline int compareTo(const configuration_t lhs, const configuration_t rhs) {
    if (lhs.time.flash < rhs.time.flash) {
        return -1;
    } else if (lhs.time.flash > rhs.time.flash) {
        return 1;
    }

    if (lhs.time.format24 < rhs.time.format24) {
        return -1;
    } else if (lhs.time.format24 > rhs.time.format24) {
        return 1;
    }

    if (lhs.time.meridiem < rhs.time.meridiem) {
        return -1;
    } else if (lhs.time.meridiem > rhs.time.meridiem) {
        return 1;
    }

    if (lhs.time.screensaver < rhs.time.screensaver) {
        return -1;
    } else if (lhs.time.screensaver > rhs.time.screensaver) {
        return 1;
    }

    return 0;
}

#endif //CONFIGURATION_H



#ifndef BASIC_ICS_CONFIGURATION_H
#define BASIC_ICS_CONFIGURATION_H

#include <stdlib.h>

typedef struct configuration {
    size_t time_flash;
    size_t time_format24;
    size_t time_meridiem;
    size_t time_screensaver;
} configuration;

configuration * p_config;

static inline int compareTo(const configuration lhs, const configuration rhs) {
    if (lhs.time_flash < rhs.time_flash) {
        return -1;
    } else if (lhs.time_flash > rhs.time_flash) {
        return 1;
    }

    if (lhs.time_format24 < rhs.time_format24) {
        return -1;
    } else if (lhs.time_format24 > rhs.time_format24) {
        return 1;
    }

    if (lhs.time_meridiem < rhs.time_meridiem) {
        return -1;
    } else if (lhs.time_meridiem > rhs.time_meridiem) {
        return 1;
    }

    if (lhs.time_screensaver < rhs.time_screensaver) {
        return -1;
    } else if (lhs.time_screensaver > rhs.time_screensaver) {
        return 1;
    }

    return 0;
}

#endif //BASIC_ICS_CONFIGURATION_H

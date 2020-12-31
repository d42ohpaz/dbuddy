#ifndef BASIC_ICS_CONFIGURATION_H
#define BASIC_ICS_CONFIGURATION_H

typedef struct time_config_t {
    int flash;
    int format24;
    int meridiem;
    int screensaver;
} time_config_t;

typedef struct config_t {
    time_config_t time;
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

#endif //BASIC_ICS_CONFIGURATION_H

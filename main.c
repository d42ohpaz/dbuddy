#include <unistd.h>
#include <stdlib.h>

#include "lvgl/lvgl.h"
#include "inih/ini.h"
#include "src/hal.h"
#include "src/ui.h"
#include "src/configuration.h"

int cb_config_handler(void* user, const char* section, const char* name, const char* value);

int main(int argc, char **argv) {
    (void) argc; /*Unused*/
    (void) argv; /*Unused*/

    p_config = malloc(sizeof(configuration));
    ini_parse("dbuddy.ini", cb_config_handler, p_config);

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();

    /*Initialize the UI*/
    ui_init();

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(1000);
    }
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
    return 0;
#pragma clang diagnostic pop
}

int cb_config_handler(void* user, const char* section, const char* name, const char* value) {
    configuration * config = (configuration *)user;

#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    if (MATCH("general", "time_format24")) {
        config->time_format24 = strtol(value, NULL, 10);
    } else if (MATCH("general", "time_meridiem")) {
        config->time_meridiem = strtol(value, NULL, 10);
    } else if (MATCH("general", "time_flash")) {
        config->time_flash = strtol(value, NULL, 10);
    } else if (MATCH("general", "time_screensaver")) {
        config->time_screensaver = strtol(value, NULL, 10);
    } else {
        return 1;
    }

    return 0;
}

#include <unistd.h>
#include <stdlib.h>

#include "lvgl/lvgl.h"
#include "inih/ini.h"
#include "src/hal.h"
#include "src/ui.h"
#include "src/configuration.h"

int cb_config_handler(void* user, const char* section, const char* name, const char* value);
int cb_settings_handler(configuration_t * lconfig);

int main(int argc, char **argv) {
    (void) argc; /*Unused*/
    (void) argv; /*Unused*/

    configuration_t * config = malloc(sizeof(configuration_t));
    ini_parse("dbuddy.ini", cb_config_handler, config);

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();

    /*Initialize the UI*/
    ui_init(config, cb_settings_handler);

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
    configuration_t * config = (configuration_t *)user;

#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    if (MATCH("general", "time_format24")) {
        config->time.format24 = (int)strtol(value, NULL, 10);
    } else if (MATCH("general", "time_meridiem")) {
        config->time.meridiem = (int)strtol(value, NULL, 10);
    } else if (MATCH("general", "time_flash")) {
        config->time.flash = (int)strtol(value, NULL, 10);
    } else if (MATCH("general", "time_screensaver")) {
        config->time.screensaver = (int)strtol(value, NULL, 10);
    } else {
        return 1;
    }

    return 0;
}

int cb_settings_handler(configuration_t * lconfig) {
    FILE * file = fopen("dbuddy.ini", "wb+");

    if (file == NULL) {
        perror("Unable to open dbuddy.ini for writing\n");
        return -1;
    }

    fputs("[general]\n", file);

    char time_format24[19];
    sprintf(time_format24, "time_format24 = %d\n", lconfig->time.format24);
    fputs(time_format24, file);

    char time_meridiem[19];
    sprintf(time_meridiem, "time_meridiem = %d\n", lconfig->time.meridiem);
    fputs(time_meridiem, file);

    char time_flash[16];
    sprintf(time_flash, "time_flash = %d\n", lconfig->time.flash);
    fputs(time_flash, file);

    char time_screensaver[22];
    sprintf(time_screensaver, "time_screensaver = %d\n", lconfig->time.screensaver);
    fputs(time_screensaver, file);

    fputs("\n[calendars]\n", file);

    fclose(file);

    return 0;
}

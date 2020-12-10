#define _DEFAULT_SOURCE /* needed for usleep() */

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "lvgl/lvgl.h"
#include "hal.h"

#define DEFAULT_PADDING 16
#define DEFAULT_BORDER 5

int main(int argc, char **argv) {
    (void) argc; /*Unused*/
    (void) argv; /*Unused*/

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();

    while (true) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}

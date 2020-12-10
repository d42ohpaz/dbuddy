#define _DEFAULT_SOURCE /* needed for usleep() */

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "lvgl/lvgl.h"
#include "hal.h"

#define DEFAULT_PADDING 16
#define DEFAULT_BORDER 5

LV_IMG_DECLARE(tft_background_art)

int main(int argc, char **argv) {
    (void) argc; /*Unused*/
    (void) argv; /*Unused*/

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();

    lv_disp_t *disp = lv_disp_get_default();
    lv_obj_t *scr = lv_scr_act();

    lv_disp_set_bg_image(disp, &tft_background_art);
    lv_obj_set_style_local_bg_opa(scr, LV_OBJMASK_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);
    while (true) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}

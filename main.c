#define _DEFAULT_SOURCE /* needed for usleep() */

#include <unistd.h>

#include "lvgl/lvgl.h"
#include "hal.h"


int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

  static lv_style_t style_radius_0;
  lv_style_init(&style_radius_0);
  lv_style_set_radius(&style_radius_0, LV_STATE_DEFAULT, 0);

  static lv_style_t style_radius_10;
  lv_style_init(&style_radius_10);
  lv_style_set_radius(&style_radius_10, LV_STATE_DEFAULT, 10);

  static lv_style_t style_bg_dark;
  lv_style_init(&style_bg_dark);
  lv_style_set_bg_grad_dir(&style_bg_dark, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_main_stop(&style_bg_dark, LV_STATE_DEFAULT, 255*.66);
  lv_style_set_bg_grad_color(&style_bg_dark, LV_STATE_DEFAULT, LV_COLOR_MAKE(10, 10, 10));
  lv_style_set_bg_blend_mode(&style_bg_dark, LV_STATE_DEFAULT, LV_BLEND_MODE_SUBTRACTIVE);

  static lv_style_t style_border_hl;
  lv_style_init(&style_border_hl);
  lv_style_set_border_width(&style_border_hl, LV_STATE_DEFAULT, 2);
  lv_style_set_border_color(&style_border_hl, LV_STATE_DEFAULT, LV_COLOR_WHITE);

  static lv_style_t style_shadow_bright;
  lv_style_init(&style_shadow_bright);
  lv_style_set_shadow_width(&style_shadow_bright, LV_STATE_DEFAULT, 30);
  lv_style_set_shadow_spread(&style_shadow_bright, LV_STATE_DEFAULT, 10);
  lv_style_set_shadow_color(&style_shadow_bright, LV_STATE_DEFAULT, LV_COLOR_GREEN);

  static lv_style_t style_border_none;
  lv_style_init(&style_border_none);
  lv_style_set_border_width(&style_border_none, LV_STATE_DEFAULT, 0);

  static lv_style_t style_bg_opa_0;
  lv_style_init(&style_bg_opa_0);
  lv_style_set_bg_opa(&style_bg_opa_0, LV_STATE_DEFAULT, LV_OPA_0);

  lv_obj_t * main;
  main = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(main, LV_HOR_RES, LV_VER_RES);
  lv_obj_align(main, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_style(main, LV_OBJ_PART_MAIN, &style_bg_dark);
  lv_obj_add_style(main, LV_OBJ_PART_MAIN, &style_border_none);
  lv_obj_add_style(main, LV_OBJ_PART_MAIN, &style_radius_0);

  lv_obj_t * neon_glow;
  neon_glow = lv_obj_create(lv_scr_act(), main);
  lv_obj_set_size(main, LV_HOR_RES, LV_VER_RES);
  lv_obj_align(main, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_style(neon_glow, LV_OBJ_PART_MAIN, &style_bg_opa_0);
  lv_obj_add_style(neon_glow, LV_OBJ_PART_MAIN, &style_radius_0);

  lv_obj_t * border_white;
  border_white = lv_obj_create(lv_scr_act(), neon_glow);
  lv_obj_set_size(border_white, LV_HOR_RES - 20, LV_VER_RES - 20);
  lv_obj_align(border_white, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_style(border_white, LV_OBJ_PART_MAIN, &style_border_hl);
  lv_obj_add_style(border_white, LV_OBJ_PART_MAIN, &style_bg_opa_0);
  lv_obj_add_style(border_white, LV_OBJ_PART_MAIN, &style_radius_10);

  lv_obj_t * shadow_glow;
  shadow_glow = lv_obj_create(lv_scr_act(), neon_glow);
  lv_obj_set_size(shadow_glow, LV_HOR_RES - 27, LV_VER_RES - 27);
  lv_obj_align(shadow_glow, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_style(shadow_glow, LV_OBJ_PART_MAIN, &style_shadow_bright);
  lv_obj_add_style(shadow_glow, LV_OBJ_PART_MAIN, &style_bg_opa_0);
  lv_obj_add_style(shadow_glow, LV_OBJ_PART_MAIN, &style_radius_10);

  lv_obj_set_click(main, false);
  lv_obj_set_click(neon_glow, false);
  lv_obj_set_click(border_white, false);
  lv_obj_set_click(shadow_glow, false);

  while (1) {
    /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
    lv_task_handler();
    usleep(5 * 1000);
  }

  return 0;
}

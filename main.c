
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" \
                            issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);
static void memory_monitor(lv_task_t *param);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t *kb_indev;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

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

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics
 * library
 */
static void hal_init(void) {
  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  monitor_init();

  /*Create a display buffer*/
  static lv_disp_buf_t disp_buf1;
  static lv_color_t buf1_1[LV_HOR_RES_MAX * 120];
  lv_disp_buf_init(&disp_buf1, buf1_1, NULL, LV_HOR_RES_MAX * 120);

  /*Create a display*/
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.buffer = &disp_buf1;
  disp_drv.flush_cb = monitor_flush;
  lv_disp_drv_register(&disp_drv);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  mouse_init();
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv); /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;

  /*This function will be called periodically (by the library) to get the mouse position and state*/
  indev_drv.read_cb = mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv);

  /*Set a cursor for the mouse*/
  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj = lv_img_create(lv_scr_act(), NULL); /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/

  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);

  /* Optional:
   * Create a memory monitor task which prints the memory usage in
   * periodically.*/
  lv_task_create(memory_monitor, 5000, LV_TASK_PRIO_MID, NULL);
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data) {
  (void)data;

  while (1) {
    SDL_Delay(5);   /*Sleep for 5 millisecond*/
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }

  return 0;
}

/**
 * Print the memory usage periodically
 * @param param
 */
static void memory_monitor(lv_task_t *param) {
  (void)param; /*Unused*/

  lv_mem_monitor_t mon;
  lv_mem_monitor(&mon);
  printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
}

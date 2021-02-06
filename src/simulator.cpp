#if !defined(ARDUINO)
#include <SDL2/SDL.h>
#include <display/monitor.h>
#include <indev/mouse.h>

#include "simulator.h"

#define SDL_MAIN_HANDLED

using namespace dbuddy;

extern "C" int tick_thread(void *data) {
  (void)data;

  while (true) {
    SDL_Delay(5);   /*Sleep for 5 millisecond*/
    lv_tick_inc(5); /*Tell LVGL that 5 milliseconds were elapsed*/
  }

  return 0;
}

void Simulator::init() {
    monitor_init();

    /* Tick init.
     * You have to call 'lv_tick_inc()' in periodically to inform LVGL about
     * how much time were elapsed Create an SDL thread to do this */
    SDL_CreateThread(tick_thread, "tick", NULL);
}

void Simulator::display_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color) {
    monitor_flush(drv, area, color);
}

bool Simulator::input_read(lv_indev_drv_t * drv, lv_indev_data_t * data) {
    return mouse_read(drv, data);
}
#endif

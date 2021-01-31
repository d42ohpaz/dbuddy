#ifdef USE_MONITOR
#include <display/monitor.h>
#include <SDL2/SDL.h>

#include "simulator.h"

#define SDL_MAIN_HANDLED

extern "C" int tick_thread(void *data) {
  (void)data;

  while (true) {
    SDL_Delay(5);   /*Sleep for 5 millisecond*/
    lv_tick_inc(5); /*Tell LVGL that 5 milliseconds were elapsed*/
  }

  return 0;
}

void dbuddy::Simulator::init() {
    monitor_init();

    /* Tick init.
     * You have to call 'lv_tick_inc()' in periodically to inform LVGL about
     * how much time were elapsed Create an SDL thread to do this */
    SDL_CreateThread(tick_thread, "tick", NULL);
}

void dbuddy::Simulator::flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color) {
    monitor_flush(drv, area, color);
}
#endif

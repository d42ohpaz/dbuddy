#include <stdexcept>

#define RA8875_INT      13
#define RA8875_CS       5
#define RA8875_RESET    12

#include "dbuddy.h"
#include "nodemcu32s.h"
#include "ui.h"

#define USE_DOUBLE_BUFFER (false)

static void memory_monitor(lv_task_t *param);

void setup() {
#ifndef USE_MONITOR
    Serial.begin(115200);
#endif

    dbuddy::DBuddy::setup(
        new dbuddy::NodeMCU32s(new Adafruit_RA8875(RA8875_CS, RA8875_RESET), RA8875_INT),
        new dbuddy::Ui,
        USE_DOUBLE_BUFFER
    );

    lv_task_create(memory_monitor, 5000, LV_TASK_PRIO_MID, nullptr);
}

void loop() {
    dbuddy::DBuddy::loop();
}

/**
 * Print the memory usage periodically
 * @param param
 */
static void memory_monitor(lv_task_t *param) {
  (void)param; /*Unused*/

  lv_mem_monitor_t mon;
  lv_mem_monitor(&mon);

#ifndef USE_MONITOR
  Serial.printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
#else
  printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
#endif
}

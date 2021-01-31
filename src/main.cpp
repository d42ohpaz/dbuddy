#include <stdexcept>

#include "dbuddy.h"
#include "fonts.h"
#include "styles.h"
#include "ui.h"

#if defined(ARDUINO)
#define RA8875_INT      13
#define RA8875_CS       5
#define RA8875_RESET    12

#include "nodemcu32s.h"
#else
#include <cstdio>
#include "simulator.h"
#endif

#define USE_DOUBLE_BUFFER (false)

using namespace dbuddy;

#if LV_MEM_CUSTOM == 0
static void memory_monitor(lv_task_t *param);
#endif

void setup() {
#if defined (ARDUINO)
    Serial.begin(115200);
#endif

    lv_init();

    DBuddy::setup(
#if defined (ARDUINO)
        new NodeMCU32s(new Adafruit_RA8875(RA8875_CS, RA8875_RESET), RA8875_INT),
#else
        new Simulator(),
#endif
        new Ui(new Fonts, new Styles),
        USE_DOUBLE_BUFFER
    );

#if LV_MEM_CUSTOM == 0
    lv_task_create(memory_monitor, 5000, LV_TASK_PRIO_MID, nullptr);
#endif
}

void loop() {
    DBuddy::loop();
}

#if !defined(ARDUINO)
int main() {
    setup();

    while (true) {
        loop();
    }
}
#endif

#if LV_MEM_CUSTOM == 0
/**
 * Print the memory usage periodically
 * @param param
 */
static void memory_monitor(lv_task_t *param) {
  (void)param; /*Unused*/

  lv_mem_monitor_t mon;
  lv_mem_monitor(&mon);

#if defined(ARDUINO)
  Serial.printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
#else
  printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
#endif
}
#endif

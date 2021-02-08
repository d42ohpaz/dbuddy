#include "dbuddy.h"
#include "fonts.h"
#include "styles.h"
#include "ui.h"

#if defined(ARDUINO)
#define RA8875_INT      14
#define RA8875_CS       5
#define RA8875_RESET    34
#define RA8875_XP       4
#define RA8875_YP       A11
#define RA8875_XM       A12
#define RA8875_YM       15
#define RA8875_RX       500

#include "nodemcu32s.h"
#else
#include <cstdio>
#include "simulator.h"
#endif

#define USE_DOUBLE_BUFFER (false)

using namespace dbuddy;

void setup() {
#if defined (ARDUINO)
    Serial.begin(115200);
#endif

    lv_init();

    DBuddy::setup(
#if defined (ARDUINO)
        new NodeMCU32s(
                new Adafruit_RA8875(RA8875_CS, RA8875_RESET),
                new TouchScreen(RA8875_XP, RA8875_YP, RA8875_XM, RA8875_YM, RA8875_RX),
                RA8875_INT
            ),
#else
        new Simulator(),
#endif
        new Ui(new Fonts, new Styles),
        USE_DOUBLE_BUFFER,
        LV_INDEV_TYPE_POINTER
    );
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

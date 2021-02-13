#include "dbuddy.h"
#include "fonts.h"
#include "styles.h"
#include "ui.h"

#define RA8875_INT      14
#define RA8875_CS       5
#define RA8875_RESET    34
#define RA8875_XP       4
#define RA8875_YP       A11
#define RA8875_XM       A12
#define RA8875_YM       15
#define RA8875_RX       500

#include "esp32dev.h"

#define USE_DOUBLE_BUFFER (false)

using namespace dbuddy;

void setup() {
    Serial.begin(115200);

    lv_init();

    DBuddy::setup(
        new ESP32Dev(
            new Adafruit_RA8875(RA8875_CS, RA8875_RESET),
            new TouchScreen(RA8875_XP, RA8875_YP, RA8875_XM, RA8875_YM, RA8875_RX),
            RA8875_INT
        ),
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

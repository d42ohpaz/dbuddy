#include <stdexcept>

#define RA8875_INT      13
#define RA8875_CS       5
#define RA8875_RESET    12

#include "dbuddy.h"
#include "nodemcu32s.h"
#include "ui.h"

#define USE_DOUBLE_BUFFER (false)

void setup() {
    DBuddy::DBuddy::setup(
        new DBuddy::NodeMCU32s(new Adafruit_RA8875(RA8875_CS, RA8875_RESET), RA8875_INT),
        new DBuddy::Ui,
        USE_DOUBLE_BUFFER
    );
}

void loop() {
    DBuddy::DBuddy::loop();
}

#include <stdexcept>

#define RA8875_INT      13
#define RA8875_CS       5
#define RA8875_RESET    12

#include "dbuddy.h"
#include "nodemcu32s.h"

#define USE_DOUBLE_BUFFER (false)

void setup() {
    Serial.begin(115200);

    try {
        DBuddy::Hal * hal = new DBuddy::NodeMCU32s(Adafruit_RA8875(RA8875_CS, RA8875_RESET), RA8875_INT);
        DBuddy::DBuddy::setup(hal, USE_DOUBLE_BUFFER);
    } catch (std::runtime_error &error) {
        Serial.printf("Unhandled exception caught: %s\n", error.what());
    }

    Serial.println("Setup complete");
}

void loop() {
    Serial.println("Begin loop");
    DBuddy::DBuddy::loop();
    Serial.println("End loop");
}

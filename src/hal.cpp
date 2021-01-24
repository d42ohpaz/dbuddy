#include <stdexcept>
#include <Arduino.h>
#include <functional>

#include "hal.h"

using namespace std;
using namespace std::placeholders;

void DBuddy::Hal::run(bool use_dbl_buff) {
    Serial.println("Initializing HAL");
    init();

    if (use_dbl_buff) {
        Serial.println("Initializing double-buffer display buffer");
        lv_disp_buf_init(display_buffer, buffer0, buffer1, BUFFER_SIZE);
    } else {
        Serial.println("Initializing single-buffer display buffer");
        lv_disp_buf_init(display_buffer, buffer0, nullptr, BUFFER_SIZE);
    }

    Serial.printf("Initializing the display driver: %p\n", this);
    lv_disp_drv_init(display_driver);
    // display_driver->flush_cb = <what goes here?>;
    display_driver->buffer = display_buffer;

    Serial.println("Registering the display driver");
    if (!lv_disp_drv_register(display_driver)) {
        throw std::runtime_error("Unable to register the display driver");
    }
}

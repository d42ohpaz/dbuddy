#include <stdexcept>

#include "hal.h"

using namespace dbuddy;

/**
 * The c-callback for flushing our visual data to our display driver.
 */
extern "C" void flush_callback(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color) {
    auto * instance = (Hal *)drv->user_data;
    instance->flush(drv, area, color);
}

void Hal::run(bool use_dbl_buff) {
    if (use_dbl_buff) {
        lv_disp_buf_init(display_buffer, buffer0, buffer1, BUFFER_SIZE);
    } else {
        lv_disp_buf_init(display_buffer, buffer0, nullptr, BUFFER_SIZE);
    }

    lv_disp_drv_init(display_driver);

    // Make the instance available for our c-callback above.
    display_driver->user_data = this;

    display_driver->flush_cb = &flush_callback;
    display_driver->buffer = display_buffer;

    if (!lv_disp_drv_register(display_driver)) {
        throw std::runtime_error("Unable to register the display driver");
    }
}

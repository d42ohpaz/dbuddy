#include <stdexcept>

#include "hal.h"

using namespace dbuddy;

void Hal::run(bool use_dbl_buff, lv_indev_type_t type) {
    initializeDisplay(use_dbl_buff);
    initializeInputDevice(type);
}

void Hal::initializeDisplay(bool use_dbl_buff) {
    static lv_color_t buffer0[BUFFER_SIZE];
    static lv_color_t buffer1[BUFFER_SIZE];
    lv_disp_buf_init(display_buffer, buffer0, buffer1, BUFFER_SIZE);

    lv_disp_drv_init(display_driver);

    // Make the instance available for our c-callback above.
    display_driver->user_data = this;

    display_driver->flush_cb = [](lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color) {
        auto * instance = (Hal *)drv->user_data;
        instance->display_flush(drv, area, color);
    };

    display_driver->buffer = display_buffer;

    if (!lv_disp_drv_register(display_driver)) {
        throw std::runtime_error("Unable to register the display driver");
    }
}

void Hal::initializeInputDevice(lv_indev_type_t type) {
    lv_indev_drv_init(input_device_driver);

    // Make the instance available for our c-callback above.
    input_device_driver->user_data = this;

    input_device_driver->type = type;
    input_device_driver->read_cb = [](lv_indev_drv_t * drv, lv_indev_data_t * data) {
        auto * instance = (Hal *)drv->user_data;
        return instance->input_read(drv, data);
    };

    if (!lv_indev_drv_register(input_device_driver)) {
        throw std::runtime_error("Unable to register the input driver");
    }
}

#if defined(ARDUINO)
#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>

#include "nodemcu32s.h"

using namespace dbuddy;

void NodeMCU32s::init() {
    tft->begin(RA8875_800x480);
    tft->GPIOX(true);
    tft->displayOn(true);
    tft->touchEnable(true);
    tft->PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
    tft->PWM1out(255);

    pinMode(interrupt, INPUT);
    digitalWrite(interrupt, HIGH);

#if defined(ESP32)
    analogReadResolution(10);
#endif
}

void NodeMCU32s::display_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color) {
    int32_t width = (area->x2 - area->x1 + 1);

    tft->startWrite();
    for (int y = area->y1; y <= area->y2; y++) {
        // https://forum.lvgl.io/t/nodemcu-32s-ra8875-rendering-advice/4300/5?u=9ae8sdf76
        tft->drawPixels((uint16_t *)color, width, area->x1, y);
        color += width;
    }
    tft->endWrite();

    lv_disp_flush_ready(disp);
}

bool NodeMCU32s::input_read(lv_indev_drv_t * drv, lv_indev_data_t * data) {
    static int last_x = 0, last_y = 0;
    bool valid = true;

    TSPoint point = ts->getPoint();

    if (point.z > ts->pressureThreshhold) {
        last_x = point.x;
        last_y = point.y;

        Serial.printf("X: %d; Y: %d; Z: %d\n", point.x, point.y, point.z);
    } else {
        point.x = last_x;
        point.y = last_y;
        valid = false;
    }

    data->point.x = point.x;
    data->point.y = point.y;
    data->state = valid ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;

    return false;
}

NodeMCU32s::NodeMCU32s(Adafruit_RA8875 * tft, TouchScreen * ts, uint8_t interrupt) : Hal(), tft(tft), ts(ts), interrupt(interrupt) {}
#endif

#include <SPI.h>
#include <Wire.h>

#include <utility>

#include "nodemcu32s.h"

using namespace DBuddy;

void NodeMCU32s::init() {
    Serial.begin(115200);

    tft->begin(RA8875_800x480);
    tft->displayOn(true);
    tft->touchEnable(true);
    tft->PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
    tft->PWM1out(255);

    pinMode(interrupt, INPUT);
    digitalWrite(interrupt, HIGH);;
}

void NodeMCU32s::flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color) {
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

NodeMCU32s::NodeMCU32s(Adafruit_RA8875 * tft, uint8_t interrupt) : Hal(), tft(tft), interrupt(interrupt) {}

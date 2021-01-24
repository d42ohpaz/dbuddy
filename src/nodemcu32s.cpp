#include <SPI.h>
#include <Wire.h>

#include <utility>

#include "nodemcu32s.h"

void DBuddy::NodeMCU32s::init() {
    tft.begin(RA8875_800x480);
    tft.GPIOX(true);
    tft.displayOn(true);
    tft.touchEnable(true);
    tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
    tft.PWM1out(255);

    pinMode(interrupt, INPUT);
    digitalWrite(interrupt, HIGH);;
}

void DBuddy::NodeMCU32s::flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color) {
    int32_t row_count = (area->x2 - area->x1 + 1);
    Serial.printf("Begin flushing to display for row count: %u\n", row_count);

    Serial.println("Drawing pixels to display");
    for (int y = area->y1; y <= area->y2; y++) {
        // https://forum.lvgl.io/t/nodemcu-32s-ra8875-rendering-advice/4300/5?u=9ae8sdf76
        tft.drawPixels((uint16_t *)color, row_count, area->x1, y);
        color += row_count;
    }

    Serial.println("Flushing the display");
    lv_disp_flush_ready(disp);
}

DBuddy::NodeMCU32s::NodeMCU32s(Adafruit_RA8875 tft, uint8_t interrupt) : Hal(), tft(std::move(tft)), interrupt(interrupt) {}

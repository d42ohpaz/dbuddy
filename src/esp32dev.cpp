#if defined(ARDUINO)

#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <ezTime.h>

#include "esp32dev.h"

using namespace dbuddy;


void ESP32Dev::init() {
    tft->begin(RA8875_800x480);
    tft->GPIOX(true);
    tft->displayOn(true);
    tft->touchEnable(true);
    tft->PWM1config(true, RA8875_PWM_CLK_DIV2); // PWM output for backlight
    tft->PWM1out(255);

    pinMode(interrupt, INPUT);
    digitalWrite(interrupt, HIGH);

#if defined(ESP32)
    analogReadResolution(10);

    // Start the NTP queries and update the RTC.
    if (!rtc->begin()) {
        Serial.print("Unable to communicate with the RTC");
        return;
    }

    if (WiFi.isConnected()) {
        setServer("time.nist.gov");
        setInterval(3600);

        Timezone tz;
        tz.setLocation("America/New_York");

        if (waitForSync()) {
            RTC_DS3231::adjust(DateTime(tz.now()));
        }
    }
#endif
}

void ESP32Dev::display_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color) {
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

bool ESP32Dev::input_read(lv_indev_drv_t * drv, lv_indev_data_t * data) {
    return false;
}

int ESP32Dev::get_year() const {
    DateTime dtime = RTC_DS3231::now();
    return dtime.year();
}

int ESP32Dev::get_month() const {
    DateTime dtime = RTC_DS3231::now();
    return dtime.month();
}

int ESP32Dev::get_day() const {
    DateTime dtime = RTC_DS3231::now();
    return dtime.day();
}

int ESP32Dev::get_hours() const {
    DateTime dtime = RTC_DS3231::now();
    return dtime.hour();
}

int ESP32Dev::get_minutes() const {
    DateTime dtime = RTC_DS3231::now();
    return dtime.minute();
}

int ESP32Dev::get_seconds() const {
    DateTime dtime = RTC_DS3231::now();
    return dtime.second();
}
#endif

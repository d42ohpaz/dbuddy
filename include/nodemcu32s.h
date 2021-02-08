#ifndef DBUDDY_NODEMCU32S_H
#define DBUDDY_NODEMCU32S_H

#include <Adafruit_RA8875.h>
#include <TouchScreen.h>
#include <ezTime.h>
#include <WiFiUdp.h>
#include <RTClib.h>

#include "hal.h"

namespace dbuddy {
    class NodeMCU32s : public Hal {
    public:
        NodeMCU32s(Adafruit_RA8875 * tft, TouchScreen * ts, uint8_t interrupt) : Hal(), tft(tft), ts(ts), interrupt(interrupt) {}

        void init() final;

        void display_flush(lv_disp_drv_t *, const lv_area_t *, lv_color_t *) final;
        bool input_read(lv_indev_drv_t *, lv_indev_data_t *) final;

        int get_year() const final;
        int get_month() const final;
        int get_day() const final;
        int get_hours() const final;
        int get_minutes() const final;
        int get_seconds() const final;

        RTC_DS3231 * get_rtc() const { return rtc; }
    private:
        Adafruit_RA8875 * tft;
        TouchScreen * ts;

        uint8_t interrupt;

        RTC_DS3231 * rtc = new RTC_DS3231();
        WiFiUDP * wiFiUdp = new WiFiUDP();
    };
}

#endif //DBUDDY_NODEMCU32S_H

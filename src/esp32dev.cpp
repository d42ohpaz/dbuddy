#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <ezTime.h>

#include "esp32dev.h"
#include "config.h"

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

    analogReadResolution(10);

    // Start the NTP queries and update the RTC.
    if (!rtc->begin()) {
        Serial.print("Unable to communicate with the RTC");
        return;
    }

    DEBUG_MODE = true;

    configManager->setAPName("Desk Buddy Setup");
    configManager->setAPFilename("/index.html");

    configManager->addParameter("timeserver", config_t.timeserver, sizeof(config_t.timeserver));
    configManager->addParameter("update_interval", &config_t.timeinterval);
    configManager->addParameter("timezone", config_t.timezone, sizeof(config_t.timezone));

    configManager->addParameter("calendar_1_color", config_t.calendar1_color, sizeof(config_t.calendar1_color));
    configManager->addParameter("calendar_1_name", config_t.calendar1_name, sizeof(config_t.calendar1_name));
    configManager->addParameter("calendar_1_url", config_t.calendar1_url, sizeof(config_t.calendar1_url));

    configManager->addParameter("calendar_2_color", config_t.calendar2_color, sizeof(config_t.calendar2_color));
    configManager->addParameter("calendar_2_name", config_t.calendar2_name, sizeof(config_t.calendar2_name));
    configManager->addParameter("calendar_2_url", config_t.calendar2_url, sizeof(config_t.calendar2_url));

    configManager->addParameter("calendar_3_color", config_t.calendar3_color, sizeof(config_t.calendar3_color));
    configManager->addParameter("calendar_3_name", config_t.calendar3_name, sizeof(config_t.calendar3_name));
    configManager->addParameter("calendar_3_url", config_t.calendar3_url, sizeof(config_t.calendar3_url));

    configManager->addParameter("calendar_4_color", config_t.calendar4_color, sizeof(config_t.calendar4_color));
    configManager->addParameter("calendar_4_name", config_t.calendar4_name, sizeof(config_t.calendar4_name));
    configManager->addParameter("calendar_4_url", config_t.calendar4_url, sizeof(config_t.calendar4_url));

    configManager->addParameter("calendar_5_color", config_t.calendar5_color, sizeof(config_t.calendar5_color));
    configManager->addParameter("calendar_5_name", config_t.calendar5_name, sizeof(config_t.calendar5_name));
    configManager->addParameter("calendar_5_url", config_t.calendar5_url, sizeof(config_t.calendar5_url));

    configManager->addParameter("calendar_6_color", config_t.calendar6_color, sizeof(config_t.calendar6_color));
    configManager->addParameter("calendar_6_name", config_t.calendar6_name, sizeof(config_t.calendar6_name));
    configManager->addParameter("calendar_6_url", config_t.calendar6_url, sizeof(config_t.calendar6_url));

    configManager->addParameter("calendar_7_color", config_t.calendar7_color, sizeof(config_t.calendar7_color));
    configManager->addParameter("calendar_7_name", config_t.calendar7_name, sizeof(config_t.calendar7_name));
    configManager->addParameter("calendar_7_url", config_t.calendar7_url, sizeof(config_t.calendar7_url));

    configManager->addParameter("calendar_8_color", config_t.calendar8_color, sizeof(config_t.calendar8_color));
    configManager->addParameter("calendar_8_name", config_t.calendar8_name, sizeof(config_t.calendar8_name));
    configManager->addParameter("calendar_8_url", config_t.calendar8_url, sizeof(config_t.calendar8_url));

    configManager->addParameter("version", &meta_t.version, get);

    configManager->setWebPort(80);
    configManager->setAPICallback([this](WebServer * server) {
        server->on("/styles.css", HTTPMethod::HTTP_GET, [this]() {
            this->configManager->streamFile("/styles.css", mimeCSS);
            DebugPrintln("Streamed file");
        });
    });

    configManager->begin(config_t);

    // Set sane defaults for the timeserver and timezone.
    if (meta_t.version == 0) {
        DebugPrintln("Setting the default time server");
        strncpy(config_t.timeserver, CONFIG_DEFAULT_TIMESERVER, CONFIG_DEFAULT_TIMESERVER_LENGTH);
    }

    if (meta_t.version == 0) {
        DebugPrintln("Setting the default timezone");
        strncpy(config_t.timezone, CONFIG_DEFAULT_TIMEZONE, CONFIG_DEFAULT_TIMEZONE_LENGTH);
    }

    if (meta_t.version == 0) {
        DebugPrintln("Saving the initial defaults for the configuration.");
        meta_t.version = 1;
        configManager->save();
    }

    if (WiFi.isConnected()) {
        setServer(config_t.timeserver);
        setInterval(config_t.timeinterval);

        Timezone tz;
        tz.setLocation(config_t.timezone);

        if (waitForSync()) {
            RTC_DS3231::adjust(DateTime(tz.now()));
        }
    }
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

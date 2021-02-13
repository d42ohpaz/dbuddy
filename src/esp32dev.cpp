#if defined(ARDUINO)

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

#if defined(ESP32)
    analogReadResolution(10);

    // Start the NTP queries and update the RTC.
    if (!rtc->begin()) {
        Serial.print("Unable to communicate with the RTC");
        return;
    }

    DEBUG_MODE = true;

    configManager->setAPName("Desk Buddy Setup");
    configManager->setAPFilename("/index.html");

    configManager->addParameter("timeserver", config.timeserver, sizeof(config.timeserver));
    configManager->addParameter("update_interval", &config.timeinterval);
    configManager->addParameter("timezone", config.timezone, sizeof(config.timezone));

    configManager->addParameter("calendar_1_color", config.calendar1_color, sizeof(config.calendar1_color));
    configManager->addParameter("calendar_1_name", config.calendar1_name, sizeof(config.calendar1_name));
    configManager->addParameter("calendar_1_url", config.calendar1_url, sizeof(config.calendar1_url));

    configManager->addParameter("calendar_2_color", config.calendar2_color, sizeof(config.calendar2_color));
    configManager->addParameter("calendar_2_name", config.calendar2_name, sizeof(config.calendar2_name));
    configManager->addParameter("calendar_2_url", config.calendar2_url, sizeof(config.calendar2_url));

    configManager->addParameter("calendar_3_color", config.calendar3_color, sizeof(config.calendar3_color));
    configManager->addParameter("calendar_3_name", config.calendar3_name, sizeof(config.calendar3_name));
    configManager->addParameter("calendar_3_url", config.calendar3_url, sizeof(config.calendar3_url));

    configManager->addParameter("calendar_4_color", config.calendar4_color, sizeof(config.calendar4_color));
    configManager->addParameter("calendar_4_name", config.calendar4_name, sizeof(config.calendar4_name));
    configManager->addParameter("calendar_4_url", config.calendar4_url, sizeof(config.calendar4_url));

    configManager->addParameter("calendar_5_color", config.calendar5_color, sizeof(config.calendar5_color));
    configManager->addParameter("calendar_5_name", config.calendar5_name, sizeof(config.calendar5_name));
    configManager->addParameter("calendar_5_url", config.calendar5_url, sizeof(config.calendar5_url));

    configManager->addParameter("calendar_6_color", config.calendar6_color, sizeof(config.calendar6_color));
    configManager->addParameter("calendar_6_name", config.calendar6_name, sizeof(config.calendar6_name));
    configManager->addParameter("calendar_6_url", config.calendar6_url, sizeof(config.calendar6_url));

    configManager->addParameter("calendar_7_color", config.calendar7_color, sizeof(config.calendar7_color));
    configManager->addParameter("calendar_7_name", config.calendar7_name, sizeof(config.calendar7_name));
    configManager->addParameter("calendar_7_url", config.calendar7_url, sizeof(config.calendar7_url));

    configManager->addParameter("calendar_8_color", config.calendar8_color, sizeof(config.calendar8_color));
    configManager->addParameter("calendar_8_name", config.calendar8_name, sizeof(config.calendar8_name));
    configManager->addParameter("calendar_8_url", config.calendar8_url, sizeof(config.calendar8_url));

    configManager->addParameter("version", &meta.version, get);

    configManager->setWebPort(80);
    configManager->setAPICallback([this](WebServer * server) {
        server->on("/styles.css", HTTPMethod::HTTP_GET, [this]() {
            this->configManager->streamFile("/styles.css", mimeCSS);
            DebugPrintln("Streamed file");
        });
    });

    configManager->begin(config);

    // Set sane defaults for the timeserver and timezone.
    if (meta.version == 0) {
        DebugPrintln("Setting the default time server");
        strncpy(config.timeserver, CONFIG_DEFAULT_TIMESERVER, CONFIG_DEFAULT_TIMESERVER_LENGTH);
    }

    if (meta.version == 0) {
        DebugPrintln("Setting the default timezone");
        strncpy(config.timezone, CONFIG_DEFAULT_TIMEZONE, CONFIG_DEFAULT_TIMEZONE_LENGTH);
    }

    if (meta.version == 0) {
        DebugPrintln("Saving the initial defaults for the configuration.");
        meta.version = 1;
        configManager->save();
    }

    if (WiFi.isConnected()) {
        setServer(config.timeserver);
        setInterval(config.timeinterval);

        Timezone tz;
        tz.setLocation(config.timezone);

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

#include <Arduino.h>
#include <lvgl.h>

#include "dbuddy.h"

void DBuddy::DBuddy::setup(Hal * hal, bool use_dbl_buff) {
    Serial.begin(115200);

    auto * db = new DBuddy(hal);

    Serial.println("Initializing DBuddy");
    db->init(use_dbl_buff);
    Serial.println("DBuddy Initialized");
}

void DBuddy::DBuddy::loop() {
    lv_task_handler();
    delay(5);
}

DBuddy::DBuddy::DBuddy(Hal * hal) : hal(hal) {};
DBuddy::DBuddy::~DBuddy() {
    delete ui;
}


void DBuddy::DBuddy::init(bool use_dbl_buff) {
    Serial.println("Initializing LVGL");
    lv_init();

    Serial.println("Running HAL");
    hal->run(use_dbl_buff);

    Serial.println("Initializing UI");
    ui->init();
}

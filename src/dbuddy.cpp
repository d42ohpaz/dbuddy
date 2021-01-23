#include <Arduino.h>
#include <lvgl.h>

#include "dbuddy.h"

void DBuddy::DBuddy::setup() {
    __unused auto * db = new DBuddy;
    lv_init();
}

void DBuddy::DBuddy::loop() {
    lv_task_handler();
    delay(5);
}

DBuddy::DBuddy::DBuddy() {
    ui->init();
}

DBuddy::DBuddy::~DBuddy() {
    delete ui;
}

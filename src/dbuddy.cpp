#include <Arduino.h>
#include <lvgl.h>

#include "dbuddy.h"

void DBuddy::DBuddy::setup(Hal * hal, bool use_dbl_buff) {
    auto * db = new DBuddy(hal);
    db->init(use_dbl_buff);
}

void DBuddy::DBuddy::loop() {
    lv_task_handler();
    delay(5);
}

DBuddy::DBuddy::DBuddy(Hal * hal) : hal(hal) {};
DBuddy::DBuddy::~DBuddy() {
    delete hal;
    delete ui;
}


void DBuddy::DBuddy::init(bool use_dbl_buff) {
    lv_init();

    hal->run(use_dbl_buff);
    ui->init();
}

#include <Arduino.h>
#include <lvgl.h>

#include "dbuddy.h"

void dbuddy::DBuddy::setup(Hal * hal, Ui * ui, bool use_dbl_buff) {
    auto * db = new DBuddy(hal, ui);
    db->init(use_dbl_buff);
}

void dbuddy::DBuddy::loop() {
    lv_task_handler();
    delay(5);
}

dbuddy::DBuddy::DBuddy(Hal * hal, Ui * ui) : ui(ui), hal(hal) {};
dbuddy::DBuddy::~DBuddy() {
    delete hal;
    delete ui;
}


void dbuddy::DBuddy::init(bool use_dbl_buff) {
    lv_init();

    hal->init();
    hal->run(use_dbl_buff);

    ui->init();
}

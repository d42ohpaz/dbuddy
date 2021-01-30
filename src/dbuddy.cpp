#include <Arduino.h>
#include <lvgl.h>

#include "dbuddy.h"
#include "widgets.h"

using namespace dbuddy;

void DBuddy::setup(Hal * hal, Ui * ui, bool use_dbl_buff) {
    auto * db = new DBuddy(hal, ui);
    db->init(use_dbl_buff);
}

void DBuddy::loop() {
    lv_task_handler();
    delay(5);
}

DBuddy::DBuddy(Hal * hal, Ui * ui) : ui(ui), hal(hal) {};
DBuddy::~DBuddy() {
    delete hal;
    delete ui;
}


void DBuddy::init(bool use_dbl_buff) {
    hal->init();
    hal->run(use_dbl_buff);

    ui->add_widget(WIDGET_SCREEN, new Screen(ui));
    ui->add_widget(WIDGET_PAGE, new Page(ui));
    ui->add_widget(WIDGET_MENU, new Menu(ui));
    ui->add_widget(WIDGET_TIME_CONTAINER, new TimeContainer(ui));
    ui->add_widget(WIDGET_TIME_LABEL, new TimeLabel(ui));
    ui->add_widget(WIDGET_ACTIONS_CONTAINER, new ActionsContainer(ui));

    ui->init();
}

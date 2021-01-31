#include <lvgl.h>
#include <unistd.h>
#include <ctime>

#include "dbuddy.h"
#include "widgets.h"

using namespace dbuddy;

extern "C" void cb_time_task_handler(lv_task_t * task) {
    auto * db = (DBuddy *)task->user_data;
    db->updateTimeCallback(task);
}

void DBuddy::setup(Hal * hal, Ui * ui, bool use_dbl_buff) {
    auto * db = new DBuddy(hal, ui);
    db->init(use_dbl_buff);
}

void DBuddy::loop() {
    lv_task_handler();
    usleep(5);
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

    lv_task_create(cb_time_task_handler, 500, LV_TASK_PRIO_MID, this);
}

void DBuddy::updateTimeCallback(lv_task_t * task) const {
    (void)task;

    time_t t = time(nullptr);
    struct tm local = *localtime(&t);
    char bufMeridiem[3] = "";
    int tmHour = local.tm_hour;

//    if (p_config->time.format24 == 0) {
//        if (p_config->time.meridiem == 1) {
//            if (local.tm_hour >= 12) {
//                sprintf(bufMeridiem, "%s", "pm");
//            } else {
//                sprintf(bufMeridiem, "%s", "am");
//            }
//        }
//
//        if (tmHour > 12) {
//            tmHour = tmHour - 12;
//        }
//    }

    lv_obj_t * time_label = ui->get_widget(WIDGET_TIME_LABEL)->get_self();

    static int count_on = 0, count_off = 0;
    char * colon = strstr(lv_label_get_text(time_label), ":");

    if (((count_on % 2) == 0 && colon == nullptr)/* || (p_config->time.flash == 0)*/) {
        lv_label_set_text_fmt(time_label, "%02u:%02u %s", tmHour, local.tm_min, bufMeridiem);
        count_on = 0;
    } else if ((count_off % 2) == 0) {
        lv_label_set_text_fmt(time_label, "%02u %02u %s", tmHour, local.tm_min, bufMeridiem);
        count_off = 0;
    }

    count_off++;
    count_on++;
}

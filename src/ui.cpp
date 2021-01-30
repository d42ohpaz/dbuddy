#include <Arduino.h>
#include <lvgl.h>
#include <ctime>

#include "ui.h"

using namespace dbuddy;

static Ui * instance;

extern "C" void cb_time_task_handler(lv_task_t * task) { instance->updateTimeCallback(task); }

void Ui::init() {
    instance = this;

    lv_task_create(cb_time_task_handler, 500, LV_TASK_PRIO_MID, nullptr);
}

void Ui::add_widget(widget_t w, Widget * widget) {
    if (widgets.find(w) == widgets.end()) {
        widgets[w] = widget;
        widget->init();
    }
}

Widget * Ui::get_widget(widget_t widget) const {
    return widgets.at(widget);
}

void Ui::updateTimeCallback(lv_task_t * task) const {
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

    lv_obj_t * time_label = get_widget(WIDGET_TIME_LABEL)->get_self();

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

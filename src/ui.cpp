#include <lvgl.h>
#include <ctime>

#include "ui.h"
#include "fonts.h"
#include "styles.h"

using namespace dbuddy;

static Ui * instance;

extern "C" void cb_time_task_handler(lv_task_t * task) { instance->updateTimeCallback(task); }

Ui::~Ui() {
    delete display;

    delete screen;
    delete page;
    delete menu;
    delete timeLabel;
    delete timeContainer;
};

void Ui::init() {
    instance = this;

    auto * fonts = new Fonts;
    auto * styles = new Styles;

    display = lv_disp_get_default();

    screen = new Widgets::Screen(nullptr, nullptr);
    screen->init(fonts, styles);

    page = new Widgets::Page(screen->get_self(), nullptr);
    page->init(fonts, styles);

    menu = new Widgets::Menu(page->get_self(), nullptr);
    menu->init(fonts, styles);

    timeContainer = new Widgets::TimeContainer(menu->get_self(), nullptr);
    timeContainer->init(fonts, styles);

    timeLabel = new Widgets::TimeLabel(timeContainer->get_self(), nullptr);
    timeLabel->init(fonts, styles);

    actionsContainer = new Widgets::ActionsContainer(menu->get_self(), nullptr);
    actionsContainer->init(fonts, styles);

    lv_task_create(cb_time_task_handler, 500, LV_TASK_PRIO_MID, nullptr);
}

void Ui::updateTimeCallback(lv_task_t * task) {
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

    static int count_on = 0, count_off = 0;
    char * colon = strstr(lv_label_get_text(timeLabel->get_self()), ":");

    if (((count_on % 2) == 0 && colon == nullptr)/* || (p_config->time.flash == 0)*/) {
        lv_label_set_text_fmt(timeLabel->get_self(), "%02u:%02u %s", tmHour, local.tm_min, bufMeridiem);
        count_on = 0;
    } else if ((count_off % 2) == 0) {
        lv_label_set_text_fmt(timeLabel->get_self(), "%02u %02u %s", tmHour, local.tm_min, bufMeridiem);
        count_off = 0;
    }

    count_off++;
    count_on++;
}

#include <lvgl.h>
#include <unistd.h>
#include <cstdio>

#if defined(ARDUINO)
#include <Arduino.h>
#include <WiFi.h>
#endif

#include "dbuddy.h"
#include "widgets.h"

using namespace dbuddy;

extern "C" void cb_time_task_handler(lv_task_t * task);

#if LV_MEM_CUSTOM == 0
extern "C" void cb_memory_monitor_task_handler(lv_task_t * param);
#endif

#if defined(ARDUINO)
extern "C" void cb_wifi_task_handler(lv_task_t * param);
#endif

void DBuddy::setup(Hal * hal, Ui * ui, bool use_dbl_buff, lv_indev_type_t input_type) {
    auto * db = new DBuddy(hal, ui);

    db->init(use_dbl_buff, input_type);
}

void DBuddy::loop() {
    lv_task_handler();
    usleep(5000);
}

void DBuddy::init(bool use_dbl_buff, lv_indev_type_t input_type) {
    hal->init();
    hal->run(use_dbl_buff, input_type);

    ui->add_widget(WIDGET_SCREEN, new Screen(ui));
    ui->add_widget(WIDGET_PAGE, new Page(ui));
    ui->add_widget(WIDGET_MENU, new Menu(ui));
    ui->add_widget(WIDGET_TIME_CONTAINER, new TimeContainer(ui));
    ui->add_widget(WIDGET_TIME_LABEL, new TimeLabel(ui));
    ui->add_widget(WIDGET_ACTIONS_CONTAINER, new ActionsContainer(ui));
    ui->add_widget(WIDGET_ACTION_SETTINGS, new ActionSettings(ui));
    ui->add_widget(WIDGET_CALENDAR_DATE, new CalendarDate(ui));
    ui->add_widget(WIDGET_CALENDAR_DETAILS, new CalendarDetails(ui));
    ui->add_widget(WIDGET_CALENDAR, new Calendar(ui));
    ui->add_widget(WIDGET_WIFI_SIGNAL, new WifiSignal(ui));

    ui->create_task(cb_time_task_handler, 500, LV_TASK_PRIO_MID, this);
#if LV_MEM_CUSTOM == 0
    ui->create_task(cb_memory_monitor_task_handler, 5000);
#endif
#if defined(ARDUINO)
    ui->create_task(cb_wifi_task_handler, 500);
#endif

    initializeCalendar();
}

void DBuddy::initializeCalendar() {
    lv_calendar_date_t today;
    today.year = hal->get_year();
    today.month = hal->get_month();
    today.day = hal->get_day();

    auto * calendar = (Calendar *) ui->get_widget(WIDGET_CALENDAR);
    calendar->set_today(&today);
    calendar->set_showed(&today);
}

void cb_time_task_handler(lv_task_t * task) {
    auto * db = (DBuddy *) task->user_data;
    Hal * hal = db->get_hal();
    Ui * ui = db->get_ui();

    char bufMeridiem[3] = "";
    int tmHour = hal->get_hours();

//    if (p_config->time.format24 == 0) {
//        if (p_config->time.meridiem == 1) {
    if (tmHour >= 12) {
        sprintf(bufMeridiem, "%s", "pm");
    } else {
        sprintf(bufMeridiem, "%s", "am");
    }
//        }
//
    if (tmHour > 12) {
        tmHour -= 12;
    }

    if (tmHour == 0) {
        tmHour += 12;
    }
//    }

    lv_obj_t * time_label = ui->get_widget(WIDGET_TIME_LABEL)->get_self();

    static int count = 0;
    char * colon = strstr(lv_label_get_text(time_label), ":");

    if (((count % 2) == 0 && colon == nullptr)/* || (p_config->time.flash == 0)*/) {
        lv_label_set_text_fmt(time_label, "%02u:%02u %s", tmHour, hal->get_minutes(), bufMeridiem);
        count = 0;
    } else if ((count % 2) == 0) {
        lv_label_set_text_fmt(time_label, "%02u %02u %s", tmHour, hal->get_minutes(), bufMeridiem);
        count = 0;
    }

    ++count;
}

#if defined(ARDUINO)
void cb_wifi_task_handler(lv_task_t * param) {
    auto * ui = (Ui *)param->user_data;
    Widget * wifi_signal = ui->get_widget(WIDGET_WIFI_SIGNAL);

    switch (WiFiClass::status()) {
        case WL_CONNECTED:
            wifi_signal->remove_style(LV_OBJ_PART_MAIN, ui->get_styles()->get_text_color_gray(LV_STATE_DEFAULT));
            wifi_signal->add_style(LV_OBJ_PART_MAIN, ui->get_styles()->get_text_color_white(LV_STATE_DEFAULT));
            break;
        default: // Disconnected, never connected, etc
            wifi_signal->remove_style(LV_OBJ_PART_MAIN, ui->get_styles()->get_text_color_white(LV_STATE_DEFAULT));
            wifi_signal->add_style(LV_OBJ_PART_MAIN, ui->get_styles()->get_text_color_gray(LV_STATE_DEFAULT));
            break;
    }
}
#endif

#if LV_MEM_CUSTOM == 0
/**
 * Print the memory usage periodically
 * @param param
 */
void cb_memory_monitor_task_handler(lv_task_t * param) {
    (void) param; /*Unused*/

    lv_mem_monitor_t mon;
    lv_mem_monitor(&mon);

#if defined(ARDUINO)
    Serial.printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
                  (int) mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
                  (int) mon.free_biggest_size);
#else
    printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
           (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
           (int)mon.free_biggest_size);
#endif
}
#endif

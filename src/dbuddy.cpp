#include <lvgl.h>
#include <unistd.h>
#include <ctime>
#include <cstdio>

#include "dbuddy.h"
#include "widgets.h"

using namespace dbuddy;

extern "C" void cb_time_task_handler(lv_task_t * task) {
    auto * ui = (Ui *)task->user_data;

    time_t t = time(nullptr);
    struct tm local_time = *localtime(&t);

    char bufMeridiem[3] = "";
    int tmHour = local_time.tm_hour;

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
        lv_label_set_text_fmt(time_label, "%02u:%02u %s", tmHour, local_time.tm_min, bufMeridiem);
        count = 0;
    } else if ((count % 2) == 0) {
        lv_label_set_text_fmt(time_label, "%02u %02u %s", tmHour, local_time.tm_min, bufMeridiem);
        count = 0;
    }

    ++count;
}

#if defined(ARDUINO)
#include <Arduino.h>

#if LV_MEM_CUSTOM == 0
extern "C" void cb_memory_monitor_task_handler(lv_task_t *param);
#endif
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

    ui->create_task(cb_time_task_handler, 500);
#if defined(ARDUINO)
#if LV_MEM_CUSTOM == 0
    ui->create_task(cb_memory_monitor_task_handler, 500);
#endif
#endif

    initializeCalendar();
}

void DBuddy::initializeCalendar() {
    time_t t = time(nullptr);
    struct tm local_time = *localtime(&t);

    lv_calendar_date_t today;
    today.year = (local_time.tm_year + 1900);
    today.month = (local_time.tm_mon + 1);
    today.day = local_time.tm_mday;

    auto * calendar = (Calendar *)ui->get_widget(WIDGET_CALENDAR);
    calendar->set_today(&today);
    calendar->set_showed(&today);
}

#if defined(ARDUINO)
#if LV_MEM_CUSTOM == 0
/**
 * Print the memory usage periodically
 * @param param
 */
void cb_memory_monitor_task_handler(lv_task_t *param) {
  (void)param; /*Unused*/

  lv_mem_monitor_t mon;
  lv_mem_monitor(&mon);

#if defined(ARDUINO)
  Serial.printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
#else
  printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
#endif
}
#endif
#endif

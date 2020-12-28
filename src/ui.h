#ifndef DBUDDY_UI_H
#define DBUDDY_UI_H

#include "lvgl/lvgl.h"
#include "configuration.h"

typedef struct ui_top_left_page_t {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * container_month;
    lv_obj_t * container_day;
    lv_obj_t * container_year;

    lv_obj_t * label_day;
    lv_obj_t * label_month;
    lv_obj_t * label_year;
} ui_top_left_page_t;

typedef struct ui_bottom_left_page_t {
    lv_obj_t * main;

    lv_obj_t * itinerary;
} ui_bottom_left_page_t;

typedef struct ui_top_page_t {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * container_time;
    lv_obj_t * container_actions;

    lv_obj_t * label_time;
    lv_obj_t * btn_action_settings;
} ui_top_page_t;

typedef struct ui_left_page_t {
    lv_obj_t * main;

    ui_top_left_page_t top;
    ui_bottom_left_page_t bottom;
} ui_left_page_t;

typedef struct ui_right_page_t {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * calendar;
} ui_right_page_t;

typedef struct ui_settings_general_t {
    lv_obj_t * main;

    lv_obj_t * toggle_format;
    lv_obj_t * toggle_meridiem;
    lv_obj_t * toggle_flash;
    lv_obj_t * toggle_screensaver;
} ui_settings_general_t;

typedef struct ui_settings_calendars_t {
    lv_obj_t * main;
} ui_settings_calendars_t;

typedef struct ui_settings_t {
    lv_obj_t * main;
    lv_obj_t * overlay;
    lv_obj_t * list;
    lv_obj_t * msgbox;
    lv_obj_t * btn_close;
    lv_obj_t * action_btns;

    lv_coord_t header_offset;
    configuration config;

    union {
        ui_settings_general_t general;
        ui_settings_calendars_t calendars;
    };
} ui_settings_t;

typedef struct ui_page_t {
    lv_obj_t * main;

    ui_top_page_t top;
    ui_left_page_t left;
    ui_right_page_t right;
} ui_page_t;

typedef struct ui_t {
    lv_disp_t * display;
    lv_obj_t * screen;

    ui_page_t page;

    ui_settings_t settings;

    lv_calendar_date_t date;
} ui_t;

void ui_init(void);

#endif //DBUDDY_UI_H

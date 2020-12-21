#ifndef DBUDDY_UI_H
#define DBUDDY_UI_H

#include "lvgl/lvgl.h"

struct ui_bottom_left_page_t;
struct ui_left_page_t;
struct ui_page_t;
struct ui_right_page_t;
struct ui_t;
struct ui_top_left_page_t;
struct ui_top_page_t;

typedef struct ui_bottom_left_page_t ui_bottom_left_page_t;
typedef struct ui_left_page_t ui_left_page_t;
typedef struct ui_page_t ui_page_t;
typedef struct ui_right_page_t ui_right_page_t;
typedef struct ui_t ui_t;
typedef struct ui_top_left_page_t ui_top_left_page_t;
typedef struct ui_top_page_t ui_top_page_t;

struct ui_top_left_page_t {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * container_month;
    lv_obj_t * container_day;
    lv_obj_t * container_year;

    lv_obj_t * label_day;
    lv_obj_t * label_month;
    lv_obj_t * label_year;
};

struct ui_bottom_left_page_t {
    lv_obj_t * main;

    lv_obj_t * itinerary;
};

struct ui_top_page_t {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * container_time;
    lv_obj_t * container_actions;

    lv_obj_t * label_time;
    lv_obj_t * btn_action_settings;
};

struct ui_left_page_t {
    lv_obj_t * main;

    ui_top_left_page_t top;
    ui_bottom_left_page_t bottom;
};

struct ui_right_page_t {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * calendar;
};

struct ui_page_t {
    lv_obj_t * main;

    ui_top_page_t top;
    ui_left_page_t left;
    ui_right_page_t right;
};

struct ui_t {
    lv_disp_t * display;
    lv_obj_t * screen;

    ui_page_t page;

    lv_calendar_date_t date;
};

ui_t * ui_init(void);

#endif //DBUDDY_UI_H

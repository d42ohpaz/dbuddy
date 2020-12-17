#ifndef DBUDDY_UI_H
#define DBUDDY_UI_H

#include "lvgl/lvgl.h"

typedef struct {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * label_day;
    lv_obj_t * label_month;
    lv_obj_t * label_year;
} TopLeftPageUi;

typedef struct {
    lv_obj_t * main;

    lv_obj_t * itinerary;
} BottomLeftPageUi;

typedef struct {
    lv_obj_t * main;

    TopLeftPageUi top;
    BottomLeftPageUi bottom;
} LeftPageUi;

typedef struct {
    lv_obj_t * main;

    lv_obj_t * calendar;
} RightPageUi;

typedef struct {
    lv_obj_t * main;

    LeftPageUi left;
    RightPageUi right;
} PageUi;

typedef struct {
    lv_disp_t * display;
    lv_obj_t * screen;

    PageUi page;
} Ui;

Ui * ui_init(void);

#endif //DBUDDY_UI_H

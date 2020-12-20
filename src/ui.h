#ifndef DBUDDY_UI_H
#define DBUDDY_UI_H

#include "lvgl/lvgl.h"

struct BottomLeftPageUi;
struct LeftPageUi;
struct PageUi;
struct RightPageUi;
struct TopLeftPageUi;
struct TopPageUi;
struct Ui;

typedef struct BottomLeftPageUi BottomLeftPageUi;
typedef struct LeftPageUi LeftPageUi;
typedef struct PageUi PageUi;
typedef struct RightPageUi RightPageUi;
typedef struct TopLeftPageUi TopLeftPageUi;
typedef struct TopPageUi TopPageUi;
typedef struct Ui Ui;

struct TopLeftPageUi {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * container_month;
    lv_obj_t * container_day;
    lv_obj_t * container_year;

    lv_obj_t * label_day;
    lv_obj_t * label_month;
    lv_obj_t * label_year;
};

struct BottomLeftPageUi {
    lv_obj_t * main;

    lv_obj_t * itinerary;
};

struct TopPageUi {
    lv_obj_t * main;
    lv_obj_t * container;
};

struct LeftPageUi {
    lv_obj_t * main;

    TopLeftPageUi top;
    BottomLeftPageUi bottom;
};

struct RightPageUi {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * calendar;
};

struct PageUi {
    lv_obj_t * main;

    TopPageUi top;
    LeftPageUi left;
    RightPageUi right;
};

struct Ui {
    lv_disp_t * display;
    lv_obj_t * screen;

    PageUi page;

    lv_calendar_date_t date;
};

Ui * ui_init(void);

#endif //DBUDDY_UI_H

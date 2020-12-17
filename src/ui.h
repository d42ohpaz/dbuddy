#ifndef DBUDDY_UI_H
#define DBUDDY_UI_H

#include "lvgl/lvgl.h"

struct BottomLeftPageUi;
struct LeftPageUi;
struct PageUi;
struct RightPageUi;
struct TopLeftPageUi;
struct Ui;

typedef struct BottomLeftPageUi BottomLeftPageUi;
typedef struct LeftPageUi LeftPageUi;
typedef struct PageUi PageUi;
typedef struct RightPageUi RightPageUi;
typedef struct TopLeftPageUi TopLeftPageUi;
typedef struct Ui Ui;

struct TopLeftPageUi {
    lv_obj_t * main;
    lv_obj_t * container;

    lv_obj_t * label_day;
    lv_obj_t * label_month;
    lv_obj_t * label_year;
};

struct BottomLeftPageUi {
    lv_obj_t * main;

    lv_obj_t * itinerary;
};

struct LeftPageUi {
    lv_obj_t * main;

    TopLeftPageUi top;
    BottomLeftPageUi bottom;
};

struct RightPageUi {
    lv_obj_t * main;

    lv_obj_t * calendar;
};

struct PageUi {
    lv_obj_t * main;

    LeftPageUi left;
    RightPageUi right;
};

struct Ui {
    lv_disp_t * display;
    lv_obj_t * screen;

    PageUi page;
};

Ui * ui_init(void);

#endif //DBUDDY_UI_H

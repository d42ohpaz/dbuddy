#ifndef DBUDDY_UI_WIDGETS_H
#define DBUDDY_UI_WIDGETS_H

#include <lvgl.h>

struct MenuWidget {
    lv_obj_t * self = new lv_obj_t;
    lv_obj_t * container = new lv_obj_t;

    lv_obj_t * container_time = new lv_obj_t;
    lv_obj_t * label_time = new lv_obj_t;

    lv_obj_t * container_actions = new lv_obj_t;
    lv_obj_t * btn_settings = new lv_obj_t;
};

struct DockDateWidget {
    lv_obj_t * self = new lv_obj_t;

    lv_obj_t * container_month = new lv_obj_t;
    lv_obj_t * label_month = new lv_obj_t;

    lv_obj_t * container_day = new lv_obj_t;
    lv_obj_t * label_day = new lv_obj_t;

    lv_obj_t * container_year = new lv_obj_t;
    lv_obj_t * label_year = new lv_obj_t;
};

struct DockEventsWidget {
    lv_obj_t * self = new lv_obj_t;
    lv_obj_t * itinerary = new lv_obj_t;
};

struct DockWidget {
    lv_obj_t * self = new lv_obj_t;

    DockDateWidget * date = new DockDateWidget;
    DockEventsWidget * events = new DockEventsWidget;
};

struct CalendarWidget {
    lv_obj_t * self = new lv_obj_t;
    lv_obj_t * container = new lv_obj_t;
};

struct PageWidget {
    lv_obj_t * self = new lv_obj_t;

    MenuWidget * menu = new MenuWidget;
    DockWidget * dock = new DockWidget;
    CalendarWidget * calendar = new CalendarWidget;
};

#endif // DBUDDY_UI_WIDGETS_H

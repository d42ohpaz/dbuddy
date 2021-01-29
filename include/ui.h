#ifndef DBUDDY_UI_H
#define DBUDDY_UI_H

#include <lvgl.h>

#include "widget.h"
#include "widgets.h"

namespace dbuddy {
    class Ui {
    public:
        void init();

        void add_widget(widget_t w, Widget * widget);
        Widget * get_widget(widget_t) const;

        void updateTimeCallback(lv_task_t * task) const;
    private:
        std::map<widget_t, Widget *> widgets;
    };
}

#endif //DBUDDY_UI_H

#pragma once

#include <lvgl.h>
#include <vector>

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    class Ui {
    public:
        Ui(Fonts * fonts, Styles * styles) : fonts(fonts), styles(styles) {}
        ~Ui() {
            delete fonts;
            delete styles;

            auto it = tasks->begin();
            while (it != tasks->end()) {
                delete *it++;
            }
        }

        void add_widget(widget_t, Widget *);
        lv_task_t * create_task(lv_task_cb_t, uint32_t period, lv_task_prio_t prio = LV_TASK_PRIO_MID, void * user_data = nullptr);
        void delete_task(lv_task_t * task);
        Widget * get_widget(widget_t) const;
        bool has_widget(widget_t) const;

        Fonts * get_fonts() const { return fonts; }
        Styles * get_styles() const { return styles; }
    private:
        Fonts * fonts;
        Styles * styles;

        std::vector<lv_task_t *> * tasks = new std::vector<lv_task_t *>;

        std::map<widget_t, Widget *> widgets;
    };
}

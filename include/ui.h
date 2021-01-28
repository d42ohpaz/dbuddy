#include <algorithm>

#ifndef BASIC_ICS_UI_H
#define BASIC_ICS_UI_H

#include <lvgl.h>

#include "widgets.h"

using namespace dbuddy::Widgets;

namespace dbuddy {
    class Ui {
    public:
        Ui() = default;
        ~Ui();

        void init();

        lv_disp_t * get_display() const;
        Screen * get_screen() const;
        Page * get_page() const;
        Menu * get_menu() const;
        TimeContainer * get_time_container() const;
        TimeLabel * get_time_label() const;
        ActionsContainer * get_actions_container() const;

        void updateTimeCallback(lv_task_t * task) const;
    private:
        lv_disp_t * display;

        Screen * screen;
        Page * page;
        Menu * menu;

        TimeContainer * timeContainer;
        TimeLabel * timeLabel;

        ActionsContainer * actionsContainer;
    };
}

#endif //BASIC_ICS_UI_H

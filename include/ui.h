#include <algorithm>

#ifndef DBUDDY_UI_H
#define DBUDDY_UI_H

#include <lvgl.h>

#include "widgets.h"

namespace dbuddy {
    class Ui {
    public:
        Ui() = default;
        ~Ui();

        void init();

        Screen * get_screen() const;
        Page * get_page() const;
        Menu * get_menu() const;
        TimeContainer * get_time_container() const;
        TimeLabel * get_time_label() const;
        ActionsContainer * get_actions_container() const;

        void updateTimeCallback(lv_task_t * task) const;
    private:
        Screen * screen;
        Page * page;
        Menu * menu;

        TimeContainer * timeContainer;
        TimeLabel * timeLabel;

        ActionsContainer * actionsContainer;
    };
}

#endif //DBUDDY_UI_H

#include <algorithm>

#ifndef BASIC_ICS_UI_H
#define BASIC_ICS_UI_H

#include <lvgl.h>

#include "widgets/screen.h"
#include "widgets/page.h"
#include "widgets/menu.h"
#include "widgets/timecontainer.h"
#include "widgets/timelabel.h"
#include "widgets/actionscontainer.h"

#include "ui-widgets.h"

namespace DBuddy {
    class Ui {
    public:
        Ui() = default;
        ~Ui();

        void init();

        void updateTimeCallback(lv_task_t * task);
    private:
        lv_disp_t * display;

        Widgets::Screen * screen;
        Widgets::Page * page;
        Widgets::Menu * menu;

        Widgets::TimeContainer * timeContainer;
        Widgets::TimeLabel * timeLabel;

        Widgets::ActionsContainer * actionsContainer;
    };
}

#endif //BASIC_ICS_UI_H

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

using namespace dbuddy::Widgets;

namespace dbuddy {
    class Ui {
    public:
        Ui() = default;
        ~Ui();

        void init();

        void updateTimeCallback(lv_task_t * task);
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

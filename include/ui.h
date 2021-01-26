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
        Ui();
        ~Ui();

        void init();

        void updateTimeCallback(lv_task_t * task);
    private:
        lv_disp_t * display = new lv_disp_t;

        Widgets::Screen * screen = new Widgets::Screen(nullptr, nullptr);
        Widgets::Page * page = new Widgets::Page(screen->get_self(), nullptr);
        Widgets::Menu * menu = new Widgets::Menu(page->get_self(), nullptr);

        Widgets::TimeContainer * timeContainer = new Widgets::TimeContainer(menu->get_self(), nullptr);
        Widgets::TimeLabel * timeLabel = new Widgets::TimeLabel(timeContainer->get_self(), nullptr);

        Widgets::ActionsContainer * actionsContainer = new Widgets::ActionsContainer(menu->get_self(), nullptr);
    };
}

#endif //BASIC_ICS_UI_H

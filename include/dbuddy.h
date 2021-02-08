#pragma once

#include "ui.h"
#include "hal.h"

namespace dbuddy {
    class DBuddy {
    public:
        DBuddy(Hal * hal, Ui * ui) : ui(ui), hal(hal) {};
        ~DBuddy() {
            delete hal;
            delete ui;
        }

        static void setup(Hal *, Ui *, bool, lv_indev_type_t);
        static void loop();

        void init(bool, lv_indev_type_t);
        Ui * get_ui() const { return ui; }
        Hal * get_hal() const { return hal; }

        void updateTimeCallback(lv_task_t * task) const;
    private:
        Ui * ui{};
        Hal * hal{};

        void initializeCalendar();
    };
}

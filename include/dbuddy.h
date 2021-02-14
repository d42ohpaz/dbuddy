#pragma once

#include "config.h"
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

        static void setup(Hal *, Ui *, Config *, bool, lv_indev_type_t);
        static void loop();

        void init(bool, lv_indev_type_t);
        Ui * get_ui() const { return ui; }
        Hal * get_hal() const { return hal; }
        Config * get_config() const { return config; }
    private:
        Ui * ui{};
        Hal * hal{};
        Config * config{};

        void initialize_calendar();
    };
}

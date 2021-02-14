#pragma once

#include "config.h"
#include "ui.h"
#include "hal.h"

namespace dbuddy {
    class DBuddy {
    public:
        static void setup(Hal *, Ui *, Config *, bool, lv_indev_type_t);
        static void loop();

        void init(bool, lv_indev_type_t);
        Config * get_config() const { return config; }
        Hal * get_hal() const { return hal; }
        static DBuddy * get_instance() { return instance; }
        Ui * get_ui() const { return ui; }
    private:
        Ui * ui{};
        Hal * hal{};
        Config * config{};
        static DBuddy * instance;

        DBuddy(Hal * hal, Ui * ui) : ui(ui), hal(hal) {};

        ~DBuddy() {
            delete hal;
            delete ui;
            delete instance;
        }

        void initialize_calendar();
    };
}

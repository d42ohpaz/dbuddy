#if !defined(ARDUINO)
#pragma once

#include "hal.h"

namespace dbuddy {
    class Simulator : public Hal {
    public:
        void init() final;

        void display_flush(lv_disp_drv_t *, const lv_area_t *, lv_color_t *) final;
        bool input_read(lv_indev_drv_t * drv, lv_indev_data_t * data) final;

        int get_year() const final;
        int get_month() const final;
        int get_day() const final;
        int get_hours() const final;
        int get_minutes() const final;
        int get_seconds() const final;
    };
}

#endif //ARDUINO

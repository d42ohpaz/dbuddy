#if !defined(ARDUINO)
#ifndef DBUDDY_SIMULATOR_H
#define DBUDDY_SIMULATOR_H

#include "hal.h"

namespace dbuddy {
    class Simulator : public Hal {
    public:
        void init() final;
        void display_flush(lv_disp_drv_t *, const lv_area_t *, lv_color_t *) final;
        bool input_read(lv_indev_drv_t * drv, lv_indev_data_t * data) final;
    };
}


#endif //DBUDDY_SIMULATOR_H
#endif //ARDUINO

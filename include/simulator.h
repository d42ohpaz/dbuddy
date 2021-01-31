#ifndef ARDUINO
#ifndef DBUDDY_SIMULATOR_H
#define DBUDDY_SIMULATOR_H

#include "hal.h"

namespace dbuddy {
    class Simulator : public Hal {
    public:
        void init() final;
        void flush(lv_disp_drv_t *, const lv_area_t *, lv_color_t *) final;
    };
}


#endif //DBUDDY_SIMULATOR_H
#endif //ARDUINO

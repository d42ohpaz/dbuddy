#ifndef DBUDDY_NODEMCU32S_H
#define DBUDDY_NODEMCU32S_H

#include <Adafruit_RA8875.h>

#include "hal.h"

namespace dbuddy {
    class NodeMCU32s : public Hal {
    public:
        NodeMCU32s(Adafruit_RA8875 *, uint8_t);

        void init() final;
        void display_flush(lv_disp_drv_t *, const lv_area_t *, lv_color_t *) final;
    private:
        Adafruit_RA8875 * tft;
        uint8_t interrupt;
    };
}

#endif //DBUDDY_NODEMCU32S_H

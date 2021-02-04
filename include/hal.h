#ifndef DBUDDY_HAL_H
#define DBUDDY_HAL_H

#include <lvgl.h>

namespace dbuddy {
    class Hal {
    public:
        virtual ~Hal() {
            delete display_buffer;
            delete display_driver;
        };
        virtual void init() = 0;
        virtual void display_flush(lv_disp_drv_t *, const lv_area_t *, lv_color_t *) = 0;

        void run(bool);
    private:
        static const uint32_t BUFFER_SIZE = LV_HOR_RES_MAX;

        lv_disp_buf_t * display_buffer = new lv_disp_buf_t;
        lv_disp_drv_t * display_driver = new lv_disp_drv_t;

        lv_color_t * buffer0[BUFFER_SIZE]{};
        lv_color_t * buffer1[BUFFER_SIZE]{};

        void initializeDisplay(bool);
    };
}


#endif //DBUDDY_HAL_H

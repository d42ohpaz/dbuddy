#ifndef DBUDDY_WIDGET_H
#define DBUDDY_WIDGET_H

#include <lvgl.h>

namespace dbuddy {
    enum {
        WIDGET_SCREEN               = 0x01,
        WIDGET_PAGE                 = 0x02,
        WIDGET_MENU                 = 0x03,
        WIDGET_TIME_CONTAINER       = 0x04,
        WIDGET_TIME_LABEL           = 0x05,
        WIDGET_ACTIONS_CONTAINER    = 0x06,
    };

    typedef uint8_t widget_t;

    class Ui;

    class Widget {
    public:
        explicit Widget(Ui * ui) : ui(ui) {}

        virtual ~Widget() {
            delete self;
        };

        virtual void init() {};

        void add_style(lv_obj_part_t, lv_style_t *);
        void clear_styles(lv_obj_part_t);
        void remove_style(lv_obj_part_t, lv_style_t *);

        void set_pos(lv_coord_t, lv_coord_t);
        void set_size(lv_coord_t, lv_coord_t);

        Ui * get_ui() { return ui; }
        lv_obj_t * get_self() { return self; }
        void set_self(lv_obj_t * s) { self = s; }
    protected:
        Ui * ui;
        lv_obj_t * self{};
    };
}

#endif //DBUDDY_WIDGET_H

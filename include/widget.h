#ifndef BASIC_ICS_WIDGET_H
#define BASIC_ICS_WIDGET_H

#include <lvgl.h>
#include "fonts.h"
#include "styles.h"

namespace DBuddy {
    class Widget {
    public:
        Widget(lv_obj_t *, lv_obj_t *);

        virtual ~Widget() {
            delete parent;
            delete copy;
            delete self;
        };

        virtual void init() = 0;

        void add_style(lv_obj_part_t, lv_style_t *);
        void clear_styles(lv_obj_part_t);
        void remove_style(lv_obj_part_t, lv_style_t *);

        void set_pos(lv_coord_t, lv_coord_t);
        void set_size(lv_coord_t, lv_coord_t);

        lv_obj_t * get_copy() {
            return copy;
        }

        lv_obj_t * get_parent() {
            return parent;
        }

        lv_obj_t * get_self() {
            return self;
        }
    protected:
        lv_obj_t * parent;
        lv_obj_t * copy;
        lv_obj_t * self{};

        const Fonts * fonts = Fonts::get_instance();
        const Styles * styles = Styles::get_instance();
    };
}

#endif //BASIC_ICS_WIDGET_H

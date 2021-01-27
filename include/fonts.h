#ifndef BASIC_ICS_FONTS_H
#define BASIC_ICS_FONTS_H

#include <lvgl.h>
#include <map>

namespace dbuddy {
    class Fonts {
    public:
        Fonts();
        Fonts(Fonts &other) = delete;
        void operator=(const Fonts &) = delete;

        lv_style_t * get_black_medium(lv_state_t);
        lv_style_t * get_black_small(lv_state_t);
        lv_style_t * get_black_xxlarge(lv_state_t);
        lv_style_t * get_regular_small(lv_state_t);
        lv_style_t * get_regular_xsmall(lv_state_t);
    private:
        std::map<lv_state_t, lv_style_t> black_medium{};
        std::map<lv_state_t, lv_style_t> black_small{};
        std::map<lv_state_t, lv_style_t> black_xxlarge{};
        std::map<lv_state_t, lv_style_t> regular_small{};
        std::map<lv_state_t, lv_style_t> regular_xsmall{};

        static void init_font(std::map<lv_state_t, lv_style_t> *, lv_state_t);
    };
}
#endif // BASIC_ICS_FONTS_H

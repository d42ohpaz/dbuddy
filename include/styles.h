#ifndef BASIC_ICS_STYLES_H
#define BASIC_ICS_STYLES_H

#include <lvgl.h>
#include <map>

#define DEFAULT_PADDING 12
#define DEFAULT_BORDER 5
#define DEFAULT_MENU_HEIGHT 24
#define DEFAULT_LIST_WIDTH 160

namespace dbuddy {
    class Styles {
    public:
        Styles();
        Styles(Styles &other) = delete;
        void operator=(const Styles &) = delete;

        lv_style_t * get_background_blend_mode_additive(lv_state_t);
        lv_style_t * get_background_blend_mode_subtractive(lv_state_t);
        lv_style_t * get_background_color_black(lv_state_t);
        lv_style_t * get_background_color_blue(lv_state_t);
        lv_style_t * get_background_overlay(lv_state_t);
        lv_style_t * get_background_transparent_10(lv_state_t);
        lv_style_t * get_background_transparent_20(lv_state_t);
        lv_style_t * get_background_transparent_30(lv_state_t);
        lv_style_t * get_background_transparent_40(lv_state_t);
        lv_style_t * get_background_transparent_60(lv_state_t);
        lv_style_t * get_background_transparent_70(lv_state_t);
        lv_style_t * get_background_transparent_80(lv_state_t);
        lv_style_t * get_background_transparent_90(lv_state_t);
        lv_style_t * get_background_transparent_cover(lv_state_t);
        lv_style_t * get_background_transparent_full(lv_state_t);
        lv_style_t * get_background_transparent_half(lv_state_t);
        lv_style_t * get_border_color_white(lv_state_t);
        lv_style_t * get_border_none(lv_state_t);
        lv_style_t * get_border_sides_only_bottom(lv_state_t);
        lv_style_t * get_border_sides_only_top(lv_state_t);
        lv_style_t * get_border_sides_only_left(lv_state_t);
        lv_style_t * get_border_sides_only_right(lv_state_t);
        lv_style_t * get_border_sides_right_none(lv_state_t);
        lv_style_t * get_border_thin(lv_state_t);
        lv_style_t * get_margin_none(lv_state_t);
        lv_style_t * get_padding_bottom_none(lv_state_t);
        lv_style_t * get_padding_default(lv_state_t);
        lv_style_t * get_padding_left_none(lv_state_t);
        lv_style_t * get_padding_none(lv_state_t);
        lv_style_t * get_padding_right_none(lv_state_t);
        lv_style_t * get_padding_top_none(lv_state_t);
        lv_style_t * get_radius_none(lv_state_t);
        lv_style_t * get_radius_normal(lv_state_t);
        lv_style_t * get_shadow_none(lv_state_t);
        lv_style_t * get_text_color_black(lv_state_t);
        lv_style_t * get_text_color_white(lv_state_t);
        lv_style_t * get_background_color_purple(lv_state_t);
        lv_style_t * get_background_color_none(lv_state_t);
        lv_style_t * get_background_color_white(lv_state_t);
    private:
        std::map<lv_state_t, lv_style_t> background_blend_mode_additive{};
        std::map<lv_state_t, lv_style_t> background_blend_mode_subtractive{};
        std::map<lv_state_t, lv_style_t> background_color_black{};
        std::map<lv_state_t, lv_style_t> background_color_blue{};
        std::map<lv_state_t, lv_style_t> background_color_none{};
        std::map<lv_state_t, lv_style_t> background_color_purple{};
        std::map<lv_state_t, lv_style_t> background_color_white{};
        std::map<lv_state_t, lv_style_t> background_overlay{};
        std::map<lv_state_t, lv_style_t> background_transparent_10{};
        std::map<lv_state_t, lv_style_t> background_transparent_20{};
        std::map<lv_state_t, lv_style_t> background_transparent_30{};
        std::map<lv_state_t, lv_style_t> background_transparent_40{};
        std::map<lv_state_t, lv_style_t> background_transparent_60{};
        std::map<lv_state_t, lv_style_t> background_transparent_70{};
        std::map<lv_state_t, lv_style_t> background_transparent_80{};
        std::map<lv_state_t, lv_style_t> background_transparent_90{};
        std::map<lv_state_t, lv_style_t> background_transparent_cover{};
        std::map<lv_state_t, lv_style_t> background_transparent_full{};
        std::map<lv_state_t, lv_style_t> background_transparent_half{};
        std::map<lv_state_t, lv_style_t> border_color_white{};
        std::map<lv_state_t, lv_style_t> border_none{};
        std::map<lv_state_t, lv_style_t> border_sides_only_bottom{};
        std::map<lv_state_t, lv_style_t> border_sides_only_left{};
        std::map<lv_state_t, lv_style_t> border_sides_only_right{};
        std::map<lv_state_t, lv_style_t> border_sides_only_top{};
        std::map<lv_state_t, lv_style_t> border_sides_right_none{};
        std::map<lv_state_t, lv_style_t> border_thin{};
        std::map<lv_state_t, lv_style_t> margin_none{};
        std::map<lv_state_t, lv_style_t> padding_bottom_none{};
        std::map<lv_state_t, lv_style_t> padding_default{};
        std::map<lv_state_t, lv_style_t> padding_left_none{};
        std::map<lv_state_t, lv_style_t> padding_none{};
        std::map<lv_state_t, lv_style_t> padding_right_none{};
        std::map<lv_state_t, lv_style_t> padding_top_none{};
        std::map<lv_state_t, lv_style_t> radius_none{};
        std::map<lv_state_t, lv_style_t> radius_normal{};
        std::map<lv_state_t, lv_style_t> shadow_none{};
        std::map<lv_state_t, lv_style_t> text_color_black{};
        std::map<lv_state_t, lv_style_t> text_color_white{};
    };
}

#endif // BASIC_ICS_STYLES_H

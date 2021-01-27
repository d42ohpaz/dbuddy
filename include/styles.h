#ifndef BASIC_ICS_STYLES_H
#define BASIC_ICS_STYLES_H

#include <lvgl.h>

#define DEFAULT_PADDING 12
#define DEFAULT_BORDER 5
#define DEFAULT_MENU_HEIGHT 24
#define DEFAULT_LIST_WIDTH 160

namespace DBuddy {
    class Styles {
    public:
        Styles();
        Styles(Styles &other) = delete;
        void operator=(const Styles &) = delete;

        static Styles * get_instance();

        lv_style_t * style_default_background_blend_mode_additive{};
        lv_style_t * style_default_background_blend_mode_subtractive{};
        lv_style_t * style_default_background_color_black{};
        lv_style_t * style_default_background_color_blue{};
        lv_style_t * style_default_background_overlay{};
        lv_style_t * style_default_background_transparent_10{};
        lv_style_t * style_default_background_transparent_20{};
        lv_style_t * style_default_background_transparent_30{};
        lv_style_t * style_default_background_transparent_40{};
        lv_style_t * style_default_background_transparent_60{};
        lv_style_t * style_default_background_transparent_70{};
        lv_style_t * style_default_background_transparent_80{};
        lv_style_t * style_default_background_transparent_90{};
        lv_style_t * style_default_background_transparent_cover{};
        lv_style_t * style_default_background_transparent_full{};
        lv_style_t * style_default_background_transparent_half{};
        lv_style_t * style_default_border_color_white{};
        lv_style_t * style_default_border_none{};
        lv_style_t * style_default_border_sides_only_bottom{};
        lv_style_t * style_default_border_sides_only_top{};
        lv_style_t * style_default_border_sides_only_left{};
        lv_style_t * style_default_border_sides_only_right{};
        lv_style_t * style_default_border_sides_right_none{};
        lv_style_t * style_default_border_thin{};
        lv_style_t * style_default_margin_none{};
        lv_style_t * style_default_padding_bottom_none{};
        lv_style_t * style_default_padding_default{};
        lv_style_t * style_default_padding_left_none{};
        lv_style_t * style_default_padding_none{};
        lv_style_t * style_default_padding_right_none{};
        lv_style_t * style_default_padding_top_none{};
        lv_style_t * style_default_radius_none{};
        lv_style_t * style_default_radius_normal{};
        lv_style_t * style_default_shadow_none{};
        lv_style_t * style_default_text_color_black{};
        lv_style_t * style_default_text_color_white{};

        lv_style_t * style_focused_border_color_white{};
        lv_style_t * style_focused_background_blend_mode_additive{};
        lv_style_t * style_focused_background_blend_mode_subtractive{};
        lv_style_t * style_focused_background_color_purple{};
        lv_style_t * style_focused_border_none{};
        lv_style_t * style_focused_border_sides_only_right{};
        lv_style_t * style_focused_border_thin{};
        lv_style_t * style_focused_text_color_black{};

        lv_style_t * style_pressed_background_color_none{};
        lv_style_t * style_pressed_background_color_white{};
        lv_style_t * style_pressed_text_color_black{};
    protected:
    };
}

#endif // BASIC_ICS_STYLES_H

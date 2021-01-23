#ifndef BASIC_ICS_UI_H
#define BASIC_ICS_UI_H

#include <lvgl.h>
#include "ui-widgets.h"

#define DEFAULT_PADDING 12
#define DEFAULT_BORDER 5
#define DEFAULT_MENU_HEIGHT 24
#define DEFAULT_LIST_WIDTH 160

namespace DBuddy {
    class Ui {
    public:
        Ui();
        ~Ui();

        void init();

        lv_style_t * styleFontBlackMedium(lv_state_t);
        lv_style_t * styleFontBlackSmall(lv_state_t);
        lv_style_t * styleFontBlackXXLarge(lv_state_t);
        lv_style_t * styleFontRegularSmall(lv_state_t);
        lv_style_t * styleFontRegularXSmall(lv_state_t);
    private:
        lv_disp_t * display = new lv_disp_t;
        lv_obj_t * screen = new lv_obj_t;

        PageWidget * page = new PageWidget;

        lv_style_t * style_default_font_black_medium = new lv_style_t;
        lv_style_t * style_default_font_black_small = new lv_style_t;
        lv_style_t * style_default_font_black_xxlarge = new lv_style_t;
        lv_style_t * style_default_font_regular_small = new lv_style_t;
        lv_style_t * style_default_font_regular_xsmall = new lv_style_t;

        lv_style_t * style_default_background_blend_mode_additive = new lv_style_t;
        lv_style_t * style_default_background_blend_mode_subtractive = new lv_style_t;
        lv_style_t * style_default_background_color_black = new lv_style_t;
        lv_style_t * style_default_background_color_blue = new lv_style_t;
        lv_style_t * style_default_background_overlay = new lv_style_t;
        lv_style_t * style_default_background_transparent_10 = new lv_style_t;
        lv_style_t * style_default_background_transparent_20 = new lv_style_t;
        lv_style_t * style_default_background_transparent_30 = new lv_style_t;
        lv_style_t * style_default_background_transparent_40 = new lv_style_t;
        lv_style_t * style_default_background_transparent_60 = new lv_style_t;
        lv_style_t * style_default_background_transparent_70 = new lv_style_t;
        lv_style_t * style_default_background_transparent_80 = new lv_style_t;
        lv_style_t * style_default_background_transparent_90 = new lv_style_t;
        lv_style_t * style_default_background_transparent_cover = new lv_style_t;
        lv_style_t * style_default_background_transparent_full = new lv_style_t;
        lv_style_t * style_default_background_transparent_half = new lv_style_t;
        lv_style_t * style_default_border_color_white = new lv_style_t;
        lv_style_t * style_default_border_none = new lv_style_t;
        lv_style_t * style_default_border_sides_only_bottom = new lv_style_t;
        lv_style_t * style_default_border_sides_only_top = new lv_style_t;
        lv_style_t * style_default_border_sides_only_left = new lv_style_t;
        lv_style_t * style_default_border_sides_only_right = new lv_style_t;
        lv_style_t * style_default_border_sides_right_none = new lv_style_t;
        lv_style_t * style_default_border_thin = new lv_style_t;
        lv_style_t * style_default_margin_none = new lv_style_t;
        lv_style_t * style_default_padding_bottom_none = new lv_style_t;
        lv_style_t * style_default_padding_default = new lv_style_t;
        lv_style_t * style_default_padding_left_none = new lv_style_t;
        lv_style_t * style_default_padding_none = new lv_style_t;
        lv_style_t * style_default_padding_right_none = new lv_style_t;
        lv_style_t * style_default_padding_top_none = new lv_style_t;
        lv_style_t * style_default_radius_none = new lv_style_t;
        lv_style_t * style_default_radius_normal = new lv_style_t;
        lv_style_t * style_default_shadow_none = new lv_style_t;
        lv_style_t * style_default_text_color_black = new lv_style_t;

        lv_style_t * style_focused_border_color_white = new lv_style_t;
        lv_style_t * style_focused_background_blend_mode_additive = new lv_style_t;
        lv_style_t * style_focused_background_blend_mode_subtractive = new lv_style_t;
        lv_style_t * style_focused_background_color_purple = new lv_style_t;
        lv_style_t * style_focused_border_none = new lv_style_t;
        lv_style_t * style_focused_border_sides_only_right = new lv_style_t;
        lv_style_t * style_focused_border_thin = new lv_style_t;
        lv_style_t * style_focused_text_color_black = new lv_style_t;

        lv_style_t * style_pressed_background_color_none = new lv_style_t;
        lv_style_t * style_pressed_background_color_white = new lv_style_t;
        lv_style_t * style_pressed_text_color_black = new lv_style_t;

        void initPageWidget();
        void initPageMenuWidget();
        void initFonts();
        void initStyles();
    };
}

#endif //BASIC_ICS_UI_H

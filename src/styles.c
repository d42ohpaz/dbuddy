#include "styles.h"

lv_style_t style_default_background_color_black;
lv_style_t style_default_background_color_blue;
lv_style_t style_default_background_overlay_color_black;
lv_style_t style_default_background_transparent_full;
lv_style_t style_default_background_transparent_half;
lv_style_t style_default_background_transparent_cover;
lv_style_t style_default_border_color_white;
lv_style_t style_default_border_none;
lv_style_t style_default_border_sides_right_none;
lv_style_t style_default_font_black_large;
lv_style_t style_default_font_black_large_48;
lv_style_t style_default_font_black_large_72;
lv_style_t style_default_font_black_medium;
lv_style_t style_default_font_black_small;
lv_style_t style_default_padding_default;
lv_style_t style_default_padding_left_none;
lv_style_t style_default_padding_none;
lv_style_t style_default_radius_none;
lv_style_t style_default_text_color_black;

lv_style_t style_focused_background_blend_mode_additive;
lv_style_t style_focused_background_color_purple;
lv_style_t style_focused_text_color_black;

void styles_init(void) {
    static bool initialized = false;

    if (initialized) {
        LV_LOG_WARN("styles_init: already inited");
        return;
    }

    lv_style_init(&style_default_background_transparent_full);
    lv_style_set_bg_opa(&style_default_background_transparent_full, LV_STATE_DEFAULT, LV_OPA_TRANSP);

    lv_style_init(&style_default_background_transparent_half);
    lv_style_set_bg_opa(&style_default_background_transparent_half, LV_STATE_DEFAULT, LV_OPA_50);

    lv_style_init(&style_default_background_transparent_cover);
    lv_style_set_bg_opa(&style_default_background_transparent_cover, LV_STATE_DEFAULT, LV_OPA_COVER);

    lv_style_init(&style_default_padding_default);
    lv_style_set_pad_all(&style_default_padding_default, LV_STATE_DEFAULT, DEFAULT_PADDING);

    lv_style_init(&style_default_padding_left_none);
    lv_style_set_pad_top(&style_default_padding_left_none, LV_STATE_DEFAULT, DEFAULT_PADDING);
    lv_style_set_pad_left(&style_default_padding_left_none, LV_STATE_DEFAULT, 0);
    lv_style_set_pad_right(&style_default_padding_left_none, LV_STATE_DEFAULT, DEFAULT_PADDING);
    lv_style_set_pad_bottom(&style_default_padding_left_none, LV_STATE_DEFAULT, DEFAULT_PADDING);

    lv_style_init(&style_default_padding_none);
    lv_style_set_pad_all(&style_default_padding_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_radius_none);
    lv_style_set_radius(&style_default_radius_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_text_color_black);
    lv_style_set_text_color(&style_default_text_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&style_default_border_color_white);
    lv_style_set_border_color(&style_default_border_color_white, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    lv_style_init(&style_default_border_none);
    lv_style_set_border_width(&style_default_border_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_border_sides_right_none);
    lv_style_set_border_side(&style_default_border_sides_right_none, LV_STATE_DEFAULT, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP);

    lv_style_init(&style_default_background_color_black);
    lv_style_set_bg_color(&style_default_background_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&style_default_background_color_blue);
    lv_style_set_bg_color(&style_default_background_color_blue, LV_STATE_DEFAULT, LV_COLOR_BLUE);

    lv_style_init(&style_default_font_black_medium);
    lv_style_set_text_font(&style_default_font_black_medium, LV_STATE_DEFAULT, &roboto_black_24);
    lv_style_set_value_font(&style_default_font_black_medium, LV_STATE_DEFAULT, &roboto_black_24);

    lv_style_init(&style_default_font_black_small);
    lv_style_set_text_font(&style_default_font_black_small, LV_STATE_DEFAULT, &roboto_black_16);
    lv_style_set_value_font(&style_default_font_black_small, LV_STATE_DEFAULT, &roboto_black_16);

    lv_style_init(&style_default_font_black_large);
    lv_style_set_text_font(&style_default_font_black_large, LV_STATE_DEFAULT, &roboto_black_96);
    lv_style_set_value_font(&style_default_font_black_large, LV_STATE_DEFAULT, &roboto_black_96);

    lv_style_init(&style_default_font_black_large_48);
    lv_style_set_text_font(&style_default_font_black_large_48, LV_STATE_DEFAULT, &roboto_black_48);
    lv_style_set_value_font(&style_default_font_black_large_48, LV_STATE_DEFAULT, &roboto_black_48);

    lv_style_init(&style_default_font_black_large_72);
    lv_style_set_text_font(&style_default_font_black_large_72, LV_STATE_DEFAULT, &roboto_black_72);
    lv_style_set_value_font(&style_default_font_black_large_72, LV_STATE_DEFAULT, &roboto_black_72);

    lv_style_init(&style_default_background_overlay_color_black);
    lv_style_copy(&style_default_background_overlay_color_black, &style_default_background_color_black);
    lv_style_copy(&style_default_background_overlay_color_black, &style_default_background_transparent_half);

    lv_style_init(&style_focused_background_blend_mode_additive);
    lv_style_set_bg_blend_mode(&style_focused_background_blend_mode_additive, LV_STATE_FOCUSED, LV_BLEND_MODE_ADDITIVE);

    lv_style_init(&style_focused_background_color_purple);
    lv_style_set_bg_color(&style_focused_background_color_purple, LV_STATE_FOCUSED, LV_COLOR_PURPLE);

    lv_style_init(&style_focused_text_color_black);
    lv_style_set_text_color(&style_focused_text_color_black, LV_STATE_FOCUSED, LV_COLOR_BLACK);


    initialized = true;
    LV_LOG_INFO("styles_init ready");
}

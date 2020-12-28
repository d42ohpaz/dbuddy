#include "styles.h"

void styles_init(void) {
    static bool initialized = false;

    if (initialized) {
        LV_LOG_WARN("styles_init: already inited");
        return;
    }

    lv_style_init(&style_default_background_blend_mode_additive);
    lv_style_set_bg_blend_mode(&style_default_background_blend_mode_additive, LV_STATE_DEFAULT, LV_BLEND_MODE_ADDITIVE);

    lv_style_init(&style_default_background_blend_mode_subtractive);
    lv_style_set_bg_blend_mode(&style_default_background_blend_mode_subtractive, LV_STATE_DEFAULT, LV_BLEND_MODE_SUBTRACTIVE);

    lv_style_init(&style_focused_background_blend_mode_additive);
    lv_style_set_bg_blend_mode(&style_focused_background_blend_mode_additive, LV_STATE_FOCUSED, LV_BLEND_MODE_ADDITIVE);

    lv_style_init(&style_focused_background_blend_mode_subtractive);
    lv_style_set_bg_blend_mode(&style_focused_background_blend_mode_subtractive, LV_STATE_FOCUSED, LV_BLEND_MODE_SUBTRACTIVE);

    lv_style_init(&style_default_background_transparent_full);
    lv_style_set_bg_opa(&style_default_background_transparent_full, LV_STATE_DEFAULT, LV_OPA_TRANSP);

    lv_style_init(&style_default_background_transparent_10);
    lv_style_set_bg_opa(&style_default_background_transparent_10, LV_STATE_DEFAULT, LV_OPA_10);

    lv_style_init(&style_default_background_transparent_20);
    lv_style_set_bg_opa(&style_default_background_transparent_20, LV_STATE_DEFAULT, LV_OPA_20);

    lv_style_init(&style_default_background_transparent_30);
    lv_style_set_bg_opa(&style_default_background_transparent_30, LV_STATE_DEFAULT, LV_OPA_30);

    lv_style_init(&style_default_background_transparent_40);
    lv_style_set_bg_opa(&style_default_background_transparent_40, LV_STATE_DEFAULT, LV_OPA_40);

    lv_style_init(&style_default_background_transparent_half);
    lv_style_set_bg_opa(&style_default_background_transparent_half, LV_STATE_DEFAULT, LV_OPA_50);

    lv_style_init(&style_default_background_transparent_60);
    lv_style_set_bg_opa(&style_default_background_transparent_60, LV_STATE_DEFAULT, LV_OPA_60);

    lv_style_init(&style_default_background_transparent_70);
    lv_style_set_bg_opa(&style_default_background_transparent_70, LV_STATE_DEFAULT, LV_OPA_70);

    lv_style_init(&style_default_background_transparent_80);
    lv_style_set_bg_opa(&style_default_background_transparent_80, LV_STATE_DEFAULT, LV_OPA_80);

    lv_style_init(&style_default_background_transparent_90);
    lv_style_set_bg_opa(&style_default_background_transparent_90, LV_STATE_DEFAULT, LV_OPA_90);

    lv_style_init(&style_default_background_transparent_cover);
    lv_style_set_bg_opa(&style_default_background_transparent_cover, LV_STATE_DEFAULT, LV_OPA_COVER);

    lv_style_init(&style_default_margin_none);
    lv_style_set_pad_all(&style_default_margin_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_padding_default);
    lv_style_set_pad_all(&style_default_padding_default, LV_STATE_DEFAULT, DEFAULT_PADDING);

    lv_style_init(&style_default_padding_top_none);
    lv_style_set_pad_top(&style_default_padding_top_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_padding_left_none);
    lv_style_set_pad_left(&style_default_padding_left_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_padding_right_none);
    lv_style_set_pad_right(&style_default_padding_right_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_padding_bottom_none);
    lv_style_set_pad_bottom(&style_default_padding_bottom_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_padding_none);
    lv_style_set_pad_all(&style_default_padding_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_radius_none);
    lv_style_set_radius(&style_default_radius_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_radius_normal);
    lv_style_set_radius(&style_default_radius_normal, LV_STATE_DEFAULT, 5);

    lv_style_init(&style_default_shadow_none);
    lv_style_set_shadow_width(&style_default_shadow_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_text_color_black);
    lv_style_set_text_color(&style_default_text_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&style_default_border_color_white);
    lv_style_set_border_color(&style_default_border_color_white, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    lv_style_init(&style_default_border_none);
    lv_style_set_border_width(&style_default_border_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_default_border_sides_only_bottom);
    lv_style_set_border_side(&style_default_border_sides_only_bottom, LV_STATE_DEFAULT, LV_BORDER_SIDE_BOTTOM);

    lv_style_init(&style_default_border_sides_only_right);
    lv_style_set_border_side(&style_default_border_sides_only_right, LV_STATE_DEFAULT, LV_BORDER_SIDE_RIGHT);

    lv_style_init(&style_default_border_sides_right_none);
    lv_style_set_border_side(&style_default_border_sides_right_none, LV_STATE_DEFAULT, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP);

    lv_style_init(&style_default_border_thin);
    lv_style_set_border_width(&style_default_border_thin, LV_STATE_DEFAULT, 1);

    lv_style_init(&style_default_background_color_black);
    lv_style_set_bg_color(&style_default_background_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&style_default_background_color_blue);
    lv_style_set_bg_color(&style_default_background_color_blue, LV_STATE_DEFAULT, LV_COLOR_BLUE);

    lv_style_init(&style_default_background_overlay_color_black);
    lv_style_set_bg_color(&style_default_background_overlay_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_bg_opa(&style_default_background_overlay_color_black, LV_STATE_DEFAULT, LV_OPA_50);

    lv_style_init(&style_focused_background_color_purple);
    lv_style_set_bg_color(&style_focused_background_color_purple, LV_STATE_FOCUSED, LV_COLOR_PURPLE);

    lv_style_init(&style_focused_border_none);
    lv_style_set_border_width(&style_focused_border_none, LV_STATE_FOCUSED, 0);

    lv_style_init(&style_focused_border_sides_only_right);
    lv_style_set_border_side(&style_focused_border_sides_only_right, LV_STATE_FOCUSED, LV_BORDER_SIDE_RIGHT);

    lv_style_init(&style_focused_border_thin);
    lv_style_set_border_width(&style_focused_border_thin, LV_STATE_FOCUSED, 1);

    lv_style_init(&style_focused_text_color_black);
    lv_style_set_text_color(&style_focused_text_color_black, LV_STATE_FOCUSED, LV_COLOR_BLACK);

    lv_style_init(&style_focused_border_color_white);
    lv_style_set_border_color(&style_focused_border_color_white, LV_STATE_FOCUSED, LV_COLOR_WHITE);

    lv_style_init(&style_pressed_background_color_none);
    lv_style_set_bg_opa(&style_pressed_background_color_none, LV_STATE_PRESSED, LV_OPA_TRANSP);

    lv_style_init(&style_pressed_background_color_white);
    lv_style_set_bg_color(&style_pressed_background_color_white, LV_STATE_PRESSED, LV_COLOR_WHITE);

    lv_style_init(&style_pressed_text_color_black);
    lv_style_set_text_color(&style_pressed_text_color_black, LV_STATE_PRESSED, LV_COLOR_BLACK);

    initialized = true;
    LV_LOG_INFO("styles_init ready");
}

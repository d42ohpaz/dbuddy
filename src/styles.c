#include "styles.h"

lv_style_t style_background_transparent_full;
lv_style_t style_background_transparent_half;
lv_style_t style_padding_default;
lv_style_t style_padding_none;
lv_style_t style_text_color_black;
lv_style_t style_border_color_white;
lv_style_t style_border_none;
lv_style_t style_border_sides_right_none;
lv_style_t style_background_color_black;
lv_style_t style_background_color_blue;
lv_style_t style_font_black_medium;
lv_style_t style_font_black_large;
lv_style_t style_background_overlay_color_black;

void styles_init(void) {
    static bool initialized = false;

    if (initialized) {
        LV_LOG_WARN("styles_init: already inited");
        return;
    }

    lv_style_init(&style_background_transparent_full);
    lv_style_set_bg_opa(&style_background_transparent_full, LV_STATE_DEFAULT, LV_OPA_TRANSP);

    lv_style_init(&style_background_transparent_half);
    lv_style_set_bg_opa(&style_background_transparent_half, LV_STATE_DEFAULT, LV_OPA_50);

    lv_style_init(&style_padding_default);
    lv_style_set_pad_all(&style_padding_default, LV_STATE_DEFAULT, DEFAULT_PADDING);

    lv_style_init(&style_padding_none);
    lv_style_set_pad_all(&style_padding_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_text_color_black);
    lv_style_set_text_color(&style_text_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&style_border_color_white);
    lv_style_set_border_color(&style_border_color_white, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_width(&style_border_color_white, LV_STATE_DEFAULT, DEFAULT_BORDER);

    lv_style_init(&style_border_none);
    lv_style_set_border_width(&style_border_none, LV_STATE_DEFAULT, 0);

    lv_style_init(&style_border_sides_right_none);
    lv_style_set_border_side(&style_border_sides_right_none, LV_STATE_DEFAULT, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP);

    lv_style_init(&style_background_color_black);
    lv_style_set_bg_color(&style_background_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&style_background_color_blue);
    lv_style_set_bg_color(&style_background_color_blue, LV_STATE_DEFAULT, LV_COLOR_BLUE);

    lv_style_init(&style_font_black_medium);
    lv_style_set_text_font(&style_font_black_medium, LV_STATE_DEFAULT, &roboto_black_24);
    lv_style_set_value_align(&style_font_black_medium, LV_STATE_DEFAULT, LV_ALIGN_IN_TOP_MID);
    lv_style_set_value_font(&style_font_black_medium, LV_STATE_DEFAULT, &roboto_black_24);

    lv_style_init(&style_font_black_large);
    lv_style_set_text_font(&style_font_black_large, LV_STATE_DEFAULT, &roboto_black_96);
    lv_style_set_value_align(&style_font_black_large, LV_STATE_DEFAULT, LV_ALIGN_CENTER);
    lv_style_set_value_font(&style_font_black_large, LV_STATE_DEFAULT, &roboto_black_96);

    lv_style_init(&style_background_overlay_color_black);
    lv_style_copy(&style_background_overlay_color_black, &style_background_color_black);
    lv_style_copy(&style_background_overlay_color_black, &style_background_transparent_half);

    initialized = true;
    LV_LOG_INFO("styles_init ready");
}

#include "fonts.h"

using namespace DBuddy;

Fonts::Fonts() {
    lv_style_init(style_default_font_black_medium);
    lv_style_set_text_font(style_default_font_black_medium, LV_STATE_DEFAULT, &roboto_black_24);
    lv_style_set_value_font(style_default_font_black_medium, LV_STATE_DEFAULT, &roboto_black_24);

    lv_style_init(style_default_font_black_small);
    lv_style_set_text_font(style_default_font_black_small, LV_STATE_DEFAULT, &roboto_black_16);
    lv_style_set_value_font(style_default_font_black_small, LV_STATE_DEFAULT, &roboto_black_16);

    lv_style_init(style_default_font_black_xxlarge);
    lv_style_set_text_font(style_default_font_black_xxlarge, LV_STATE_DEFAULT, &roboto_black_72);
    lv_style_set_value_font(style_default_font_black_xxlarge, LV_STATE_DEFAULT, &roboto_black_72);

    lv_style_init(style_default_font_regular_xsmall);
    lv_style_set_text_font(style_default_font_regular_xsmall, LV_STATE_DEFAULT, &roboto_regular_14);
    lv_style_set_value_font(style_default_font_regular_xsmall, LV_STATE_DEFAULT, &roboto_regular_14);

    lv_style_init(style_default_font_regular_small);
    lv_style_set_text_font(style_default_font_regular_small, LV_STATE_DEFAULT, &roboto_regular_16);
    lv_style_set_value_font(style_default_font_regular_small, LV_STATE_DEFAULT, &roboto_regular_16);
}

Fonts * Fonts::get_instance() {
    static Fonts * instance;

    if (instance == nullptr) {
        instance = new Fonts();
    }

    return instance;
}

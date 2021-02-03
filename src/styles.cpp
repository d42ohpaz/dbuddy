#include "styles.h"

using namespace dbuddy;

Styles::Styles() {
    lv_state_t STATES[8] = {LV_STATE_DEFAULT, LV_STATE_CHECKED, LV_STATE_FOCUSED, LV_STATE_EDITED, LV_STATE_HOVERED, LV_STATE_PRESSED, LV_STATE_DISABLED};

    background_blend_mode_additive = new std::map<lv_state_t, lv_style_t *>();
    background_blend_mode_subtractive = new std::map<lv_state_t, lv_style_t *>();
    background_color_black = new std::map<lv_state_t, lv_style_t *>();
    background_color_blue = new std::map<lv_state_t, lv_style_t *>();
    background_color_none = new std::map<lv_state_t, lv_style_t *>();
    background_color_purple = new std::map<lv_state_t, lv_style_t *>();
    background_color_white = new std::map<lv_state_t, lv_style_t *>();
    background_overlay = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_10 = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_20 = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_30 = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_40 = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_60 = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_70 = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_80 = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_90 = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_cover = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_full = new std::map<lv_state_t, lv_style_t *>();
    background_transparent_half = new std::map<lv_state_t, lv_style_t *>();
    border_color_white = new std::map<lv_state_t, lv_style_t *>();
    border_none = new std::map<lv_state_t, lv_style_t *>();
    border_reset = new std::map<lv_state_t, lv_style_t *>();
    border_sides_only_bottom = new std::map<lv_state_t, lv_style_t *>();
    border_sides_only_left = new std::map<lv_state_t, lv_style_t *>();
    border_sides_only_right = new std::map<lv_state_t, lv_style_t *>();
    border_sides_only_top = new std::map<lv_state_t, lv_style_t *>();
    border_sides_right_none = new std::map<lv_state_t, lv_style_t *>();
    border_thin = new std::map<lv_state_t, lv_style_t *>();
    margin_none = new std::map<lv_state_t, lv_style_t *>();
    margin_reset = new std::map<lv_state_t, lv_style_t *>();
    padding_bottom_none = new std::map<lv_state_t, lv_style_t *>();
    padding_default = new std::map<lv_state_t, lv_style_t *>();
    padding_left_none = new std::map<lv_state_t, lv_style_t *>();
    padding_none = new std::map<lv_state_t, lv_style_t *>();
    padding_reset = new std::map<lv_state_t, lv_style_t *>();
    padding_right_none = new std::map<lv_state_t, lv_style_t *>();
    padding_top_none = new std::map<lv_state_t, lv_style_t *>();
    radius_none = new std::map<lv_state_t, lv_style_t *>();
    radius_reset = new std::map<lv_state_t, lv_style_t *>();
    shadow_none = new std::map<lv_state_t, lv_style_t *>();
    text_color_black = new std::map<lv_state_t, lv_style_t *>();
    text_color_white = new std::map<lv_state_t, lv_style_t *>();

    for (unsigned char STATE : STATES) {
        init_style(background_blend_mode_additive, STATE);
        lv_style_set_bg_blend_mode(background_blend_mode_additive->at(STATE), STATE, LV_BLEND_MODE_ADDITIVE);

        init_style(background_blend_mode_subtractive, STATE);
        lv_style_set_bg_blend_mode(background_blend_mode_subtractive->at(STATE), STATE, LV_BLEND_MODE_SUBTRACTIVE);

        init_style(background_transparent_full, STATE);
        lv_style_set_bg_opa(background_transparent_full->at(STATE), STATE, LV_OPA_TRANSP);

        init_style(background_transparent_10, STATE);
        lv_style_set_bg_opa(background_transparent_10->at(STATE), STATE, LV_OPA_10);

        init_style(background_transparent_20, STATE);
        lv_style_set_bg_opa(background_transparent_20->at(STATE), STATE, LV_OPA_20);

        init_style(background_transparent_30, STATE);
        lv_style_set_bg_opa(background_transparent_30->at(STATE), STATE, LV_OPA_30);

        init_style(background_transparent_40, STATE);
        lv_style_set_bg_opa(background_transparent_40->at(STATE), STATE, LV_OPA_40);

        init_style(background_transparent_half, STATE);
        lv_style_set_bg_opa(background_transparent_half->at(STATE), STATE, LV_OPA_50);

        init_style(background_transparent_60, STATE);
        lv_style_set_bg_opa(background_transparent_60->at(STATE), STATE, LV_OPA_60);

        init_style(background_transparent_70, STATE);
        lv_style_set_bg_opa(background_transparent_70->at(STATE), STATE, LV_OPA_70);

        init_style(background_transparent_80, STATE);
        lv_style_set_bg_opa(background_transparent_80->at(STATE), STATE, LV_OPA_80);

        init_style(background_transparent_90, STATE);
        lv_style_set_bg_opa(background_transparent_90->at(STATE), STATE, LV_OPA_90);

        init_style(background_transparent_cover, STATE);
        lv_style_set_bg_opa(background_transparent_cover->at(STATE), STATE, LV_OPA_COVER);

        init_style(margin_none, STATE);
        lv_style_set_pad_all(margin_none->at(STATE), STATE, 0);

        init_style(margin_reset, STATE);
        lv_style_set_pad_all(margin_reset->at(STATE), STATE, DEFAULT_MARGIN);

        init_style(padding_default, STATE);
        lv_style_set_pad_all(padding_default->at(STATE), STATE, DEFAULT_PADDING);

        init_style(padding_top_none, STATE);
        lv_style_set_pad_top(padding_top_none->at(STATE), STATE, 0);

        init_style(padding_left_none, STATE);
        lv_style_set_pad_left(padding_left_none->at(STATE), STATE, 0);

        init_style(padding_right_none, STATE);
        lv_style_set_pad_right(padding_right_none->at(STATE), STATE, 0);

        init_style(padding_bottom_none, STATE);
        lv_style_set_pad_bottom(padding_bottom_none->at(STATE), STATE, 0);

        init_style(padding_none, STATE);
        lv_style_set_pad_all(padding_none->at(STATE), STATE, 0);

        init_style(padding_reset, STATE);
        lv_style_set_pad_all(padding_reset->at(STATE), STATE, DEFAULT_PADDING);

        init_style(radius_none, STATE);
        lv_style_set_radius(radius_none->at(STATE), STATE, 0);

        init_style(radius_reset, STATE);
        lv_style_set_radius(radius_reset->at(STATE), STATE, 5);

        init_style(shadow_none, STATE);
        lv_style_set_shadow_width(shadow_none->at(STATE), STATE, 0);

        init_style(text_color_black, STATE);
        lv_style_set_text_color(text_color_black->at(STATE), STATE, LV_COLOR_BLACK);

        init_style(text_color_white, STATE);
        lv_style_set_text_color(text_color_white->at(STATE), STATE, LV_COLOR_WHITE);

        init_style(border_color_white, STATE);
        lv_style_set_border_color(border_color_white->at(STATE), STATE, LV_COLOR_WHITE);

        init_style(border_none, STATE);
        lv_style_set_border_width(border_none->at(STATE), STATE, 0);

        init_style(border_reset, STATE);
        lv_style_set_border_width(border_reset->at(STATE), STATE, DEFAULT_BORDER);

        init_style(border_sides_only_bottom, STATE);
        lv_style_set_border_side(border_sides_only_bottom->at(STATE), STATE, LV_BORDER_SIDE_BOTTOM);

        init_style(border_sides_only_top, STATE);
        lv_style_set_border_side(border_sides_only_top->at(STATE), STATE, LV_BORDER_SIDE_TOP);

        init_style(border_sides_only_left, STATE);
        lv_style_set_border_side(border_sides_only_left->at(STATE), STATE, LV_BORDER_SIDE_LEFT);

        init_style(border_sides_only_right, STATE);
        lv_style_set_border_side(border_sides_only_right->at(STATE), STATE, LV_BORDER_SIDE_RIGHT);

        init_style(border_sides_right_none, STATE);
        lv_style_set_border_side(border_sides_right_none->at(STATE), STATE, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP);

        init_style(border_thin, STATE);
        lv_style_set_border_width(border_thin->at(STATE), STATE, 1);

        init_style(background_color_black, STATE);
        lv_style_set_bg_color(background_color_black->at(STATE), STATE, LV_COLOR_BLACK);

        init_style(background_color_blue, STATE);
        lv_style_set_bg_color(background_color_blue->at(STATE), STATE, LV_COLOR_MAKE(0x20, 0x2D, 0x58));

        init_style(background_overlay, STATE);
        lv_style_set_bg_color(background_overlay->at(STATE), STATE, LV_COLOR_MAKE(0x2B, 0x36, 0x6F));
        lv_style_set_bg_opa(background_overlay->at(STATE), STATE, LV_OPA_10);

        init_style(background_color_purple, STATE);
        lv_style_set_bg_color(background_color_purple->at(STATE), LV_STATE_FOCUSED, LV_COLOR_PURPLE);

        init_style(background_color_none, STATE);
        lv_style_set_bg_opa(background_color_none->at(STATE), STATE, LV_OPA_TRANSP);

        init_style(background_color_white, STATE);
        lv_style_set_bg_color(background_color_white->at(STATE), STATE, LV_COLOR_WHITE);
    }
}

void Styles::init_style(std::map<lv_state_t, lv_style_t *> * map, lv_state_t state) {
    auto * style = new lv_style_t;
    lv_style_init(style);
    (*map)[state] = style;
}

lv_style_t * Styles::get_background_blend_mode_additive(lv_state_t state) {
    return background_blend_mode_additive->at(state);
}

lv_style_t * Styles::get_background_blend_mode_subtractive(lv_state_t state) {
    return background_blend_mode_subtractive->at(state);
}

lv_style_t * Styles::get_background_color_black(lv_state_t state) {
    return background_color_black->at(state);
}

lv_style_t * Styles::get_background_color_blue(lv_state_t state) {
    return background_color_blue->at(state);
}

lv_style_t * Styles::get_background_overlay(lv_state_t state) {
    return background_overlay->at(state);
}

lv_style_t * Styles::get_background_transparent_10(lv_state_t state) {
    return background_transparent_10->at(state);
}

lv_style_t * Styles::get_background_transparent_20(lv_state_t state) {
    return background_transparent_20->at(state);
}

lv_style_t * Styles::get_background_transparent_30(lv_state_t state) {
    return background_transparent_30->at(state);
}

lv_style_t * Styles::get_background_transparent_40(lv_state_t state) {
    return background_transparent_40->at(state);
}

lv_style_t * Styles::get_background_transparent_60(lv_state_t state) {
    return background_transparent_60->at(state);
}

lv_style_t * Styles::get_background_transparent_70(lv_state_t state) {
    return background_transparent_70->at(state);
}

lv_style_t * Styles::get_background_transparent_80(lv_state_t state) {
    return background_transparent_80->at(state);
}

lv_style_t * Styles::get_background_transparent_90(lv_state_t state) {
    return background_transparent_90->at(state);
}

lv_style_t * Styles::get_background_transparent_cover(lv_state_t state) {
    return background_transparent_cover->at(state);
}

lv_style_t * Styles::get_background_transparent_full(lv_state_t state) {
    return background_transparent_full->at(state);
}

lv_style_t * Styles::get_background_transparent_half(lv_state_t state) {
    return background_transparent_half->at(state);
}

lv_style_t * Styles::get_border_color_white(lv_state_t state) {
    return border_color_white->at(state);
}

lv_style_t * Styles::get_border_none(lv_state_t state) {
    return border_none->at(state);
}

lv_style_t * Styles::get_border_reset(lv_state_t state) {
    return border_reset->at(state);
}

lv_style_t * Styles::get_border_sides_only_bottom(lv_state_t state) {
    return border_sides_only_bottom->at(state);
}

lv_style_t * Styles::get_border_sides_only_top(lv_state_t state) {
    return border_sides_only_top->at(state);
}

lv_style_t * Styles::get_border_sides_only_left(lv_state_t state) {
    return border_sides_only_left->at(state);
}

lv_style_t * Styles::get_border_sides_only_right(lv_state_t state) {
    return border_sides_only_right->at(state);
}

lv_style_t * Styles::get_border_sides_right_none(lv_state_t state) {
    return border_sides_right_none->at(state);
}

lv_style_t * Styles::get_border_thin(lv_state_t state) {
    return border_thin->at(state);
}

lv_style_t * Styles::get_margin_none(lv_state_t state) {
    return margin_none->at(state);
}

lv_style_t * Styles::get_margin_reset(lv_state_t state) {
    return margin_reset->at(state);
}

lv_style_t * Styles::get_padding_bottom_none(lv_state_t state) {
    return padding_bottom_none->at(state);
}

lv_style_t * Styles::get_padding_default(lv_state_t state) {
    return padding_default->at(state);
}

lv_style_t * Styles::get_padding_left_none(lv_state_t state) {
    return padding_left_none->at(state);
}

lv_style_t * Styles::get_padding_none(lv_state_t state) {
    return padding_none->at(state);
}

lv_style_t * Styles::get_padding_reset(lv_state_t state) {
    return padding_reset->at(state);
}

lv_style_t * Styles::get_padding_right_none(lv_state_t state) {
    return padding_right_none->at(state);
}

lv_style_t * Styles::get_padding_top_none(lv_state_t state) {
    return padding_top_none->at(state);
}

lv_style_t * Styles::get_radius_none(lv_state_t state) {
    return radius_none->at(state);
}

lv_style_t * Styles::get_radius_reset(lv_state_t state) {
    return radius_reset->at(state);
}

lv_style_t * Styles::get_shadow_none(lv_state_t state) {
    return shadow_none->at(state);
}

lv_style_t * Styles::get_text_color_black(lv_state_t state) {
    return text_color_black->at(state);
}

lv_style_t * Styles::get_text_color_white(lv_state_t state) {
    return text_color_white->at(state);
}

lv_style_t * Styles::get_background_color_purple(lv_state_t state) {
    return background_color_purple->at(state);
}

lv_style_t * Styles::get_background_color_none(lv_state_t state) {
    return background_color_none->at(state);
}

lv_style_t * Styles::get_background_color_white(lv_state_t state) {
    return background_color_white->at(state);
}

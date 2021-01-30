#include "styles.h"

using namespace dbuddy;

Styles::Styles() {
    lv_state_t STATES[8] = {LV_STATE_DEFAULT, LV_STATE_CHECKED, LV_STATE_FOCUSED, LV_STATE_EDITED, LV_STATE_HOVERED, LV_STATE_PRESSED, LV_STATE_DISABLED};

    for (unsigned char STATE : STATES) {
        lv_style_t bbma;
        lv_style_init(&bbma);
        lv_style_set_bg_blend_mode(&bbma, STATE, LV_BLEND_MODE_ADDITIVE);
        background_blend_mode_additive[STATE] = bbma;

        lv_style_t bbms;
        lv_style_init(&bbms);
        lv_style_set_bg_blend_mode(&bbms, STATE, LV_BLEND_MODE_SUBTRACTIVE);
        background_blend_mode_subtractive[STATE] = bbms;

        lv_style_t btf;
        lv_style_init(&btf);
        lv_style_set_bg_opa(&btf, STATE, LV_OPA_TRANSP);
        background_transparent_full[STATE] = btf;

        lv_style_t bt10;
        lv_style_init(&bt10);
        lv_style_set_bg_opa(&bt10, STATE, LV_OPA_10);
        background_transparent_10[STATE] = bt10;

        lv_style_t bt20;
        lv_style_init(&bt20);
        lv_style_set_bg_opa(&bt20, STATE, LV_OPA_20);
        background_transparent_20[STATE] = bt20;

        lv_style_t bt30;
        lv_style_init(&bt30);
        lv_style_set_bg_opa(&bt30, STATE, LV_OPA_30);
        background_transparent_30[STATE] = bt30;

        lv_style_t bt40;
        lv_style_init(&bt40);
        lv_style_set_bg_opa(&bt40, STATE, LV_OPA_40);
        background_transparent_40[STATE] = bt40;

        lv_style_t bth;
        lv_style_init(&bth);
        lv_style_set_bg_opa(&bth, STATE, LV_OPA_50);
        background_transparent_half[STATE] = bth;

        lv_style_t bt60;
        lv_style_init(&bt60);
        lv_style_set_bg_opa(&bt60, STATE, LV_OPA_60);
        background_transparent_60[STATE] = bt60;

        lv_style_t bt70;
        lv_style_init(&bt70);
        lv_style_set_bg_opa(&bt70, STATE, LV_OPA_70);
        background_transparent_70[STATE] = bt70;

        lv_style_t bt80;
        lv_style_init(&bt80);
        lv_style_set_bg_opa(&bt80, STATE, LV_OPA_80);
        background_transparent_80[STATE] = bt80;

        lv_style_t bt90;
        lv_style_init(&bt90);
        lv_style_set_bg_opa(&bt90, STATE, LV_OPA_90);
        background_transparent_90[STATE] = bt90;

        lv_style_t btc;
        lv_style_init(&btc);
        lv_style_set_bg_opa(&btc, STATE, LV_OPA_COVER);
        background_transparent_cover[STATE] = btc;

        lv_style_t mn;
        lv_style_init(&mn);
        lv_style_set_pad_all(&mn, STATE, 0);
        margin_none[STATE] = mn;

        lv_style_t pd;
        lv_style_init(&pd);
        lv_style_set_pad_all(&pd, STATE, DEFAULT_PADDING);
        padding_default[STATE] = pd;

        lv_style_t ptn;
        lv_style_init(&ptn);
        lv_style_set_pad_top(&ptn, STATE, 0);
        padding_top_none[STATE] = ptn;

        lv_style_t pln;
        lv_style_init(&pln);
        lv_style_set_pad_left(&pln, STATE, 0);
        padding_left_none[STATE] = pln;

        lv_style_t prn;
        lv_style_init(&prn);
        lv_style_set_pad_right(&prn, STATE, 0);
        padding_right_none[STATE] = prn;

        lv_style_t pbn;
        lv_style_init(&pbn);
        lv_style_set_pad_bottom(&pbn, STATE, 0);
        padding_bottom_none[STATE] = pbn;

        lv_style_t pn;
        lv_style_init(&pn);
        lv_style_set_pad_all(&pn, STATE, 0);
        padding_none[STATE] = pn;

        lv_style_t rn;
        lv_style_init(&rn);
        lv_style_set_radius(&rn, STATE, 0);
        radius_none[STATE] = rn;

        lv_style_t rm;
        lv_style_init(&rm);
        lv_style_set_radius(&rm, STATE, 5);
        radius_normal[STATE] = rm;

        lv_style_t sn;
        lv_style_init(&sn);
        lv_style_set_shadow_width(&sn, STATE, 0);
        shadow_none[STATE] = sn;

        lv_style_t tcb;
        lv_style_init(&tcb);
        lv_style_set_text_color(&tcb, STATE, LV_COLOR_BLACK);
        text_color_black[STATE] = tcb;

        lv_style_t tcw;
        lv_style_init(&tcw);
        lv_style_set_text_color(&tcw, STATE, LV_COLOR_WHITE);
        text_color_white[STATE] = tcw;

        lv_style_t bocw;
        lv_style_init(&bocw);
        lv_style_set_border_color(&bocw, STATE, LV_COLOR_WHITE);
        border_color_white[STATE] = bocw;

        lv_style_t bn;
        lv_style_init(&bn);
        lv_style_set_border_width(&bn, STATE, 0);
        border_none[STATE] = bn;

        lv_style_t bsob;
        lv_style_init(&bsob);
        lv_style_set_border_side(&bsob, STATE, LV_BORDER_SIDE_BOTTOM);
        border_sides_only_bottom[STATE] = bsob;

        lv_style_t bsot;
        lv_style_init(&bsot);
        lv_style_set_border_side(&bsot, STATE, LV_BORDER_SIDE_TOP);
        border_sides_only_top[STATE] = bsot;

        lv_style_t bsol;
        lv_style_init(&bsol);
        lv_style_set_border_side(&bsol, STATE, LV_BORDER_SIDE_LEFT);
        border_sides_only_left[STATE] = bsol;

        lv_style_t bsor;
        lv_style_init(&bsor);
        lv_style_set_border_side(&bsor, STATE, LV_BORDER_SIDE_RIGHT);
        border_sides_only_right[STATE] = bsor;

        lv_style_t bsrn;
        lv_style_init(&bsrn);
        lv_style_set_border_side(&bsrn, STATE, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP);
        border_sides_right_none[STATE] = bsrn;

        lv_style_t bt;
        lv_style_init(&bt);
        lv_style_set_border_width(&bt, STATE, 1);
        border_thin[STATE] = bt;

        lv_style_t bcb;
        lv_style_init(&bcb);
        lv_style_set_bg_color(&bcb, STATE, LV_COLOR_BLACK);
        background_color_black[STATE] = bcb;

        lv_style_t bcbl;
        lv_style_init(&bcbl);
        lv_style_set_bg_color(&bcbl, STATE, LV_COLOR_MAKE(0x20, 0x2D, 0x58));
        background_color_blue[STATE] = bcbl;

        lv_style_t bo;
        lv_style_init(&bo);
        lv_style_set_bg_color(&bo, STATE, LV_COLOR_MAKE(0x2B, 0x36, 0x6F));
        lv_style_set_bg_opa(&bo, STATE, LV_OPA_10);
        background_overlay[STATE] = bo;

        lv_style_t bcp;
        lv_style_init(&bcp);
        lv_style_set_bg_color(&bcp, LV_STATE_FOCUSED, LV_COLOR_PURPLE);
        background_color_purple[STATE] = bcp;

        lv_style_t bcn;
        lv_style_init(&bcn);
        lv_style_set_bg_opa(&bcn, STATE, LV_OPA_TRANSP);
        background_color_none[STATE] = bcn;

        lv_style_t bacw;
        lv_style_init(&bacw);
        lv_style_set_bg_color(&bacw, STATE, LV_COLOR_WHITE);
        background_color_white[STATE] = bacw;
    }
}

lv_style_t * Styles::get_background_blend_mode_additive(lv_state_t state) {
    return &background_blend_mode_additive.at(state);
}

lv_style_t * Styles::get_background_blend_mode_subtractive(lv_state_t state) {
    return &background_blend_mode_subtractive.at(state);
}

lv_style_t * Styles::get_background_color_black(lv_state_t state) {
    return &background_color_black.at(state);
}

lv_style_t * Styles::get_background_color_blue(lv_state_t state) {
    return &background_color_blue.at(state);
}

lv_style_t * Styles::get_background_overlay(lv_state_t state) {
    return &background_overlay.at(state);
}

lv_style_t * Styles::get_background_transparent_10(lv_state_t state) {
    return &background_transparent_10.at(state);
}

lv_style_t * Styles::get_background_transparent_20(lv_state_t state) {
    return &background_transparent_20.at(state);
}

lv_style_t * Styles::get_background_transparent_30(lv_state_t state) {
    return &background_transparent_30.at(state);
}

lv_style_t * Styles::get_background_transparent_40(lv_state_t state) {
    return &background_transparent_40.at(state);
}

lv_style_t * Styles::get_background_transparent_60(lv_state_t state) {
    return &background_transparent_60.at(state);
}

lv_style_t * Styles::get_background_transparent_70(lv_state_t state) {
    return &background_transparent_70.at(state);
}

lv_style_t * Styles::get_background_transparent_80(lv_state_t state) {
    return &background_transparent_80.at(state);
}

lv_style_t * Styles::get_background_transparent_90(lv_state_t state) {
    return &background_transparent_90.at(state);
}

lv_style_t * Styles::get_background_transparent_cover(lv_state_t state) {
    return &background_transparent_cover.at(state);
}

lv_style_t * Styles::get_background_transparent_full(lv_state_t state) {
    return &background_transparent_full.at(state);
}

lv_style_t * Styles::get_background_transparent_half(lv_state_t state) {
    return &background_transparent_half.at(state);
}

lv_style_t * Styles::get_border_color_white(lv_state_t state) {
    return &border_color_white.at(state);
}

lv_style_t * Styles::get_border_none(lv_state_t state) {
    return &border_none.at(state);
}

lv_style_t * Styles::get_border_sides_only_bottom(lv_state_t state) {
    return &border_sides_only_bottom.at(state);
}

lv_style_t * Styles::get_border_sides_only_top(lv_state_t state) {
    return &border_sides_only_top.at(state);
}

lv_style_t * Styles::get_border_sides_only_left(lv_state_t state) {
    return &border_sides_only_left.at(state);
}

lv_style_t * Styles::get_border_sides_only_right(lv_state_t state) {
    return &border_sides_only_right.at(state);
}

lv_style_t * Styles::get_border_sides_right_none(lv_state_t state) {
    return &border_sides_right_none.at(state);
}

lv_style_t * Styles::get_border_thin(lv_state_t state) {
    return &border_thin.at(state);
}

lv_style_t * Styles::get_margin_none(lv_state_t state) {
    return &margin_none.at(state);
}

lv_style_t * Styles::get_padding_bottom_none(lv_state_t state) {
    return &padding_bottom_none.at(state);
}

lv_style_t * Styles::get_padding_default(lv_state_t state) {
    return &padding_default.at(state);
}

lv_style_t * Styles::get_padding_left_none(lv_state_t state) {
    return &padding_left_none.at(state);
}

lv_style_t * Styles::get_padding_none(lv_state_t state) {
    return &padding_none.at(state);
}

lv_style_t * Styles::get_padding_right_none(lv_state_t state) {
    return &padding_right_none.at(state);
}

lv_style_t * Styles::get_padding_top_none(lv_state_t state) {
    return &padding_top_none.at(state);
}

lv_style_t * Styles::get_radius_none(lv_state_t state) {
    return &radius_none.at(state);
}

lv_style_t * Styles::get_radius_normal(lv_state_t state) {
    return &radius_normal.at(state);
}

lv_style_t * Styles::get_shadow_none(lv_state_t state) {
    return &shadow_none.at(state);
}

lv_style_t * Styles::get_text_color_black(lv_state_t state) {
    return &text_color_black.at(state);
}

lv_style_t * Styles::get_text_color_white(lv_state_t state) {
    return &text_color_white.at(state);
}

lv_style_t * Styles::get_background_color_purple(lv_state_t state) {
    return &background_color_purple.at(state);
}

lv_style_t * Styles::get_background_color_none(lv_state_t state) {
    return &background_color_none.at(state);
}

lv_style_t * Styles::get_background_color_white(lv_state_t state) {
    return &background_color_white.at(state);
}

#include <lvgl.h>

#include "ui.h"

DBuddy::Ui::Ui() {
    display = lv_disp_get_default();
    screen = lv_scr_act();
};

DBuddy::Ui::~Ui() {
    delete display;
    delete screen;
    delete page;
};

void DBuddy::Ui::init() {
    initFonts();
    initStyles();

    initPageWidget();
    initPageMenuWidget();
}

void DBuddy::Ui::initFonts() {
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

void DBuddy::Ui::initStyles() {
    lv_style_init(style_default_background_blend_mode_additive);
    lv_style_set_bg_blend_mode(style_default_background_blend_mode_additive, LV_STATE_DEFAULT, LV_BLEND_MODE_ADDITIVE);

    lv_style_init(style_default_background_blend_mode_subtractive);
    lv_style_set_bg_blend_mode(style_default_background_blend_mode_subtractive, LV_STATE_DEFAULT, LV_BLEND_MODE_SUBTRACTIVE);

    lv_style_init(style_focused_background_blend_mode_additive);
    lv_style_set_bg_blend_mode(style_focused_background_blend_mode_additive, LV_STATE_FOCUSED, LV_BLEND_MODE_ADDITIVE);

    lv_style_init(style_focused_background_blend_mode_subtractive);
    lv_style_set_bg_blend_mode(style_focused_background_blend_mode_subtractive, LV_STATE_FOCUSED, LV_BLEND_MODE_SUBTRACTIVE);

    lv_style_init(style_default_background_transparent_full);
    lv_style_set_bg_opa(style_default_background_transparent_full, LV_STATE_DEFAULT, LV_OPA_TRANSP);

    lv_style_init(style_default_background_transparent_10);
    lv_style_set_bg_opa(style_default_background_transparent_10, LV_STATE_DEFAULT, LV_OPA_10);

    lv_style_init(style_default_background_transparent_20);
    lv_style_set_bg_opa(style_default_background_transparent_20, LV_STATE_DEFAULT, LV_OPA_20);

    lv_style_init(style_default_background_transparent_30);
    lv_style_set_bg_opa(style_default_background_transparent_30, LV_STATE_DEFAULT, LV_OPA_30);

    lv_style_init(style_default_background_transparent_40);
    lv_style_set_bg_opa(style_default_background_transparent_40, LV_STATE_DEFAULT, LV_OPA_40);

    lv_style_init(style_default_background_transparent_half);
    lv_style_set_bg_opa(style_default_background_transparent_half, LV_STATE_DEFAULT, LV_OPA_50);

    lv_style_init(style_default_background_transparent_60);
    lv_style_set_bg_opa(style_default_background_transparent_60, LV_STATE_DEFAULT, LV_OPA_60);

    lv_style_init(style_default_background_transparent_70);
    lv_style_set_bg_opa(style_default_background_transparent_70, LV_STATE_DEFAULT, LV_OPA_70);

    lv_style_init(style_default_background_transparent_80);
    lv_style_set_bg_opa(style_default_background_transparent_80, LV_STATE_DEFAULT, LV_OPA_80);

    lv_style_init(style_default_background_transparent_90);
    lv_style_set_bg_opa(style_default_background_transparent_90, LV_STATE_DEFAULT, LV_OPA_90);

    lv_style_init(style_default_background_transparent_cover);
    lv_style_set_bg_opa(style_default_background_transparent_cover, LV_STATE_DEFAULT, LV_OPA_COVER);

    lv_style_init(style_default_margin_none);
    lv_style_set_pad_all(style_default_margin_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_padding_default);
    lv_style_set_pad_all(style_default_padding_default, LV_STATE_DEFAULT, DEFAULT_PADDING);

    lv_style_init(style_default_padding_top_none);
    lv_style_set_pad_top(style_default_padding_top_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_padding_left_none);
    lv_style_set_pad_left(style_default_padding_left_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_padding_right_none);
    lv_style_set_pad_right(style_default_padding_right_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_padding_bottom_none);
    lv_style_set_pad_bottom(style_default_padding_bottom_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_padding_none);
    lv_style_set_pad_all(style_default_padding_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_radius_none);
    lv_style_set_radius(style_default_radius_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_radius_normal);
    lv_style_set_radius(style_default_radius_normal, LV_STATE_DEFAULT, 5);

    lv_style_init(style_default_shadow_none);
    lv_style_set_shadow_width(style_default_shadow_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_text_color_black);
    lv_style_set_text_color(style_default_text_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(style_default_border_color_white);
    lv_style_set_border_color(style_default_border_color_white, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    lv_style_init(style_default_border_none);
    lv_style_set_border_width(style_default_border_none, LV_STATE_DEFAULT, 0);

    lv_style_init(style_default_border_sides_only_bottom);
    lv_style_set_border_side(style_default_border_sides_only_bottom, LV_STATE_DEFAULT, LV_BORDER_SIDE_BOTTOM);

    lv_style_init(style_default_border_sides_only_top);
    lv_style_set_border_side(style_default_border_sides_only_top, LV_STATE_DEFAULT, LV_BORDER_SIDE_TOP);

    lv_style_init(style_default_border_sides_only_left);
    lv_style_set_border_side(style_default_border_sides_only_left, LV_STATE_DEFAULT, LV_BORDER_SIDE_LEFT);

    lv_style_init(style_default_border_sides_only_right);
    lv_style_set_border_side(style_default_border_sides_only_right, LV_STATE_DEFAULT, LV_BORDER_SIDE_RIGHT);

    lv_style_init(style_default_border_sides_right_none);
    lv_style_set_border_side(style_default_border_sides_right_none, LV_STATE_DEFAULT, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP);

    lv_style_init(style_default_border_thin);
    lv_style_set_border_width(style_default_border_thin, LV_STATE_DEFAULT, 1);

    lv_style_init(style_default_background_color_black);
    lv_style_set_bg_color(style_default_background_color_black, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(style_default_background_color_blue);
    lv_style_set_bg_color(style_default_background_color_blue, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x20, 0x2D, 0x58));

    lv_style_init(style_default_background_overlay);
    lv_style_set_bg_color(style_default_background_overlay, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x2B, 0x36, 0x6F));
    lv_style_set_bg_opa(style_default_background_overlay, LV_STATE_DEFAULT, LV_OPA_10);

    lv_style_init(style_focused_background_color_purple);
    lv_style_set_bg_color(style_focused_background_color_purple, LV_STATE_FOCUSED, LV_COLOR_PURPLE);

    lv_style_init(style_focused_border_none);
    lv_style_set_border_width(style_focused_border_none, LV_STATE_FOCUSED, 0);

    lv_style_init(style_focused_border_sides_only_right);
    lv_style_set_border_side(style_focused_border_sides_only_right, LV_STATE_FOCUSED, LV_BORDER_SIDE_RIGHT);

    lv_style_init(style_focused_border_thin);
    lv_style_set_border_width(style_focused_border_thin, LV_STATE_FOCUSED, 1);

    lv_style_init(style_focused_text_color_black);
    lv_style_set_text_color(style_focused_text_color_black, LV_STATE_FOCUSED, LV_COLOR_BLACK);

    lv_style_init(style_focused_border_color_white);
    lv_style_set_border_color(style_focused_border_color_white, LV_STATE_FOCUSED, LV_COLOR_WHITE);

    lv_style_init(style_pressed_background_color_none);
    lv_style_set_bg_opa(style_pressed_background_color_none, LV_STATE_PRESSED, LV_OPA_TRANSP);

    lv_style_init(style_pressed_background_color_white);
    lv_style_set_bg_color(style_pressed_background_color_white, LV_STATE_PRESSED, LV_COLOR_WHITE);

    lv_style_init(style_pressed_text_color_black);
    lv_style_set_text_color(style_pressed_text_color_black, LV_STATE_PRESSED, LV_COLOR_BLACK);
}

void DBuddy::Ui::initPageWidget() {
    page->self = lv_page_create(screen, nullptr);

    lv_obj_set_size(page->self, LV_HOR_RES, LV_VER_RES);
    lv_obj_add_style(page->self, LV_PAGE_PART_BG, style_default_border_none);
    lv_obj_add_style(page->self, LV_PAGE_PART_BG, style_default_padding_none);
    lv_obj_add_style(page->self, LV_PAGE_PART_BG, style_default_background_transparent_full);
}

void DBuddy::Ui::initPageMenuWidget() {
    MenuWidget * menu = page->menu;

    menu->self = lv_obj_create(page->self, nullptr);

    menu->container_time = lv_obj_create(menu->self, nullptr);
    menu->label_time = lv_obj_create(menu->container_time, nullptr);

    menu->container_actions = lv_obj_create(menu->self, nullptr);
    menu->btn_settings = lv_btn_create(menu->container_actions, nullptr);
}

lv_style_t * DBuddy::Ui::styleFontBlackMedium(lv_state_t state = LV_STATE_DEFAULT) {
    switch (state) {
        case LV_STATE_CHECKED:
        case LV_STATE_DEFAULT:
        case LV_STATE_DISABLED:
        case LV_STATE_EDITED:
        case LV_STATE_FOCUSED:
        case LV_STATE_HOVERED:
        case LV_STATE_PRESSED:
        default:
            return style_default_font_black_medium;
    }
}

lv_style_t * DBuddy::Ui::styleFontBlackSmall(lv_state_t state = LV_STATE_DEFAULT) {
    switch (state) {
        case LV_STATE_CHECKED:
        case LV_STATE_DEFAULT:
        case LV_STATE_DISABLED:
        case LV_STATE_EDITED:
        case LV_STATE_FOCUSED:
        case LV_STATE_HOVERED:
        case LV_STATE_PRESSED:
        default:
            return style_default_font_black_small;
    }
}

lv_style_t * DBuddy::Ui::styleFontBlackXXLarge(lv_state_t state = LV_STATE_DEFAULT) {
    switch (state) {
        case LV_STATE_CHECKED:
        case LV_STATE_DEFAULT:
        case LV_STATE_DISABLED:
        case LV_STATE_EDITED:
        case LV_STATE_FOCUSED:
        case LV_STATE_HOVERED:
        case LV_STATE_PRESSED:
        default:
            return style_default_font_black_xxlarge;
    }
}

lv_style_t * DBuddy::Ui::styleFontRegularSmall(lv_state_t state = LV_STATE_DEFAULT) {
    switch (state) {
        case LV_STATE_CHECKED:
        case LV_STATE_DEFAULT:
        case LV_STATE_DISABLED:
        case LV_STATE_EDITED:
        case LV_STATE_FOCUSED:
        case LV_STATE_HOVERED:
        case LV_STATE_PRESSED:
        default:
            return style_default_font_regular_small;
    }
}

lv_style_t * DBuddy::Ui::styleFontRegularXSmall(lv_state_t state = LV_STATE_DEFAULT) {
    switch (state) {
        case LV_STATE_CHECKED:
        case LV_STATE_DEFAULT:
        case LV_STATE_DISABLED:
        case LV_STATE_EDITED:
        case LV_STATE_FOCUSED:
        case LV_STATE_HOVERED:
        case LV_STATE_PRESSED:
        default:
            return style_default_font_regular_xsmall;
    }
}

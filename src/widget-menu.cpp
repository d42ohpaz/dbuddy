#include "widget-menu.h"
#include "styles.h"

using namespace dbuddy;

Menu::Menu(lv_obj_t * parent, lv_obj_t * copy) : Widget(parent, copy) {
    self = lv_obj_create(parent, copy);
}

void Menu::init(Fonts * fonts, Styles * styles) {
    set_size(lv_obj_get_width(get_parent()), DEFAULT_MENU_HEIGHT + DEFAULT_PADDING);

    add_style(LV_OBJ_PART_MAIN, styles->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, styles->get_background_overlay(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, styles->get_padding_default(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, styles->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, styles->get_background_transparent_full(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, styles->get_border_color_white(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, styles->get_border_color_white(LV_STATE_FOCUSED));
    add_style(LV_OBJ_PART_MAIN, styles->get_border_sides_only_bottom(LV_STATE_DEFAULT));
}

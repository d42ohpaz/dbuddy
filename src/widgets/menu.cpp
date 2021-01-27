#include "widgets/menu.h"
#include "styles.h"

using namespace DBuddy;

Widgets::Menu::Menu(lv_obj_t * parent, lv_obj_t * copy) : Widget(parent, copy) {
    self = lv_obj_create(parent, copy);
}

void Widgets::Menu::init(Fonts * fonts, Styles * styles) {
    set_size(lv_obj_get_width(get_parent()), DEFAULT_MENU_HEIGHT + DEFAULT_PADDING);

    add_style(LV_OBJ_PART_MAIN, styles->style_default_radius_none);
    add_style(LV_OBJ_PART_MAIN, styles->style_default_background_overlay);
    add_style(LV_OBJ_PART_MAIN, styles->style_default_padding_default);
    add_style(LV_OBJ_PART_MAIN, styles->style_default_radius_none);
    add_style(LV_OBJ_PART_MAIN, styles->style_default_background_transparent_full);
    add_style(LV_PAGE_PART_BG, styles->style_default_border_color_white);
    add_style(LV_PAGE_PART_BG, styles->style_focused_border_color_white);
    add_style(LV_OBJ_PART_MAIN, styles->style_default_border_sides_only_bottom);
}

#include "widget-menu.h"

using namespace dbuddy;

void Menu::init() {
    Widget * page = get_ui()->get_widget(WIDGET_PAGE);

    set_self(lv_obj_create(page->get_self(), page->get_self()));

    set_size(page->get_width(), DEFAULT_MENU_HEIGHT + DEFAULT_PADDING);

    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_border_color_white(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_sides_only_bottom(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_reset(LV_STATE_DEFAULT));
}

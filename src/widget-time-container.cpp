#include "widget-time-container.h"

using namespace dbuddy;

void TimeContainer::init() {
    Widget * menu = get_ui()->get_widget(WIDGET_MENU);
    Widget * page = get_ui()->get_widget(WIDGET_PAGE);

    set_self(lv_obj_create(menu->get_self(), page->get_self()));

    set_size(menu->get_width() / 2, menu->get_height());

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_background_transparent_full(LV_STATE_DEFAULT));
}

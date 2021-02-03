#include "widget-calendar-date.h"

void dbuddy::CalendarDate::init() {
    Widget * page = get_ui()->get_widget(WIDGET_PAGE);
    Widget * menu = get_ui()->get_widget(WIDGET_MENU);

    set_self(lv_obj_create(page->get_self(), nullptr));

    set_pos(0, menu->get_height());
    set_size(280, 125);

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_padding_default(LV_STATE_DEFAULT));
}

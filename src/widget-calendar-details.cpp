#include "widget-calendar-details.h"

void dbuddy::CalendarDetails::init() {
    Widget * calendar_date = get_ui()->get_widget(WIDGET_CALENDAR_DATE);
    Widget * menu = get_ui()->get_widget(WIDGET_MENU);
    Widget * page = get_ui()->get_widget(WIDGET_PAGE);

    set_self(lv_obj_create(page->get_self(), page->get_self()));

    set_pos(0, menu->get_height() + calendar_date->get_height());
    set_size(calendar_date->get_width(), page->get_height() - menu->get_height() - calendar_date->get_height());

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_padding_default(LV_STATE_DEFAULT));
}

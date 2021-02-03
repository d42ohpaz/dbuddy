#include "widget-calendar-details.h"

void dbuddy::CalendarDetails::init() {
    Widget * page = get_ui()->get_widget(WIDGET_PAGE);
    Widget * menu = get_ui()->get_widget(WIDGET_MENU);
    Widget * calendar_date = get_ui()->get_widget(WIDGET_CALENDAR_DATE);

    set_self(lv_obj_create(page->get_self(), nullptr));

    set_pos(0, menu->get_height() + calendar_date->get_height());
    set_size(calendar_date->get_width(), page->get_height() - menu->get_height() - calendar_date->get_height());

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_padding_default(LV_STATE_DEFAULT));
}

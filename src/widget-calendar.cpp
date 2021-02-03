#include "widget-calendar.h"

void dbuddy::Calendar::init() {
    Widget * page = get_ui()->get_widget(WIDGET_PAGE);
    Widget * menu = get_ui()->get_widget(WIDGET_MENU);
    Widget * calendar_date = get_ui()->get_widget(WIDGET_CALENDAR_DATE);

    set_self(lv_calendar_create(page->get_self(), nullptr));

    set_pos(calendar_date->get_width(), menu->get_height());
    set_size(page->get_width() - calendar_date->get_width(), page->get_height() - menu->get_height());

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_padding_default(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_background_color_blue(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
}

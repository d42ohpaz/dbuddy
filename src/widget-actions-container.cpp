#include "widget-actions-container.h"

using namespace dbuddy;

void ActionsContainer::init() {
    Widget * menu = get_ui()->get_widget(WIDGET_MENU);
    Widget * time_container = get_ui()->get_widget(WIDGET_TIME_CONTAINER);

    set_self(lv_obj_create(menu->get_self(), nullptr));

    set_size(time_container->get_width(), time_container->get_height());
    set_pos(time_container->get_width(), 0);

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_background_transparent_full(LV_STATE_DEFAULT));
}

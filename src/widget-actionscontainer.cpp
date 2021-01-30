#include "widget-actionscontainer.h"

using namespace dbuddy;

void ActionsContainer::init() {
    lv_obj_t * menu = get_ui()->get_widget(WIDGET_MENU)->get_self();
    set_self(lv_obj_create(menu, nullptr));

    set_size(lv_obj_get_width(menu) / 2, lv_obj_get_height(menu));
    set_pos(lv_obj_get_width(menu) / 2, 0);

    lv_obj_add_style(get_self(), LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    lv_obj_add_style(get_self(), LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    lv_obj_add_style(get_self(), LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_background_transparent_full(LV_STATE_DEFAULT));
}

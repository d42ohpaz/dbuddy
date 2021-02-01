#include "widget-action-settings.h"

void dbuddy::ActionSettings::init() {
    lv_obj_t * actions_container = get_ui()->get_widget(WIDGET_ACTIONS_CONTAINER)->get_self();
    set_self(lv_obj_create(actions_container, nullptr));
    set_size(24 + DEFAULT_PADDING, 24 + DEFAULT_PADDING);

    lv_obj_align(get_self(), actions_container, LV_ALIGN_IN_RIGHT_MID, 0, 0);

    lv_obj_t * label = lv_label_create(get_self(), nullptr);
    lv_label_set_text(label, LV_SYMBOL_SETTINGS);
    lv_obj_set_auto_realign(label, true);
    lv_obj_add_style(label, LV_LABEL_PART_MAIN, get_ui()->get_fonts()->get_regular_small(LV_STATE_DEFAULT));

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_padding_left_none(LV_STATE_DEFAULT));
}

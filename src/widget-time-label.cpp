#include "widget-time-label.h"

using namespace dbuddy;

void TimeLabel::init() {
    Widget * time_container = get_ui()->get_widget(WIDGET_TIME_CONTAINER);

    set_self(lv_label_create(time_container->get_self(), nullptr));

    set_pos(DEFAULT_PADDING / 2, DEFAULT_PADDING / 2);

    lv_label_set_text(get_self(), "");
    lv_obj_set_auto_realign(get_self(), false);

    add_style(LV_LABEL_PART_MAIN, get_ui()->get_fonts()->get_regular_small(LV_STATE_DEFAULT));
    add_style(LV_LABEL_PART_MAIN, get_ui()->get_styles()->get_text_color_white(LV_STATE_DEFAULT));
}

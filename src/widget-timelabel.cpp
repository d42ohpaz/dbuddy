#include "widget-timelabel.h"

using namespace dbuddy;

void TimeLabel::init() {
    lv_obj_t * time_container = get_ui()->get_widget(WIDGET_TIME_CONTAINER)->get_self();
    set_self(lv_label_create(time_container, nullptr));

    lv_label_set_text(get_self(), "--:--");
    lv_obj_set_auto_realign(get_self(), true);
    lv_obj_align(get_self(), time_container, LV_ALIGN_IN_LEFT_MID, DEFAULT_PADDING / 2, 0);

    add_style(LV_LABEL_PART_MAIN, get_ui()->get_fonts()->get_regular_small(LV_STATE_DEFAULT));
    add_style(LV_LABEL_PART_MAIN, get_ui()->get_styles()->get_text_color_white(LV_STATE_DEFAULT));
}

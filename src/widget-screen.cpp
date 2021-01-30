#include "widget-screen.h"

using namespace dbuddy;

void Screen::init() {
    set_self(lv_scr_act());

    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_background_color_blue(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, get_ui()->get_styles()->get_background_transparent_cover(LV_STATE_DEFAULT));
}

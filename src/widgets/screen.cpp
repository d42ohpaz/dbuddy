#include "widgets/screen.h"
#include "styles.h"

using namespace dbuddy::Widgets;

Screen::Screen(lv_obj_t * parent, lv_obj_t * copy) : Widget(parent, copy) {
    self = lv_scr_act();
}

void Screen::init(Fonts * fonts, Styles * styles) {
    add_style(LV_OBJ_PART_MAIN, styles->get_background_color_blue(LV_STATE_DEFAULT));
    add_style(LV_OBJ_PART_MAIN, styles->get_background_transparent_cover(LV_STATE_DEFAULT));
}

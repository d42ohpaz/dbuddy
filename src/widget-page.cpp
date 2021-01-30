#include "widget-page.h"

using namespace dbuddy;

void Page::init() {
    lv_obj_t * screen = get_ui()->get_widget(WIDGET_SCREEN)->get_self();
    set_self(lv_page_create(screen, nullptr));

    set_size(LV_HOR_RES_MAX, LV_VER_RES_MAX);

    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_padding_none(LV_STATE_DEFAULT));
}

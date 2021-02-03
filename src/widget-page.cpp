#include "widget-page.h"

using namespace dbuddy;

void Page::init() {
    Widget * screen = get_ui()->get_widget(WIDGET_SCREEN);
    set_self(lv_page_create(screen->get_self(), nullptr));

    set_size(LV_HOR_RES_MAX, LV_VER_RES_MAX);

    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_padding_none(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_radius_none(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, get_ui()->get_styles()->get_background_transparent_full(LV_STATE_DEFAULT));
}

#include "widget-page.h"
#include "styles.h"

using namespace dbuddy;

Page::Page(lv_obj_t * parent, lv_obj_t * copy) : Widget(parent, copy) {
    self = lv_page_create(parent, copy);
}

void Page::init(Fonts * fonts, Styles * styles) {

    set_size(lv_obj_get_width(get_parent()), lv_obj_get_height(get_parent()));

    add_style(LV_PAGE_PART_BG, styles->get_border_none(LV_STATE_DEFAULT));
    add_style(LV_PAGE_PART_BG, styles->get_padding_none(LV_STATE_DEFAULT));
}

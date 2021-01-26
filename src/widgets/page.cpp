#include "widgets/page.h"
#include "styles.h"

using namespace DBuddy;

Widgets::Page::Page(lv_obj_t * parent, lv_obj_t * copy) : Widget(parent, copy) {
    init();
}

void Widgets::Page::init() {
    self = lv_page_create(get_parent(), get_copy());

    set_size(lv_obj_get_width(get_parent()), lv_obj_get_height(get_parent()));

    add_style(LV_PAGE_PART_BG, styles->style_default_border_none);
    add_style(LV_PAGE_PART_BG, styles->style_default_padding_none);
}

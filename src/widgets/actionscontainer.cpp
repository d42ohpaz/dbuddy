#include "widgets/actionscontainer.h"
#include "styles.h"

using namespace DBuddy;

Widgets::ActionsContainer::ActionsContainer(lv_obj_t * parent, lv_obj_t * copy) : Widget(parent, copy) {
    self = lv_obj_create(parent, copy);
}

void Widgets::ActionsContainer::init(Fonts * fonts, Styles * styles) {
    set_size(lv_obj_get_width(get_parent()) / 2, lv_obj_get_height(get_parent()));
    set_pos(lv_obj_get_width(get_parent()) / 2, 0);

    lv_obj_add_style(self, LV_OBJ_PART_MAIN, styles->style_default_border_none);
    lv_obj_add_style(self, LV_OBJ_PART_MAIN, styles->style_default_radius_none);
    lv_obj_add_style(self, LV_OBJ_PART_MAIN, styles->style_default_background_transparent_full);
}

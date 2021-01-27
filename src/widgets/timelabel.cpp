#include "widgets/timelabel.h"
#include "fonts.h"
#include "styles.h"

using namespace dbuddy::Widgets;

TimeLabel::TimeLabel(lv_obj_t * parent, lv_obj_t * copy) : Widget(parent, copy) {
    self = lv_label_create(parent, copy);
}

void TimeLabel::init(Fonts * fonts, Styles * styles) {
    lv_label_set_text(self, "--:--");
    lv_obj_set_auto_realign(self, true);
    lv_obj_align(self, get_parent(), LV_ALIGN_IN_LEFT_MID, DEFAULT_PADDING / 2, 0);

    add_style(LV_LABEL_PART_MAIN, &fonts->style_default_font_regular_small);
    add_style(LV_LABEL_PART_MAIN, styles->get_text_color_white(LV_STATE_DEFAULT));
}

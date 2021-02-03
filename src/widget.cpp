#include "widget.h"
#include "ui.h"

using namespace dbuddy;

void Widget::add_style(lv_obj_part_t part, lv_style_t * style) {
    lv_obj_add_style(self, part, style);
}

void Widget::clear_styles(lv_obj_part_t part) {
    lv_obj_reset_style_list(self, part);
}

lv_coord_t Widget::get_height() const {
    return lv_obj_get_height(self);
}

lv_coord_t Widget::get_width() const {
    return lv_obj_get_width(self);
}

void Widget::remove_style(lv_obj_part_t part, lv_style_t * style) {
    lv_obj_remove_style(self, part, style);
}

void Widget::set_pos(lv_coord_t x, lv_coord_t y) {
    lv_obj_set_pos(self, x, y);
}

void Widget::set_size(lv_coord_t w, lv_coord_t h) {
    lv_obj_set_size(self, w, h);
}

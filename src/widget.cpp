#include "widget.h"

using namespace dbuddy;

Widget::Widget(lv_obj_t * parent, lv_obj_t * copy) : parent(parent), copy(copy) {}

void Widget::add_style(lv_obj_part_t part, lv_style_t * style) {
    lv_obj_add_style(self, part, style);
}

void Widget::clear_styles(lv_obj_part_t part) {
    lv_obj_reset_style_list(self, part);
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

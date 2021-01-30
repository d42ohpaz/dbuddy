#include <Arduino.h>
#include <lvgl.h>
#include <ctime>

#include "ui.h"

using namespace dbuddy;

void Ui::add_widget(widget_t w, Widget * widget) {
    if (!has_widget(w)) {
        widgets[w] = widget;
        widget->init();
    }
}

Widget * Ui::get_widget(widget_t widget) const {
    return widgets.at(widget);
}

bool Ui::has_widget(widget_t widget) const {
    return widgets.find(widget) != widgets.end();
}

#include <Arduino.h>
#include <lvgl.h>
#include <ctime>

#include "ui.h"

using namespace dbuddy;

void Ui::add_widget(widget_t w, Widget * widget) {
    if (widgets.find(w) == widgets.end()) {
        widgets[w] = widget;
        widget->init();
    }
}

Widget * Ui::get_widget(widget_t widget) const {
    return widgets.at(widget);
}

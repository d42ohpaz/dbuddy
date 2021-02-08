#include "ui.h"

using namespace dbuddy;

void Ui::add_widget(widget_t w, Widget * widget) {
    if (!has_widget(w)) {
        widgets[w] = widget;
        widget->init();
    }
}

lv_task_t * Ui::create_task(lv_task_cb_t task_xcb, uint32_t period, lv_task_prio_t prio, void * user_data) {
    user_data = user_data == nullptr ? this : user_data;
    lv_task_t * task = lv_task_create(task_xcb, period, prio, user_data);
    tasks->push_back(task);
    return task;
}

void Ui::delete_task(lv_task_t * task) {
    auto it = tasks->begin();
    while (it != tasks->end()) {
        if (*it == task) {
            tasks->erase(it);
            break;
        }
    }
}

Widget * Ui::get_widget(widget_t widget) const {
    return widgets.at(widget);
}

bool Ui::has_widget(widget_t widget) const {
    return widgets.find(widget) != widgets.end();
}

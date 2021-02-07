#include "widget-wifi-signal.h"
#include <Arduino.h>

using namespace dbuddy;

extern "C" void cb_time_change_task_handler(lv_task_t *);

void WifiSignal::init() {
    Widget * time_container = get_ui()->get_widget(WIDGET_TIME_CONTAINER);
    Widget * time_label = get_ui()->get_widget(WIDGET_TIME_LABEL);

    set_self(lv_label_create(time_container->get_self(), time_label->get_self()));

    set_pos(time_label->get_width() + DEFAULT_PADDING, DEFAULT_PADDING / 2);

    lv_label_set_text(get_self(), LV_SYMBOL_WIFI);

    add_style(LV_LABEL_PART_MAIN, get_ui()->get_styles()->get_text_color_gray(LV_STATE_DEFAULT));

    // Keep the symbol to the right of the time label
    get_ui()->create_task(cb_time_change_task_handler, 500);
}

void cb_time_change_task_handler(lv_task_t * task) {
    auto * ui = (Ui *)task->user_data;
    Widget * wifi_signal = ui->get_widget(WIDGET_WIFI_SIGNAL);
    Widget * time_label = ui->get_widget(WIDGET_TIME_LABEL);

    lv_obj_set_pos(wifi_signal->get_self(), time_label->get_width() + DEFAULT_PADDING, DEFAULT_PADDING / 2);
}

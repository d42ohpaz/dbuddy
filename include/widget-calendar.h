#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class Calendar : public Widget {
    public:
        explicit Calendar(Ui * ui) : Widget(ui) {}
        void init() final;

        void set_today(lv_calendar_date_t *);
        void set_showed(lv_calendar_date_t *);
    };
}

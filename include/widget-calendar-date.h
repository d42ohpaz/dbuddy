#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class CalendarDate : public Widget {
    public:
        explicit CalendarDate(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

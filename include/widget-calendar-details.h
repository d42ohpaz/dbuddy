#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class CalendarDetails : public Widget {
    public:
        explicit CalendarDetails(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

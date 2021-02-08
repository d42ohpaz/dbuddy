#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class TimeLabel : public Widget {
    public:
        explicit TimeLabel(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class TimeContainer : public Widget {
    public:
        explicit TimeContainer(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

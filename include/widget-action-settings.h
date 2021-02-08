#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class ActionSettings : public Widget {
    public:
        explicit ActionSettings(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class WifiSignal : public Widget {
    public:
        explicit WifiSignal(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

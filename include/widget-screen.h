#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class Screen : public Widget {
    public:
        explicit Screen(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

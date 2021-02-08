#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class Menu : public Widget {
    public:
        explicit Menu(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class ActionsContainer : public Widget {
    public:
        explicit ActionsContainer(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

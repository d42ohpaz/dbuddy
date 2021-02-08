#pragma once

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class Page : public Widget {
    public:
        explicit Page(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

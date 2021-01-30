#ifndef DBUDDY_SCREEN_H
#define DBUDDY_SCREEN_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class Screen : public Widget {
    public:
        explicit Screen(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_SCREEN_H

#ifndef DBUDDY_MENU_H
#define DBUDDY_MENU_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class Menu : public Widget {
    public:
        explicit Menu(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_MENU_H

#ifndef DBUDDY_PAGE_H
#define DBUDDY_WIDGET_PAGE_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class Page : public Widget {
    public:
        explicit Page(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_PAGE_H

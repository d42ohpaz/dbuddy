#ifndef DBUDDY_CALENDAR_H
#define DBUDDY_CALENDAR_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class Calendar : public Widget {
    public:
        explicit Calendar(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_CALENDAR_H

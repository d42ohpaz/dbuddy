#ifndef DBUDDY_CALENDAR_DETAILS_H
#define DBUDDY_CALENDAR_DETAILS_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class CalendarDetails : public Widget {
    public:
        explicit CalendarDetails(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_CALENDAR_DETAILS_H

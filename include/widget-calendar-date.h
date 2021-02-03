#ifndef DBUDDY_CALENDAR_DATE_H
#define DBUDDY_CALENDAR_DATE_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class CalendarDate : public Widget {
    public:
        explicit CalendarDate(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_CALENDAR_DATE_H

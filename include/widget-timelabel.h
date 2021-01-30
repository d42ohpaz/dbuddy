#ifndef DBUDDY_TIMELABEL_H
#define DBUDDY_TIMELABEL_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class TimeLabel : public Widget {
    public:
        explicit TimeLabel(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_TIMELABEL_H

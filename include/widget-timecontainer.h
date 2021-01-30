#ifndef DBUDDY_TIMECONTAINER_H
#define DBUDDY_TIMECONTAINER_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class TimeContainer : public Widget {
    public:
        explicit TimeContainer(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_TIMECONTAINER_H

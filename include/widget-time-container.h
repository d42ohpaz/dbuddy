#ifndef DBUDDY_TIME_CONTAINER_H
#define DBUDDY_TIME_CONTAINER_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class TimeContainer : public Widget {
    public:
        explicit TimeContainer(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_TIME_CONTAINER_H

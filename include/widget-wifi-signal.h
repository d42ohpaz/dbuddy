#ifndef DBUDDY_WIFI_SIGNAL_H
#define DBUDDY_WIFI_SIGNAL_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class WifiSignal : public Widget {
    public:
        explicit WifiSignal(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_WIFI_SIGNAL_H

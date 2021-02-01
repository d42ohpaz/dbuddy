#ifndef DBUDDY_SETTINGS_ACTION_H
#define DBUDDY_SETTINGS_ACTION_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class ActionSettings : public Widget {
    public:
        explicit ActionSettings(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_SETTINGS_ACTION_H

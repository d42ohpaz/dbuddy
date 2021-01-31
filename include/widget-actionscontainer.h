#ifndef DBUDDY_ACTIONSCONTAINER_H
#define DBUDDY_ACTIONSCONTAINER_H

#include "widget.h"
#include "ui.h"

namespace dbuddy {
    class ActionsContainer : public Widget {
    public:
        explicit ActionsContainer(Ui * ui) : Widget(ui) {}
        void init() final;
    };
}

#endif //DBUDDY_ACTIONSCONTAINER_H

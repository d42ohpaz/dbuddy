#ifndef DBUDDY_WIDGET_ACTIONSCONTAINER_H
#define DBUDDY_WIDGET_ACTIONSCONTAINER_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    class ActionsContainer : public Widget {
    public:
        ActionsContainer(lv_obj_t *, lv_obj_t *);

        void init(Fonts *, Styles *) final;
    };
}

#endif //DBUDDY_WIDGET_ACTIONSCONTAINER_H

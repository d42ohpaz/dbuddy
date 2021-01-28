#ifndef BASIC_ICS_WIDGET_ACTIONSCONTAINER_H
#define BASIC_ICS_WIDGET_ACTIONSCONTAINER_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    namespace Widgets {
        class ActionsContainer : Widget {
        public:
            ActionsContainer(lv_obj_t *, lv_obj_t *);

            void init(Fonts *, Styles *) final;
        };
    }
}

#endif //BASIC_ICS_WIDGET_ACTIONSCONTAINER_H

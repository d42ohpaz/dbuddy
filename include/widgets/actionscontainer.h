#ifndef BASIC_ICS_ACTIONSCONTAINER_H
#define BASIC_ICS_ACTIONSCONTAINER_H

#include "widget.h"

namespace DBuddy {
    namespace Widgets {
        class ActionsContainer : Widget {
        public:
            ActionsContainer(lv_obj_t *, lv_obj_t *);

            void init() final;
        };
    }
}

#endif //BASIC_ICS_ACTIONSCONTAINER_H

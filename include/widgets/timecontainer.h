#ifndef BASIC_ICS_TIMECONTAINER_H
#define BASIC_ICS_TIMECONTAINER_H

#include "widget.h"

namespace DBuddy {
    namespace Widgets {
        class TimeContainer : public Widget {
        public:
            TimeContainer(lv_obj_t *, lv_obj_t *);

            void init() final;
        };
    }
}

#endif //BASIC_ICS_TIMECONTAINER_H

#ifndef BASIC_ICS_TIMELABEL_H
#define BASIC_ICS_TIMELABEL_H

#include "widget.h"

namespace DBuddy {
    namespace Widgets {
        class TimeLabel : public Widget {
        public:
            TimeLabel(lv_obj_t *, lv_obj_t *);

            void init() final;
        };
    }
}

#endif //BASIC_ICS_TIMELABEL_H

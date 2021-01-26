#ifndef BASIC_ICS_SCREEN_H
#define BASIC_ICS_SCREEN_H

#include "widget.h"

namespace DBuddy {
    namespace Widgets {
        class Screen : public Widget {
        public:
            Screen(lv_obj_t *, lv_obj_t *);

            void init() final;
        };
    }
}

#endif //BASIC_ICS_SCREEN_H

#ifndef BASIC_ICS_PAGE_H
#define BASIC_ICS_PAGE_H

#include "widget.h"

namespace DBuddy {
    namespace Widgets {
        class Page : public Widget {
        public:
            Page(lv_obj_t *, lv_obj_t *);

            void init() final;
        };
    }
}

#endif //BASIC_ICS_PAGE_H

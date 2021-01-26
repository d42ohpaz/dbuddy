#ifndef BASIC_ICS_MENU_H
#define BASIC_ICS_MENU_H

#include "widget.h"

namespace DBuddy {
    namespace Widgets {
        class Menu : public Widget {
        public:
            Menu(lv_obj_t *, lv_obj_t *);

            void init() final;
        };
    }
}

#endif //BASIC_ICS_MENU_H

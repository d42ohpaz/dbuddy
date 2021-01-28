#ifndef BASIC_ICS_PAGE_H
#define BASIC_ICS_WIDGET_PAGE_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    namespace Widgets {
        class Page : public Widget {
        public:
            Page(lv_obj_t *, lv_obj_t *);

            void init(Fonts *, Styles *) final;
        };
    }
}

#endif //BASIC_ICS_PAGE_H

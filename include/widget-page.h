#ifndef DBUDDY_PAGE_H
#define DBUDDY_WIDGET_PAGE_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    class Page : public Widget {
    public:
        Page(lv_obj_t *, lv_obj_t *);

        void init(Fonts *, Styles *) final;
    };
}

#endif //DBUDDY_PAGE_H

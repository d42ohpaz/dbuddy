#ifndef DBUDDY_MENU_H
#define DBUDDY_WIDGET_MENU_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    class Menu : public Widget {
    public:
        Menu(lv_obj_t *, lv_obj_t *);

        void init(Fonts *, Styles *) final;
    };
}

#endif //DBUDDY_MENU_H

#ifndef DBUDDY_TIMECONTAINER_H
#define DBUDDY_TIMECONTAINER_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    class TimeContainer : public Widget {
    public:
        TimeContainer(lv_obj_t *, lv_obj_t *);

        void init(Fonts *, Styles *) final;
    };
}

#endif //DBUDDY_TIMECONTAINER_H

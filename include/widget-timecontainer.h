#ifndef BASIC_ICS_TIMECONTAINER_H
#define BASIC_ICS_TIMECONTAINER_H

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

#endif //BASIC_ICS_TIMECONTAINER_H

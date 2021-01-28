#ifndef DBUDDY_TIMELABEL_H
#define DBUDDY_TIMELABEL_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    class TimeLabel : public Widget {
    public:
        TimeLabel(lv_obj_t *, lv_obj_t *);

        void init(Fonts *, Styles *) final;
    };
}

#endif //DBUDDY_TIMELABEL_H

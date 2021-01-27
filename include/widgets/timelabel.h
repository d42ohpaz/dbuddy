#ifndef BASIC_ICS_TIMELABEL_H
#define BASIC_ICS_TIMELABEL_H

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace DBuddy {
    namespace Widgets {
        class TimeLabel : public Widget {
        public:
            TimeLabel(lv_obj_t *, lv_obj_t *);

            void init(Fonts *, Styles *) final;
        };
    }
}

#endif //BASIC_ICS_TIMELABEL_H

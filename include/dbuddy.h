#ifndef BASIC_ICS_DBUDDY_H
#define BASIC_ICS_DBUDDY_H

#include "ui.h"
#include "hal.h"

namespace DBuddy {
    class DBuddy {
    public:
        explicit DBuddy(Hal *, Ui *);
        ~DBuddy();

        static void setup(Hal *, Ui *, bool);
        static void loop();

        void init(bool);
    private:
        Ui * ui{};
        Hal * hal{};
    };
}


#endif //BASIC_ICS_DBUDDY_H

#ifndef DBUDDY_DBUDDY_H
#define DBUDDY_DBUDDY_H

#include "ui.h"
#include "hal.h"

namespace dbuddy {
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


#endif //DBUDDY_DBUDDY_H

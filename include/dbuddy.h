#ifndef BASIC_ICS_DBUDDY_H
#define BASIC_ICS_DBUDDY_H

#include "ui.h"
#include "hal.h"

namespace DBuddy {
    class DBuddy {
    public:
        explicit DBuddy(Hal * hal);
        ~DBuddy();

        static void setup(Hal *, bool);
        static void loop();

        void init(bool);
    private:
        Ui * ui = new Ui;
        Hal * hal{};
    };
}


#endif //BASIC_ICS_DBUDDY_H

#ifndef BASIC_ICS_DBUDDY_H
#define BASIC_ICS_DBUDDY_H

#include "ui.h"

namespace DBuddy {
    class DBuddy {
    public:
        DBuddy();
        ~DBuddy();

        static void setup();
        static void loop();
    private:
        Ui *ui = new Ui;
    };
}


#endif //BASIC_ICS_DBUDDY_H

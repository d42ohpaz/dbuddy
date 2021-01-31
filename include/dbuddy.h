#ifndef DBUDDY_DBUDDY_H
#define DBUDDY_DBUDDY_H

#include "ui.h"
#include "hal.h"

namespace dbuddy {
    class DBuddy {
    public:
        DBuddy(Hal * hal, Ui * ui) : ui(ui), hal(hal) {};
        ~DBuddy() {
            delete hal;
            delete ui;
        }

        static void setup(Hal *, Ui *, bool);
        static void loop();

        void init(bool);

        void updateTimeCallback(lv_task_t * task) const;
    private:
        Ui * ui{};
        Hal * hal{};
    };
}


#endif //DBUDDY_DBUDDY_H

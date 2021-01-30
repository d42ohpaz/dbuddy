#ifndef DBUDDY_UI_H
#define DBUDDY_UI_H

#include <lvgl.h>

#include "widget.h"
#include "fonts.h"
#include "styles.h"

namespace dbuddy {
    class Ui {
    public:
        Ui(Fonts * fonts, Styles * styles) : fonts(fonts), styles(styles) {}

        void add_widget(widget_t, Widget *);
        Widget * get_widget(widget_t) const;
        bool has_widget(widget_t) const;

        Fonts * get_fonts() const { return fonts; }
        Styles * get_styles() const { return styles; }
    private:
        Fonts * fonts;
        Styles * styles;

        std::map<widget_t, Widget *> widgets;
    };
}

#endif //DBUDDY_UI_H

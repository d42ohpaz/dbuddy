#include "fonts.h"

using namespace dbuddy;

Fonts::Fonts() {
    lv_state_t STATES[8] = {LV_STATE_DEFAULT};

    black_medium = new std::map<lv_state_t, lv_style_t *>();
    black_small = new std::map<lv_state_t, lv_style_t *>();
    black_xxlarge = new std::map<lv_state_t, lv_style_t *>();
    regular_small = new std::map<lv_state_t, lv_style_t *>();
    regular_xsmall = new std::map<lv_state_t, lv_style_t *>();

    for (unsigned char STATE : STATES) {
        init_font(black_medium, STATE);
        lv_style_set_text_font(black_medium->at(STATE), STATE, &roboto_black_24);

        init_font(black_small, STATE);
        lv_style_set_text_font(black_small->at(STATE), STATE, &roboto_black_16);

        init_font(black_xxlarge, STATE);
        lv_style_set_text_font(black_xxlarge->at(STATE), STATE, &roboto_black_72);

        init_font(regular_xsmall, STATE);
        lv_style_set_text_font(regular_xsmall->at(STATE), STATE, &roboto_regular_14);

        init_font(regular_small, STATE);
        lv_style_set_text_font(regular_small->at(STATE), STATE, &roboto_regular_16);
    }
}

void Fonts::init_font(std::map<lv_state_t, lv_style_t *> * map, lv_state_t state) {
    auto * style = new lv_style_t;
    lv_style_init(style);
    map->insert(std::pair<lv_state_t, lv_style_t *>(state, style));
}

lv_style_t * Fonts::get_black_medium(lv_state_t state) {
    return black_medium->at(state);
}

lv_style_t * Fonts::get_black_small(lv_state_t state) {
    return black_small->at(state);
}

lv_style_t * Fonts::get_black_xxlarge(lv_state_t state) {
    return black_xxlarge->at(state);
}

lv_style_t * Fonts::get_regular_small(lv_state_t state) {
    return regular_small->at(state);
}

lv_style_t * Fonts::get_regular_xsmall(lv_state_t state) {
    return regular_xsmall->at(state);
}

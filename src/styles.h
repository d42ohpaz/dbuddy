#ifndef DBUDDY_STYLES_H
#define DBUDDY_STYLES_H

#include "lvgl/lvgl.h"

#define DEFAULT_PADDING 16
#define DEFAULT_BORDER 5

extern lv_style_t style_background_color_black;
extern lv_style_t style_background_color_blue;
extern lv_style_t style_background_overlay_color_black;
extern lv_style_t style_background_transparent_full;
extern lv_style_t style_background_transparent_half;
extern lv_style_t style_border_color_white;
extern lv_style_t style_border_none;
extern lv_style_t style_border_sides_right_none;
extern lv_style_t style_font_black_large;
extern lv_style_t style_font_black_medium;
extern lv_style_t style_padding_default;
extern lv_style_t style_padding_none;
extern lv_style_t style_text_color_black;

void styles_init(void);

#endif //DBUDDY_STYLES_H

#ifndef DBUDDY_STYLES_H
#define DBUDDY_STYLES_H

#include "lvgl/lvgl.h"

#define DEFAULT_PADDING 16
#define DEFAULT_BORDER 5

extern lv_style_t transBackground;
extern lv_style_t halfTransBackground;
extern lv_style_t padding;
extern lv_style_t nPadding;
extern lv_style_t blkText;
extern lv_style_t wBorder;
extern lv_style_t nBorder;
extern lv_style_t triBorderRight;
extern lv_style_t blkBackground;
extern lv_style_t bluBackground;
extern lv_style_t mdDayFont;
extern lv_style_t lgDayFont;
extern lv_style_t bgBlendMode;

void styles_init(void);

#endif //DBUDDY_STYLES_H

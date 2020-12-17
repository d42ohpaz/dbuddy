#include "styles.h"

lv_style_t transBackground;
lv_style_t halfTransBackground;
lv_style_t padding;
lv_style_t nPadding;
lv_style_t blkText;
lv_style_t wBorder;
lv_style_t nBorder;
lv_style_t triBorderRight;
lv_style_t blkBackground;
lv_style_t bluBackground;
lv_style_t mdDayFont;
lv_style_t lgDayFont;
lv_style_t bgBlendMode;

void styles_init(void) {
    static bool initialized = false;

    if (initialized) {
        LV_LOG_WARN("styles_init: already inited");
        return;
    }

    lv_style_init(&transBackground);
    lv_style_set_bg_opa(&transBackground, LV_STATE_DEFAULT, LV_OPA_TRANSP);

    lv_style_init(&halfTransBackground);
    lv_style_set_bg_opa(&halfTransBackground, LV_STATE_DEFAULT, LV_OPA_50);

    lv_style_init(&padding);
    lv_style_set_pad_all(&padding, LV_STATE_DEFAULT, DEFAULT_PADDING);

    lv_style_init(&nPadding);
    lv_style_set_pad_all(&nPadding, LV_STATE_DEFAULT, 0);

    lv_style_init(&blkText);
    lv_style_set_text_color(&blkText, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&wBorder);
    lv_style_set_border_color(&wBorder, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_width(&wBorder, LV_STATE_DEFAULT, DEFAULT_BORDER);

    lv_style_init(&nBorder);
    lv_style_set_border_width(&nBorder, LV_STATE_DEFAULT, 0);

    lv_style_init(&triBorderRight);
    lv_style_set_border_side(&triBorderRight, LV_STATE_DEFAULT, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_TOP);

    lv_style_init(&blkBackground);
    lv_style_set_bg_color(&blkBackground, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    lv_style_init(&bluBackground);
    lv_style_set_bg_color(&bluBackground, LV_STATE_DEFAULT, LV_COLOR_BLUE);

    lv_style_init(&mdDayFont);
    lv_style_set_text_font(&mdDayFont, LV_STATE_DEFAULT, &roboto_black_24);
    lv_style_set_value_align(&mdDayFont, LV_STATE_DEFAULT, LV_ALIGN_IN_TOP_MID);
    lv_style_set_value_font(&mdDayFont, LV_STATE_DEFAULT, &roboto_black_24);

    lv_style_init(&lgDayFont);
    lv_style_set_text_font(&lgDayFont, LV_STATE_DEFAULT, &roboto_black_96);
    lv_style_set_value_align(&lgDayFont, LV_STATE_DEFAULT, LV_ALIGN_CENTER);
    lv_style_set_value_font(&lgDayFont, LV_STATE_DEFAULT, &roboto_black_96);

    lv_style_init(&bgBlendMode);
    lv_style_copy(&bgBlendMode, &blkBackground);
    lv_style_copy(&bgBlendMode, &halfTransBackground);

    initialized = true;
    LV_LOG_INFO("styles_init ready");
}

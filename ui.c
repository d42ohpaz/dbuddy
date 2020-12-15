#include <time.h>
#include "ui.h"

#define DEFAULT_PADDING 16
#define DEFAULT_BORDER 5

LV_IMG_DECLARE(tft_background_art)
static bool ui_initialized = false;

void updateCalendarCb(lv_task_t *task);

static lv_style_t transBackground;
static lv_style_t halfTransBackground;
static lv_style_t padding;
static lv_style_t nPadding;
static lv_style_t blkText;
static lv_style_t wBorder;
static lv_style_t nBorder;
static lv_style_t triBorderRight;
static lv_style_t blkBackground;
static lv_style_t bluBackground;
static lv_style_t mdDayFont;
static lv_style_t lgDayFont;
static lv_style_t bgBlendMode;

Ui * ui_init(void) {
    static Ui ui;

    if (ui_initialized) {
        LV_LOG_WARN("ui_init: already inited");
        return &ui;
    }

    ui.display = lv_disp_get_default();
    ui.screen = lv_scr_act();

    lv_disp_set_bg_image(ui.display, &tft_background_art);

    /**************************************************************************/

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

    /**************************************************************************/

    lv_obj_add_style(ui.screen, LV_OBJMASK_PART_MAIN, &transBackground);

    ui.page.main = lv_page_create(ui.screen, NULL);
    lv_obj_set_size(ui.page.main, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_click(ui.page.main, false);
    lv_obj_add_style(ui.page.main, LV_PAGE_PART_BG, &nBorder);
    lv_obj_add_style(ui.page.main, LV_PAGE_PART_BG, &nPadding);
    lv_obj_add_style(ui.page.main, LV_PAGE_PART_BG, &transBackground);

    ui.page.left.main = lv_obj_create(ui.page.main, NULL);
    lv_obj_set_size(ui.page.left.main, (LV_HOR_RES * 1 / 3), LV_VER_RES);
    lv_obj_set_click(ui.page.left.main, false);
    lv_obj_add_style(ui.page.left.main, LV_OBJ_PART_MAIN, &nBorder);
    lv_obj_add_style(ui.page.left.main, LV_OBJ_PART_MAIN, &transBackground);

    ui.page.left.top.main = lv_page_create(ui.page.left.main, NULL);
    lv_obj_set_click(ui.page.left.top.main, false);
    lv_obj_set_size(ui.page.left.top.main, lv_obj_get_width(ui.page.left.main), lv_obj_get_width(ui.page.left.main) * 2 / 3);
    lv_obj_add_style(ui.page.left.top.main, LV_STATE_DEFAULT, &nBorder);
    lv_obj_add_style(ui.page.left.top.main, LV_PAGE_PART_BG, &transBackground);
    lv_obj_add_style(ui.page.left.top.main, LV_PAGE_PART_BG, &padding);

    ui.page.left.bottom.main = lv_page_create(ui.page.left.main, NULL);
    lv_obj_set_click(ui.page.left.bottom.main, false);
    lv_obj_set_pos(ui.page.left.bottom.main, 0, lv_obj_get_height(ui.page.left.top.main));
    lv_obj_set_size(ui.page.left.bottom.main, lv_obj_get_width(ui.page.left.main), lv_obj_get_height(ui.page.left.main) - lv_obj_get_height(ui.page.left.top.main));
    lv_obj_set_style_local_pad_top(ui.page.left.bottom.main, LV_PAGE_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui.page.left.bottom.main, LV_STATE_DEFAULT, &nBorder);
    lv_obj_add_style(ui.page.left.bottom.main, LV_PAGE_PART_BG, &transBackground);
    lv_obj_add_style(ui.page.left.bottom.main, LV_PAGE_PART_BG, &padding);

    ui.page.left.top.container = lv_obj_create(ui.page.left.top.main, NULL);
    lv_obj_set_click(ui.page.left.top.container, false);
    lv_obj_set_size(ui.page.left.top.container, lv_page_get_width_fit(ui.page.left.top.main), lv_page_get_height_fit(ui.page.left.top.main));
    lv_obj_add_style(ui.page.left.top.container, LV_CALENDAR_PART_BG, &blkBackground);
    lv_obj_add_style(ui.page.left.top.container, LV_PAGE_PART_BG, &bgBlendMode);

    ui.page.left.bottom.itinerary = lv_obj_create(ui.page.left.bottom.main, NULL);
    lv_obj_set_click(ui.page.left.bottom.itinerary, false);
    lv_obj_set_size(ui.page.left.bottom.itinerary, lv_page_get_width_fit(ui.page.left.bottom.main), lv_page_get_height_fit(ui.page.left.bottom.main));
    lv_obj_add_style(ui.page.left.bottom.itinerary, LV_CALENDAR_PART_BG, &blkBackground);
    lv_obj_add_style(ui.page.left.bottom.itinerary, LV_PAGE_PART_BG, &bgBlendMode);

    ui.page.left.top.label_day = lv_label_create(ui.page.left.top.container, NULL);
    lv_label_set_text(ui.page.left.top.label_day, "");
    lv_obj_add_style(ui.page.left.top.label_day, LV_LABEL_PART_MAIN, &lgDayFont);

    ui.page.left.top.label_month = lv_label_create(ui.page.left.top.container, NULL);
    lv_label_set_text(ui.page.left.top.label_month, "");
    lv_obj_add_style(ui.page.left.top.label_month, LV_LABEL_PART_MAIN, &mdDayFont);

    ui.page.left.top.label_year = lv_label_create(ui.page.left.top.container, NULL);
    lv_label_set_text(ui.page.left.top.label_year, "");
    lv_obj_add_style(ui.page.left.top.label_year, LV_LABEL_PART_MAIN, &mdDayFont);

    ui.page.right.main = lv_obj_create(ui.page.main, NULL);
    lv_obj_set_click(ui.page.right.main, false);
    lv_obj_set_size(ui.page.right.main, (LV_HOR_RES * 2 / 3), LV_VER_RES);
    lv_obj_set_pos(ui.page.right.main, lv_obj_get_width(ui.page.left.main), 0);
    lv_obj_add_style(ui.page.right.main, LV_PAGE_PART_BG, &padding);
    lv_obj_add_style(ui.page.right.main, LV_OBJ_PART_MAIN, &nBorder);
    lv_obj_add_style(ui.page.right.main, LV_OBJ_PART_MAIN, &transBackground);

    ui.page.right.calendar = lv_calendar_create(ui.page.right.main, NULL);
    lv_obj_set_click(ui.page.right.calendar, false);
    lv_obj_set_size(ui.page.right.calendar, lv_obj_get_width_fit(ui.page.right.main), lv_obj_get_height_fit(ui.page.right.main));
    lv_obj_align(ui.page.right.calendar, ui.page.right.main, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(ui.page.right.calendar, LV_CALENDAR_PART_BG, &blkBackground);
    lv_obj_add_style(ui.page.right.calendar, LV_CALENDAR_PART_BG, &bgBlendMode);
    lv_obj_set_style_local_text_font(ui.page.right.calendar, LV_CALENDAR_PART_HEADER, LV_STATE_DEFAULT, &roboto_black_24);
    lv_obj_set_style_local_text_font(ui.page.right.calendar, LV_CALENDAR_PART_DAY_NAMES, LV_STATE_DEFAULT, &roboto_black_16);
    lv_obj_set_style_local_text_font(ui.page.right.calendar, LV_CALENDAR_PART_BG, LV_STATE_DEFAULT, &roboto_regular_12);

    static lv_calendar_date_t highlighted[3];
    highlighted[0].year = 2020;
    highlighted[0].month = 12;
    highlighted[0].day = 25;

    highlighted[1].year = 2020;
    highlighted[1].month = 12;
    highlighted[1].day = 24;

    highlighted[2].year = 2020;
    highlighted[2].month = 12;
    highlighted[2].day = 21;

    lv_calendar_set_highlighted_dates(ui.page.right.calendar, highlighted, sizeof(highlighted));

    lv_task_create(updateCalendarCb, 750, LV_TASK_PRIO_HIGH, &ui);

    ui_initialized = true;
    LV_LOG_INFO("ui_init ready");

    return &ui;
}

void updateCalendarCb(lv_task_t *task) {
    // https://docs.lvgl.io/latest/en/html/overview/task.html#create-a-task
    // Set up a "user_data" struct containing the labels (and shadows) for the
    // date stuff needing updating.
    Ui ui = *(Ui *)task->user_data;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char bufMonth[4], bufYear[5];
    lv_calendar_date_t today;

    strftime(bufMonth, sizeof(bufMonth), "%b", &tm);
    strftime(bufYear, sizeof(bufYear), "%EY", &tm);

    today.year = tm.tm_year + 1900;
    today.day = tm.tm_mday;
    today.month = tm.tm_mon + 1;

    lv_calendar_set_today_date(ui.page.right.calendar, &today);
    lv_calendar_set_showed_date(ui.page.right.calendar, &today);

    lv_label_set_text_fmt(ui.page.left.top.label_month, "%s", bufMonth);
    lv_label_set_text_fmt(ui.page.left.top.label_day, "%02d", tm.tm_mday);
    lv_label_set_text_fmt(ui.page.left.top.label_year, "%s", bufYear);

    lv_obj_align(ui.page.left.top.label_month, ui.page.left.top.container, LV_ALIGN_IN_TOP_MID, 0, DEFAULT_BORDER);
    lv_obj_align(ui.page.left.top.label_day, ui.page.left.top.container, LV_ALIGN_CENTER, 0, DEFAULT_BORDER);
    lv_obj_align(ui.page.left.top.label_year, ui.page.left.top.container, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
}

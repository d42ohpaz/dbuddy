#include <time.h>
#include "lvgl/lvgl.h"
#include "ui.h"

#define DEFAULT_PADDING 16
#define DEFAULT_BORDER 5

LV_IMG_DECLARE(tft_background_art)
static bool ui_initialized = false;

typedef struct ui_date_labels_t {
    lv_obj_t *month;
    lv_obj_t *day;
    lv_obj_t *year;

    lv_obj_t *calendar;

    lv_obj_t *parent;
} ui_date_labels_t;

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

static lv_obj_t *scr;
static lv_obj_t *page;
static lv_obj_t *topLeftPage;
static lv_obj_t *botLeftPage;
static lv_obj_t *topLeftPageDay;
static lv_obj_t *botLeftPageItinerary;
static lv_obj_t *topLeftPageMonthLabel;
static lv_obj_t *topLeftPageDayLabel;
static lv_obj_t *topLeftPageYearLabel;
static lv_obj_t *leftPage;
static lv_obj_t *rightPage;
static lv_obj_t *calendar;

static ui_date_labels_t uiDateLabels = {
        .day = NULL,
        .month = NULL,
        .year = NULL,
        .calendar = NULL,
        .parent = NULL
};

void ui_init(void) {
    if (ui_initialized) {
        LV_LOG_WARN("ui_init: already inited");
        return;
    }

    lv_disp_t *display = lv_disp_get_default();
    lv_disp_set_bg_image(display, &tft_background_art);

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

    scr = lv_scr_act();
    lv_obj_add_style(scr, LV_OBJMASK_PART_MAIN, &transBackground);

    page = lv_page_create(scr, NULL);
    lv_obj_set_size(page, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_click(page, false);
    lv_obj_add_style(page, LV_PAGE_PART_BG, &nBorder);
    lv_obj_add_style(page, LV_PAGE_PART_BG, &nPadding);
    lv_obj_add_style(page, LV_PAGE_PART_BG, &transBackground);

    leftPage = lv_obj_create(page, NULL);
    lv_obj_set_size(leftPage, (LV_HOR_RES * 1 / 3), LV_VER_RES);
    lv_obj_set_click(leftPage, false);
    lv_obj_add_style(leftPage, LV_OBJ_PART_MAIN, &nBorder);
    lv_obj_add_style(leftPage, LV_OBJ_PART_MAIN, &transBackground);

    rightPage = lv_obj_create(page, leftPage);
    lv_obj_set_click(rightPage, false);
    lv_obj_set_size(rightPage, (LV_HOR_RES * 2 / 3), LV_VER_RES);
    lv_obj_set_pos(rightPage, lv_obj_get_width(leftPage), 0);
    lv_obj_add_style(rightPage, LV_PAGE_PART_BG, &padding);

    topLeftPage = lv_page_create(leftPage, NULL);
    lv_obj_set_click(topLeftPage, false);
    lv_obj_set_size(topLeftPage, lv_obj_get_width(leftPage), lv_obj_get_width(leftPage) * 2 / 3);
    lv_obj_add_style(topLeftPage, LV_STATE_DEFAULT, &nBorder);
    lv_obj_add_style(topLeftPage, LV_PAGE_PART_BG, &transBackground);
    lv_obj_add_style(topLeftPage, LV_PAGE_PART_BG, &padding);

    botLeftPage = lv_page_create(leftPage, NULL);
    lv_obj_set_click(botLeftPage, false);
    lv_obj_set_pos(botLeftPage, 0, lv_obj_get_height(topLeftPage));
    lv_obj_set_size(botLeftPage, lv_obj_get_width(leftPage), lv_obj_get_height(leftPage) - lv_obj_get_height(topLeftPage));
    lv_obj_set_style_local_pad_top(botLeftPage, LV_PAGE_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(botLeftPage, LV_STATE_DEFAULT, &nBorder);
    lv_obj_add_style(botLeftPage, LV_PAGE_PART_BG, &transBackground);
    lv_obj_add_style(botLeftPage, LV_PAGE_PART_BG, &padding);

    topLeftPageDay = lv_obj_create(topLeftPage, NULL);
    lv_obj_set_click(topLeftPageDay, false);
    lv_obj_set_size(topLeftPageDay, lv_page_get_width_fit(topLeftPage), lv_page_get_height_fit(topLeftPage));
    lv_obj_add_style(topLeftPageDay, LV_CALENDAR_PART_BG, &blkBackground);
    lv_obj_add_style(topLeftPageDay, LV_PAGE_PART_BG, &bgBlendMode);

    botLeftPageItinerary = lv_obj_create(botLeftPage, NULL);
    lv_obj_set_click(botLeftPageItinerary, false);
    lv_obj_set_size(botLeftPageItinerary, lv_page_get_width_fit(botLeftPage), lv_page_get_height_fit(botLeftPage));
    lv_obj_add_style(botLeftPageItinerary, LV_CALENDAR_PART_BG, &blkBackground);
    lv_obj_add_style(botLeftPageItinerary, LV_PAGE_PART_BG, &bgBlendMode);

    /**************************************************************************/

    topLeftPageMonthLabel = lv_label_create(topLeftPageDay, NULL);
    lv_label_set_text(topLeftPageMonthLabel, "");
    lv_obj_add_style(topLeftPageMonthLabel, LV_LABEL_PART_MAIN, &mdDayFont);

    topLeftPageDayLabel = lv_label_create(topLeftPageDay, NULL);
    lv_label_set_text(topLeftPageDayLabel, "");
    lv_obj_add_style(topLeftPageDayLabel, LV_LABEL_PART_MAIN, &lgDayFont);

    topLeftPageYearLabel = lv_label_create(topLeftPageDay, NULL);
    lv_label_set_text(topLeftPageYearLabel, "");
    lv_obj_add_style(topLeftPageYearLabel, LV_LABEL_PART_MAIN, &mdDayFont);

    calendar = lv_calendar_create(rightPage, NULL);
    lv_obj_set_click(calendar, false);
    lv_obj_set_size(calendar, lv_obj_get_width_fit(rightPage), lv_obj_get_height_fit(rightPage));
    lv_obj_align(calendar, rightPage, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(calendar, LV_CALENDAR_PART_BG, &blkBackground);
    lv_obj_add_style(calendar, LV_CALENDAR_PART_BG, &bgBlendMode);
    lv_obj_set_style_local_text_font(calendar, LV_CALENDAR_PART_HEADER, LV_STATE_DEFAULT, &roboto_black_24);
    lv_obj_set_style_local_text_font(calendar, LV_CALENDAR_PART_DAY_NAMES, LV_STATE_DEFAULT, &roboto_black_16);
    lv_obj_set_style_local_text_font(calendar, LV_CALENDAR_PART_BG, LV_STATE_DEFAULT, &roboto_regular_12);

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

    lv_calendar_set_highlighted_dates(calendar, highlighted, sizeof(highlighted));

    uiDateLabels.day = topLeftPageDayLabel;
    uiDateLabels.month = topLeftPageMonthLabel;
    uiDateLabels.year = topLeftPageYearLabel;
    uiDateLabels.calendar = calendar;
    uiDateLabels.parent = topLeftPageDay;

    lv_task_create(updateCalendarCb, 750, LV_TASK_PRIO_HIGH, &uiDateLabels);

    ui_initialized = true;
    LV_LOG_INFO("ui_init ready");
}

void updateCalendarCb(lv_task_t *task) {
    // https://docs.lvgl.io/latest/en/html/overview/task.html#create-a-task
    // Set up a "user_data" struct containing the labels (and shadows) for the
    // date stuff needing updating.
    ui_date_labels_t *dateLabels = task->user_data;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char bufMonth[4], bufYear[5];
    lv_calendar_date_t today;

    strftime(bufMonth, sizeof(bufMonth), "%b", &tm);
    strftime(bufYear, sizeof(bufYear), "%EY", &tm);

    today.year = tm.tm_year + 1900;
    today.day = tm.tm_mday;
    today.month = tm.tm_mon + 1;

    lv_calendar_set_today_date(dateLabels->calendar, &today);
    lv_calendar_set_showed_date(dateLabels->calendar, &today);

    lv_label_set_text_fmt(dateLabels->month, "%s", bufMonth);
    lv_label_set_text_fmt(dateLabels->day, "%02d", tm.tm_mday);
    lv_label_set_text_fmt(dateLabels->year, "%s", bufYear);

    lv_obj_align(dateLabels->month, dateLabels->parent, LV_ALIGN_IN_TOP_MID, 0, DEFAULT_BORDER);
    lv_obj_align(dateLabels->day, dateLabels->parent, LV_ALIGN_CENTER, 0, DEFAULT_BORDER);
    lv_obj_align(dateLabels->year, dateLabels->parent, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
}

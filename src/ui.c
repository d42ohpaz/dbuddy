#include <stdio.h>
#include <time.h>
#include "ui.h"
#include "styles.h"

LV_IMG_DECLARE(tft_background_art)

void cb_calendar_event_handler(lv_obj_t *obj, lv_event_t event);

void update_calendar_day(Ui ui);

static Ui * p_Ui = NULL;

Ui *ui_init(void) {
    static Ui ui;
    static bool ui_initialized = false;

    if (ui_initialized) {
        LV_LOG_WARN("ui_init: already inited");
        return &ui;
    }

    styles_init();

    p_Ui = lv_mem_alloc(sizeof(Ui));
    p_Ui = &ui;

    ui.display = lv_disp_get_default();
    lv_disp_set_bg_image(ui.display, &tft_background_art);

    ui.screen = lv_scr_act();
    lv_obj_add_style(ui.screen, LV_OBJMASK_PART_MAIN, &style_default_background_transparent_full);

    ui.page.main = lv_page_create(ui.screen, NULL);
    lv_obj_set_size(ui.page.main, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_click(ui.page.main, false);
    lv_obj_add_style(ui.page.main, LV_PAGE_PART_BG, &style_default_border_none);
    lv_obj_add_style(ui.page.main, LV_PAGE_PART_BG, &style_default_padding_none);
    lv_obj_add_style(ui.page.main, LV_PAGE_PART_BG, &style_default_background_transparent_full);

    ui.page.left.main = lv_obj_create(ui.page.main, NULL);
    lv_obj_set_size(ui.page.left.main, (LV_HOR_RES * 1 / 3), LV_VER_RES);
    lv_obj_set_click(ui.page.left.main, false);
    lv_obj_add_style(ui.page.left.main, LV_OBJ_PART_MAIN, &style_default_border_none);
    lv_obj_add_style(ui.page.left.main, LV_OBJ_PART_MAIN, &style_default_background_transparent_full);

    ui.page.left.top.main = lv_page_create(ui.page.left.main, NULL);
    lv_obj_set_click(ui.page.left.top.main, false);
    lv_obj_set_size(ui.page.left.top.main, lv_obj_get_width(ui.page.left.main), lv_obj_get_width(ui.page.left.main) * 2 / 3);
    lv_obj_add_style(ui.page.left.top.main, LV_STATE_DEFAULT, &style_default_border_none);
    lv_obj_add_style(ui.page.left.top.main, LV_PAGE_PART_BG, &style_default_background_transparent_full);
    lv_obj_add_style(ui.page.left.top.main, LV_PAGE_PART_BG, &style_default_padding_default);

    ui.page.left.bottom.main = lv_page_create(ui.page.left.main, NULL);
    lv_obj_set_click(ui.page.left.bottom.main, false);
    lv_obj_set_pos(ui.page.left.bottom.main, 0, lv_obj_get_height(ui.page.left.top.main));
    lv_obj_set_size(ui.page.left.bottom.main, lv_obj_get_width(ui.page.left.main), lv_obj_get_height(ui.page.left.main) - lv_obj_get_height(ui.page.left.top.main));
    lv_obj_set_style_local_pad_top(ui.page.left.bottom.main, LV_PAGE_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui.page.left.bottom.main, LV_STATE_DEFAULT, &style_default_border_none);
    lv_obj_add_style(ui.page.left.bottom.main, LV_PAGE_PART_BG, &style_default_background_transparent_full);
    lv_obj_add_style(ui.page.left.bottom.main, LV_PAGE_PART_BG, &style_default_padding_default);

    ui.page.left.top.container = lv_obj_create(ui.page.left.top.main, NULL);
    lv_obj_set_click(ui.page.left.top.container, false);
    lv_obj_set_size(ui.page.left.top.container, lv_page_get_width_fit(ui.page.left.top.main), lv_page_get_height_fit(ui.page.left.top.main));
    lv_obj_add_style(ui.page.left.top.container, LV_CALENDAR_PART_BG, &style_default_background_color_black);
    lv_obj_add_style(ui.page.left.top.container, LV_PAGE_PART_BG, &style_default_background_overlay_color_black);
    lv_obj_add_style(ui.page.left.top.container, LV_CALENDAR_PART_BG, &style_default_border_none);

    ui.page.left.bottom.itinerary = lv_obj_create(ui.page.left.bottom.main, NULL);
    lv_obj_set_click(ui.page.left.bottom.itinerary, false);
    lv_obj_set_size(ui.page.left.bottom.itinerary, lv_page_get_width_fit(ui.page.left.bottom.main), lv_page_get_height_fit(ui.page.left.bottom.main));
    lv_obj_add_style(ui.page.left.bottom.itinerary, LV_CALENDAR_PART_BG, &style_default_background_color_black);
    lv_obj_add_style(ui.page.left.bottom.itinerary, LV_PAGE_PART_BG, &style_default_background_overlay_color_black);
    lv_obj_add_style(ui.page.left.bottom.itinerary, LV_CALENDAR_PART_BG, &style_default_border_none);

    ui.page.left.top.label_day = lv_label_create(ui.page.left.top.container, NULL);
    lv_label_set_text(ui.page.left.top.label_day, "");
    lv_obj_add_style(ui.page.left.top.label_day, LV_LABEL_PART_MAIN, &style_default_font_black_large);

    ui.page.left.top.label_month = lv_label_create(ui.page.left.top.container, NULL);
    lv_label_set_text(ui.page.left.top.label_month, "");
    lv_obj_add_style(ui.page.left.top.label_month, LV_LABEL_PART_MAIN, &style_default_font_black_medium);

    ui.page.left.top.label_year = lv_label_create(ui.page.left.top.container, NULL);
    lv_label_set_text(ui.page.left.top.label_year, "");
    lv_obj_add_style(ui.page.left.top.label_year, LV_LABEL_PART_MAIN, &style_default_font_black_medium);

    ui.page.right.main = lv_obj_create(ui.page.main, NULL);
    lv_obj_set_click(ui.page.right.main, false);
    lv_obj_set_size(ui.page.right.main, (LV_HOR_RES * 2 / 3), LV_VER_RES);
    lv_obj_set_pos(ui.page.right.main, lv_obj_get_width(ui.page.left.main), 0);
    lv_obj_add_style(ui.page.right.main, LV_PAGE_PART_BG, &style_default_padding_default);
    lv_obj_add_style(ui.page.right.main, LV_OBJ_PART_MAIN, &style_default_border_none);
    lv_obj_add_style(ui.page.right.main, LV_OBJ_PART_MAIN, &style_default_background_transparent_full);

    ui.page.right.calendar = lv_calendar_create(ui.page.right.main, NULL);
    lv_obj_set_size(ui.page.right.calendar, lv_obj_get_width_fit(ui.page.right.main), lv_obj_get_height_fit(ui.page.right.main));
    lv_obj_align(ui.page.right.calendar, ui.page.right.main, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(ui.page.right.calendar, LV_CALENDAR_PART_BG, &style_default_background_color_black);
    lv_obj_add_style(ui.page.right.calendar, LV_CALENDAR_PART_BG, &style_default_background_overlay_color_black);
    lv_obj_add_style(ui.page.right.calendar, LV_CALENDAR_PART_BG, &style_default_border_none);
    lv_obj_add_style(ui.page.right.calendar, LV_CALENDAR_PART_DATE, &style_focused_background_blend_mode_additive);
    lv_obj_add_style(ui.page.right.calendar, LV_CALENDAR_PART_DATE, &style_focused_background_color_purple);
    lv_obj_add_style(ui.page.right.calendar, LV_CALENDAR_PART_DATE, &style_focused_text_color_black);

    lv_obj_set_style_local_text_font(ui.page.right.calendar, LV_CALENDAR_PART_HEADER, LV_STATE_DEFAULT, &roboto_black_24);
    lv_obj_set_style_local_text_font(ui.page.right.calendar, LV_CALENDAR_PART_DAY_NAMES, LV_STATE_DEFAULT, &roboto_black_16);
    lv_obj_set_style_local_text_font(ui.page.right.calendar, LV_CALENDAR_PART_BG, LV_STATE_DEFAULT, &roboto_regular_12);

    update_calendar_day(ui);
    lv_obj_set_event_cb(ui.page.right.calendar, cb_calendar_event_handler);

    ui_initialized = true;
    LV_LOG_INFO("ui_init ready");

    return &ui;
}

void cb_calendar_event_handler(lv_obj_t *obj, lv_event_t event) {
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t *date = lv_calendar_get_pressed_date(obj);

        if (date) {
            p_Ui->page.right.current.month = date->month;
            p_Ui->page.right.current.day = date->day;
            p_Ui->page.right.current.year = date->year;

            update_calendar_day(*p_Ui);
        }
    }
}

void update_calendar_day(Ui ui) {
    lv_calendar_date_t current = ui.page.right.current;

    if (current.year == 0 && current.month == 0 && current.day == 0) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        current.year = tm.tm_year + 1900;
        current.day = tm.tm_mday;
        current.month = tm.tm_mon + 1;
    }

    lv_calendar_set_today_date(ui.page.right.calendar, &current);
    lv_calendar_set_showed_date(ui.page.right.calendar, &current);

    struct tm tm;
    char bufMonth[4], bufYear[5];

    tm.tm_mon = current.month - 1;
    tm.tm_mday = current.day + 0;
    tm.tm_year = current.year - 1900;

    strftime(bufMonth, sizeof(bufMonth), "%b", &tm);
    strftime(bufYear, sizeof(bufYear), "%EY", &tm);

    lv_label_set_text_fmt(ui.page.left.top.label_month, "%s", bufMonth);
    lv_label_set_text_fmt(ui.page.left.top.label_day, "%02d", tm.tm_mday);
    lv_label_set_text_fmt(ui.page.left.top.label_year, "%s", bufYear);

    lv_obj_align(ui.page.left.top.label_month, ui.page.left.top.container, LV_ALIGN_IN_TOP_MID, 0, DEFAULT_BORDER);
    lv_obj_align(ui.page.left.top.label_day, ui.page.left.top.container, LV_ALIGN_CENTER, 0, DEFAULT_BORDER);
    lv_obj_align(ui.page.left.top.label_year, ui.page.left.top.container, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
}

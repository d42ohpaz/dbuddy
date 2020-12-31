#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ui.h"
#include "styles.h"
#include "fonts.h"
#include "ui/settings.h"

void create_obj_left_top_container_day(ui_t *);
void create_obj_left_top_container_month(ui_t *);
void create_obj_left_top_container_year(ui_t *);
void create_obj_top_container_actions(ui_t *);
void create_obj_top_container_time(ui_t *);

void create_page_left_bottom_itinerary(ui_t *);
void create_page_left_bottom_main(ui_t *);
void create_page_left_main(ui_t *);
void create_page_left_top_container(ui_t *);
void create_page_left_top_main(ui_t *);
void create_page_main(ui_t *);
void create_page_right_calendar(ui_t *);
void create_page_right_main(ui_t *);
void create_page_top_container(ui_t *);
void create_page_top_main(ui_t *);

void create_screen(ui_t *);

void cb_action_settings_event_handler(lv_obj_t * obj, lv_event_t event);
void cb_calendar_event_handler(lv_obj_t * obj, lv_event_t event);
void cb_time_task_handler(lv_task_t * task);

void update_calendar(ui_t ui);
void update_time(ui_t ui);

static ui_t * p_Ui;

configuration_t * p_config;
settings_handler handler;

void ui_init(configuration_t * config, settings_handler settings_handler) {
    static bool ui_initialized = false;

    if (ui_initialized) {
        LV_LOG_WARN("ui_init: already inited");
        return;
    }

    p_config = config;
    handler = settings_handler;

    p_Ui = malloc(sizeof(ui_t));

    // Initialize the date struct since it sometimes fills with random data.
    p_Ui->date.year = 0;
    p_Ui->date.month = 0;
    p_Ui->date.day = 0;

    styles_init();
    font_init();

    create_screen(p_Ui);
    create_page_main(p_Ui);
    create_page_top_main(p_Ui);
    create_page_right_main(p_Ui);
    create_page_top_container(p_Ui);
    create_obj_top_container_time(p_Ui);
    create_obj_top_container_actions(p_Ui);
    create_page_left_main(p_Ui);
    create_page_left_top_main(p_Ui);
    create_page_left_top_container(p_Ui);
    create_obj_left_top_container_month(p_Ui);
    create_obj_left_top_container_day(p_Ui);
    create_obj_left_top_container_year(p_Ui);
    create_page_left_bottom_main(p_Ui);
    create_page_left_bottom_itinerary(p_Ui);
    create_page_right_calendar(p_Ui);

    ui_initialized = true;
    LV_LOG_INFO("ui_init ready");
}

void cb_action_settings_event_handler(lv_obj_t * obj, lv_event_t event) {
    if (lv_debug_check_obj_valid(obj) && event == LV_EVENT_RELEASED) {
        settings_init(p_config, handler);
    }
}

void cb_calendar_event_handler(lv_obj_t * obj, lv_event_t event) {
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t * date = lv_calendar_get_pressed_date(obj);

        if (date) {
            p_Ui->date.month = date->month;
            p_Ui->date.day = date->day;
            p_Ui->date.year = date->year;

            update_calendar(*p_Ui);
        }
    }
}

void cb_time_task_handler(lv_task_t * task) {
    ui_t ui = *(ui_t *) (task->user_data);
    update_time(ui);
}

void create_obj_left_top_container_day(ui_t * ui) {
    ui->page.left.top.container_day = lv_obj_create(ui->page.left.top.container, ui->page.main);
    lv_obj_set_size(ui->page.left.top.container_day, lv_obj_get_width_fit(ui->page.left.top.container) / 3, lv_obj_get_height_fit(ui->page.left.top.container));
    lv_obj_set_pos(ui->page.left.top.container_day, lv_obj_get_width_fit(ui->page.left.top.container_month), 0);

    ui->page.left.top.label_day = lv_label_create(ui->page.left.top.container_day, NULL);
    lv_label_set_text(ui->page.left.top.label_day, "");
    lv_obj_set_auto_realign(ui->page.left.top.label_day, true);
    lv_obj_align(ui->page.left.top.label_day, ui->page.left.top.container_day, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(ui->page.left.top.label_day, LV_LABEL_PART_MAIN, &style_default_font_black_xxlarge);
}

void create_obj_left_top_container_month(ui_t * ui) {
    ui->page.left.top.container_month = lv_obj_create(ui->page.left.top.container, ui->page.main);
    lv_obj_set_size(ui->page.left.top.container_month, lv_obj_get_width_fit(ui->page.left.top.container) / 3, lv_obj_get_height_fit(ui->page.left.top.container));

    ui->page.left.top.label_month = lv_label_create(ui->page.left.top.container_month, NULL);
    lv_label_set_text(ui->page.left.top.label_month, "");
    lv_obj_set_auto_realign(ui->page.left.top.label_month, true);
    lv_obj_align(ui->page.left.top.label_month, ui->page.left.top.container_month, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(ui->page.left.top.label_month, LV_LABEL_PART_MAIN, &style_default_font_black_medium);
}

void create_obj_left_top_container_year(ui_t * ui) {
    ui->page.left.top.container_year = lv_obj_create(ui->page.left.top.container, ui->page.main);
    lv_obj_set_size(ui->page.left.top.container_year, lv_obj_get_width_fit(ui->page.left.top.container) / 3, lv_obj_get_height_fit(ui->page.left.top.container));
    lv_obj_set_pos(ui->page.left.top.container_year, lv_obj_get_width_fit(ui->page.left.top.container_month) + lv_obj_get_width_fit(ui->page.left.top.container_day), 0);

    ui->page.left.top.label_year = lv_label_create(ui->page.left.top.container_year, NULL);
    lv_label_set_text(ui->page.left.top.label_year, "");
    lv_obj_set_auto_realign(ui->page.left.top.label_year, true);
    lv_label_set_long_mode(ui->page.left.top.label_year, LV_LABEL_LONG_BREAK);
    lv_obj_set_size(ui->page.left.top.label_year, lv_obj_get_width_fit(ui->page.left.top.container_year), lv_obj_get_height(ui->page.left.top.container_year));
    lv_label_set_align(ui->page.left.top.label_year, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(ui->page.left.top.label_year, ui->page.left.top.container_year, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(ui->page.left.top.label_year, LV_LABEL_PART_MAIN, &style_default_font_black_medium);
}

void create_obj_top_container_actions(ui_t * ui) {
    ui->page.top.container_actions = lv_obj_create(ui->page.top.container, ui->page.top.main);

    lv_obj_set_size(ui->page.top.container_actions, (lv_obj_get_width_fit(ui->page.top.main) - DEFAULT_PADDING * 4) / 2, lv_obj_get_height_fit(ui->page.top.main));
    lv_obj_set_pos(ui->page.top.container_actions, lv_obj_get_width(ui->page.top.container_time), 0);

    lv_obj_add_style(ui->page.top.container_actions, LV_OBJ_PART_MAIN, &style_default_background_transparent_full);

    ui->page.top.btn_action_settings = lv_btn_create(ui->page.top.container_actions, NULL);
    lv_obj_set_size(ui->page.top.btn_action_settings, lv_obj_get_width_fit(ui->page.top.container_actions) / 12, lv_obj_get_height_fit(ui->page.top.container_actions));
    lv_obj_align(ui->page.top.btn_action_settings, ui->page.top.container_actions, LV_ALIGN_IN_RIGHT_MID, 0, 0);
    lv_obj_reset_style_list(ui->page.top.btn_action_settings, LV_BTN_PART_MAIN);

    lv_obj_t * label = lv_label_create(ui->page.top.btn_action_settings, NULL);
    lv_label_set_text(label, LV_SYMBOL_SETTINGS);
    lv_obj_set_auto_realign(label, true);
    lv_obj_align(label, ui->page.top.container_actions, LV_ALIGN_IN_RIGHT_MID, 0, 0);
    lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style_default_font_regular_small);

    lv_obj_set_style_local_text_color(ui->page.top.btn_action_settings, LV_LABEL_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_AQUA);
    lv_obj_set_event_cb(ui->page.top.btn_action_settings, cb_action_settings_event_handler);
}

void create_obj_top_container_time(ui_t * ui) {
    ui->page.top.container_time = lv_obj_create(ui->page.top.container, NULL);
    lv_obj_set_size(ui->page.top.container_time, lv_obj_get_width_fit(ui->page.top.main) / 2, lv_obj_get_height_fit(ui->page.top.main));

    lv_obj_add_style(ui->page.top.container_time, LV_OBJ_PART_MAIN, &style_default_border_none);
    lv_obj_add_style(ui->page.top.container_time, LV_OBJ_PART_MAIN, &style_default_background_transparent_full);

    ui->page.top.label_time = lv_label_create(ui->page.top.container_time, NULL);
    lv_label_set_text(ui->page.top.label_time, "");
    lv_obj_set_auto_realign(ui->page.top.label_time, true);
    lv_obj_align(ui->page.top.label_time, ui->page.top.container_time, LV_ALIGN_IN_LEFT_MID, DEFAULT_PADDING / 2, 0);
    lv_obj_add_style(ui->page.top.label_time, LV_LABEL_PART_MAIN, &style_default_font_regular_small);

    lv_task_create(cb_time_task_handler, 500, LV_TASK_PRIO_MID, ui);
}

void create_page_left_bottom_itinerary(ui_t * ui) {
    ui->page.left.bottom.itinerary = lv_obj_create(ui->page.left.bottom.main, NULL);

    lv_obj_set_size(ui->page.left.bottom.itinerary, lv_page_get_width_fit(ui->page.left.bottom.main), lv_page_get_height_fit(ui->page.left.bottom.main));
    lv_obj_add_style(ui->page.left.bottom.itinerary, LV_PAGE_PART_BG, &style_default_background_overlay);
    lv_obj_add_style(ui->page.left.bottom.itinerary, LV_PAGE_PART_BG, &style_default_radius_none);
    lv_obj_add_style(ui->page.left.bottom.itinerary, LV_PAGE_PART_BG, &style_default_border_color_white);
    lv_obj_add_style(ui->page.left.bottom.itinerary, LV_PAGE_PART_BG, &style_focused_border_color_white);
    lv_obj_add_style(ui->page.left.bottom.itinerary, LV_PAGE_PART_BG, &style_default_border_sides_only_top);
}

void create_page_left_bottom_main(ui_t * ui) {
    ui->page.left.bottom.main = lv_page_create(ui->page.left.main, ui->page.main);

    lv_obj_set_pos(ui->page.left.bottom.main, 0, lv_obj_get_height(ui->page.left.top.main));
    lv_obj_set_size(ui->page.left.bottom.main, lv_obj_get_width(ui->page.left.main), lv_obj_get_height(ui->page.left.main) - lv_obj_get_height(ui->page.left.top.main));
    lv_obj_set_style_local_pad_top(ui->page.left.bottom.main, LV_PAGE_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(ui->page.left.bottom.main, LV_PAGE_PART_BG, &style_default_padding_default);
}

void create_page_left_main(ui_t * ui) {
    ui->page.left.main = lv_obj_create(ui->page.main, ui->page.main);

    lv_obj_set_size(ui->page.left.main, (LV_HOR_RES * 1 / 3), LV_VER_RES - lv_obj_get_height(ui->page.top.main));
    lv_obj_align(ui->page.left.main, ui->page.main, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0);
}

void create_page_left_top_container(ui_t * ui) {
    ui->page.left.top.container = lv_obj_create(ui->page.left.top.main, ui->page.main);

    lv_obj_set_size(ui->page.left.top.container, lv_page_get_width_fit(ui->page.left.top.main), lv_page_get_height_fit(ui->page.left.top.main));
    lv_obj_add_style(ui->page.left.top.container, LV_PAGE_PART_BG, &style_default_background_overlay);
}

void create_page_left_top_main(ui_t * ui) {
    ui->page.left.top.main = lv_page_create(ui->page.left.main, ui->page.main);

    lv_obj_set_size(ui->page.left.top.main, lv_obj_get_width(ui->page.left.main), (lv_obj_get_width(ui->page.left.main) * 2 / 3) - DEFAULT_PADDING * 6);
    lv_obj_add_style(ui->page.left.top.main, LV_PAGE_PART_BG, &style_default_padding_default);
}

void create_page_main(ui_t * ui) {
    ui->page.main = lv_page_create(ui->screen, NULL);

    lv_obj_set_size(ui->page.main, LV_HOR_RES, LV_VER_RES);
    lv_obj_add_style(ui->page.main, LV_PAGE_PART_BG, &style_default_border_none);
    lv_obj_add_style(ui->page.main, LV_PAGE_PART_BG, &style_default_padding_none);
    lv_obj_add_style(ui->page.main, LV_PAGE_PART_BG, &style_default_background_transparent_full);
}

void create_page_right_calendar(ui_t * ui) {
    ui->page.right.container = lv_obj_create(ui->page.right.main, ui->page.main);
    lv_obj_set_size(ui->page.right.container, lv_obj_get_width_fit(ui->page.right.main), lv_obj_get_height_fit(ui->page.right.main));
    lv_obj_add_style(ui->page.right.container, LV_PAGE_PART_BG, &style_default_padding_default);
    lv_obj_add_style(ui->page.right.container, LV_PAGE_PART_BG, &style_default_padding_left_none);

    ui->page.right.calendar = lv_calendar_create(ui->page.right.container, NULL);
    lv_obj_set_size(ui->page.right.calendar, lv_obj_get_width_fit(ui->page.right.container), lv_obj_get_height_fit(ui->page.right.container));
    lv_obj_align(ui->page.right.calendar, ui->page.right.main, LV_ALIGN_IN_LEFT_MID, 0, 0);
    lv_obj_add_style(ui->page.right.calendar, LV_CALENDAR_PART_BG, &style_default_background_overlay);
    lv_obj_add_style(ui->page.right.calendar, LV_CALENDAR_PART_DATE, &style_focused_background_blend_mode_additive);
    lv_obj_add_style(ui->page.right.calendar, LV_CALENDAR_PART_DATE, &style_focused_background_color_purple);
    lv_obj_add_style(ui->page.right.calendar, LV_CALENDAR_PART_DATE, &style_focused_text_color_black);
    lv_obj_add_style(ui->page.right.calendar, LV_PAGE_PART_BG, &style_default_border_color_white);
    lv_obj_add_style(ui->page.right.calendar, LV_PAGE_PART_BG, &style_focused_border_color_white);
    lv_obj_add_style(ui->page.right.calendar, LV_PAGE_PART_BG, &style_default_border_sides_only_left);
    lv_obj_add_style(ui->page.right.calendar, LV_PAGE_PART_BG, &style_default_radius_none);

    lv_obj_add_style(ui->page.right.calendar, LV_CALENDAR_PART_HEADER, &style_default_font_black_medium);
    lv_obj_add_style(ui->page.right.calendar, LV_CALENDAR_PART_DAY_NAMES, &style_default_font_black_small);
    lv_obj_add_style(ui->page.right.calendar, LV_CALENDAR_PART_BG, &style_default_font_regular_xsmall);

    lv_obj_set_event_cb(ui->page.right.calendar, cb_calendar_event_handler);

    update_calendar(*ui);
}

void create_page_right_main(ui_t * ui) {
    ui->page.right.main = lv_obj_create(ui->page.main, ui->page.main);

    lv_obj_set_size(ui->page.right.main, (LV_HOR_RES * 2 / 3), LV_VER_RES - lv_obj_get_height(ui->page.top.main));
    lv_obj_align(ui->page.right.main, ui->page.main, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
}

void create_page_top_container(ui_t * ui) {
    ui->page.top.container = lv_obj_create(ui->page.top.main, NULL);

    lv_obj_set_size(ui->page.top.container, lv_obj_get_width_fit(ui->page.top.main) - DEFAULT_PADDING * 2, lv_obj_get_height_fit(ui->page.top.main));
    lv_obj_align(ui->page.top.container, ui->page.top.main, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_style(ui->page.top.container, LV_OBJ_PART_MAIN, &style_default_padding_default);
    lv_obj_add_style(ui->page.top.container, LV_OBJ_PART_MAIN, &style_default_radius_none);
    lv_obj_add_style(ui->page.top.container, LV_OBJ_PART_MAIN, &style_default_background_transparent_full);
    lv_obj_add_style(ui->page.top.container, LV_PAGE_PART_BG, &style_default_border_color_white);
    lv_obj_add_style(ui->page.top.container, LV_PAGE_PART_BG, &style_focused_border_color_white);
    lv_obj_add_style(ui->page.top.container, LV_OBJ_PART_MAIN, &style_default_border_sides_only_bottom);
}

void create_page_top_main(ui_t * ui) {
    ui->page.top.main = lv_obj_create(ui->page.main, ui->page.main);

    lv_obj_set_size(ui->page.top.main, LV_HOR_RES, DEFAULT_MENU_HEIGHT + DEFAULT_PADDING);

    lv_obj_add_style(ui->page.top.main, LV_OBJ_PART_MAIN, &style_default_radius_none);
    lv_obj_add_style(ui->page.top.main, LV_OBJ_PART_MAIN, &style_default_background_overlay);
}

void create_screen(ui_t * ui) {
    ui->screen = lv_scr_act();

    lv_obj_add_style(ui->screen, LV_OBJMASK_PART_MAIN, &style_default_background_color_blue);
    lv_obj_add_style(ui->screen, LV_OBJMASK_PART_MAIN, &style_default_background_transparent_cover);
}

void update_calendar(ui_t ui) {
    lv_calendar_date_t date = ui.date;
    time_t t = time(NULL);
    struct tm local = *localtime(&t);

    if (date.year == 0 && date.month == 0 && date.day == 0) {
        date.year = local.tm_year + 1900;
        date.day = local.tm_mday;
        date.month = local.tm_mon + 1;
    }

    lv_calendar_set_today_date(ui.page.right.calendar, &date);
    lv_calendar_set_showed_date(ui.page.right.calendar, &date);

    char bufDay[4], bufMonth[4], bufYear[3], bufCentury[3], selected[11];

    sprintf(selected, "%d-%d-%d", date.year, date.month, date.day);
    strptime(selected, "%Y-%m-%d", &local);

    strftime(bufDay, sizeof(bufDay), "%a", &local);
    strftime(bufMonth, sizeof(bufMonth), "%b", &local);
    strftime(bufYear, sizeof(bufYear), "%y", &local);
    strftime(bufCentury, sizeof(bufCentury), "%C", &local);

    lv_label_set_text_fmt(ui.page.left.top.label_month, "%s\n%s", bufDay, bufMonth);
    lv_label_set_text_fmt(ui.page.left.top.label_day, "%02u", local.tm_mday);
    lv_label_set_text_fmt(ui.page.left.top.label_year, "%s\n%s", bufCentury, bufYear);
}

void update_time(ui_t ui) {
    time_t t = time(NULL);
    struct tm local = *localtime(&t);
    char bufMeridiem[3] = "";
    int tmHour = local.tm_hour;

    if (p_config->time.format24 == 0) {
        if (p_config->time.meridiem == 1) {
            if (local.tm_hour >= 12) {
                sprintf(bufMeridiem, "%s", "pm");
            } else {
                sprintf(bufMeridiem, "%s", "am");
            }
        }

        if (tmHour > 12) {
            tmHour = tmHour - 12;
        }
    }

    static int count_on = 0, count_off = 0;
    char * colon = strstr(lv_label_get_text(ui.page.top.label_time), ":");

    if (((count_on % 2) == 0 && colon == NULL) || (p_config->time.flash == 0)) {
        lv_label_set_text_fmt(ui.page.top.label_time, "%02u:%02u %s", tmHour, local.tm_min, bufMeridiem);

        count_on = 0;
    } else if ((count_off % 2) == 0) {
        lv_label_set_text_fmt(ui.page.top.label_time, "%02u %02u %s", tmHour, local.tm_min, bufMeridiem);

        count_off = 0;
    }

    count_off++;
    count_on++;
}

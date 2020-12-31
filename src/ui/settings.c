#include <stdlib.h>

#include "lvgl/lvgl.h"

#include "settings.h"

#include "../styles.h"
#include "../fonts.h"

void cb_list_btn_general(lv_obj_t * obj, lv_event_t event);
void cb_list_btn_calendars(lv_obj_t * obj, lv_event_t event);
void cb_settings_btnmatrix(lv_obj_t * obj, lv_event_t event);
void cb_toggle_switch(lv_obj_t * obj, lv_event_t event);
void cb_settings_win_close(lv_obj_t * obj, lv_event_t event);
void cb_settings_win_msgbox(lv_obj_t * obj, lv_event_t event);

lv_coord_t get_next_row_pos(lv_obj_t * obj, int padding);

void update_toggle_switches(void);

typedef struct ui_settings_general_t {
    lv_obj_t * main;

    lv_obj_t * toggle_format;
    lv_obj_t * toggle_meridiem;
    lv_obj_t * toggle_flash;
    lv_obj_t * toggle_screensaver;
} ui_settings_general_t;

typedef struct ui_settings_calendars_t {
    lv_obj_t * main;
} ui_settings_calendars_t;

typedef struct ui_settings_t {
    lv_obj_t * main;
    lv_obj_t * overlay;
    lv_obj_t * list;
    lv_obj_t * btn_close;
    lv_obj_t * action_btns;

    lv_coord_t header_offset;

    union {
        ui_settings_general_t general;
        ui_settings_calendars_t calendars;
    };
} ui_settings_t;

configuration_t * p_config;
configuration_t config;

lv_obj_t * msgbox = NULL;

ui_settings_t * p_settings = NULL;
settings_handler shandler = NULL;

void settings_init(configuration_t * u_config, settings_handler handler) {
    p_settings = malloc(sizeof(ui_settings_t));
    shandler = handler;

    lv_obj_t * screen = lv_scr_act();

    p_config = u_config;
    config = *u_config;

    // Overlay to simulate a modal dialog
    p_settings->overlay = lv_obj_create(screen, NULL);
    lv_obj_set_size(p_settings->overlay, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_pos(p_settings->overlay, 0, 0);
    lv_obj_add_style(p_settings->overlay, LV_OBJ_PART_MAIN, &style_default_background_overlay);
    lv_obj_add_style(p_settings->overlay, LV_OBJ_PART_MAIN, &style_default_border_none);

    // Settings window
    p_settings->main = lv_win_create(screen, NULL);
    lv_obj_set_size(p_settings->main, lv_obj_get_width_fit(screen) - DEFAULT_MENU_HEIGHT - (DEFAULT_PADDING * 2), lv_obj_get_height_fit(screen) - DEFAULT_MENU_HEIGHT - (DEFAULT_PADDING * 2));
    lv_obj_align(p_settings->main, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_style(p_settings->main, LV_WIN_PART_HEADER, &style_default_background_color_black);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_HEADER, &style_default_border_color_white);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_HEADER, &style_default_border_sides_only_bottom);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_HEADER, &style_default_border_thin);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_HEADER, &style_default_font_regular_small);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_HEADER, &style_default_padding_top_none);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_HEADER, &style_default_padding_right_none);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_HEADER, &style_default_padding_bottom_none);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_BG, &style_default_background_color_black);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_BG, &style_default_radius_normal);
    lv_obj_add_style(p_settings->main, LV_WIN_PART_CONTENT_SCROLLABLE, &style_default_padding_none);

    lv_win_set_title(p_settings->main, "Settings");

    p_settings->btn_close = lv_win_add_btn(p_settings->main, LV_SYMBOL_CLOSE);
    lv_obj_set_event_cb(p_settings->btn_close, cb_settings_win_close);

    if (p_settings->main) {
        lv_win_ext_t * win_ext = lv_obj_get_ext_attr(p_settings->main);
        p_settings->header_offset = lv_obj_get_height_fit(win_ext->header);

        p_settings->list = lv_list_create(p_settings->main, NULL);
        lv_obj_set_size(p_settings->list, DEFAULT_LIST_WIDTH, lv_obj_get_height_fit(p_settings->main) - p_settings->header_offset);
        lv_obj_add_style(p_settings->list, LV_LIST_PART_BG, &style_default_border_none);
        lv_obj_add_style(p_settings->list, LV_LIST_PART_BG, &style_default_background_transparent_full);
        lv_obj_add_style(p_settings->list, LV_LIST_PART_BG, &style_default_border_sides_only_right);
        lv_obj_add_style(p_settings->list, LV_LIST_PART_BG, &style_default_border_color_white);
        lv_obj_add_style(p_settings->list, LV_LIST_PART_BG, &style_default_border_thin);
        lv_obj_add_style(p_settings->list, LV_LIST_PART_BG, &style_default_radius_none);
        lv_obj_add_style(p_settings->list, LV_LIST_PART_BG, &style_focused_border_color_white);

        lv_obj_t * btn_general = lv_list_add_btn(p_settings->list, NULL, "General");
        lv_obj_add_style(btn_general, LV_BTN_PART_MAIN, &style_default_border_none);
        lv_obj_add_style(btn_general, LV_BTN_PART_MAIN, &style_default_background_transparent_full);
        lv_obj_set_style_local_outline_width(btn_general, LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);
        lv_obj_set_style_local_border_side(btn_general, LV_BTN_PART_MAIN, LV_STATE_FOCUSED, LV_BORDER_SIDE_LEFT);
        lv_obj_set_style_local_border_color(btn_general, LV_BTN_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_WHITE);
        lv_obj_set_style_local_border_width(btn_general, LV_BTN_PART_MAIN, LV_STATE_FOCUSED, DEFAULT_BORDER * 2);
        lv_obj_set_style_local_pad_ver(btn_general, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, DEFAULT_PADDING * 2);
        lv_obj_set_event_cb(btn_general, cb_list_btn_general);

        lv_obj_t * btn_calendars = lv_list_add_btn(p_settings->list, NULL, "Calendars");
        lv_obj_add_style(btn_calendars, LV_BTN_PART_MAIN, &style_default_border_none);
        lv_obj_add_style(btn_calendars, LV_BTN_PART_MAIN, &style_default_background_transparent_full);
        lv_obj_set_style_local_outline_width(btn_calendars, LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);
        lv_obj_set_style_local_border_side(btn_calendars, LV_BTN_PART_MAIN, LV_STATE_FOCUSED, LV_BORDER_SIDE_LEFT);
        lv_obj_set_style_local_border_color(btn_calendars, LV_BTN_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_WHITE);
        lv_obj_set_style_local_border_width(btn_calendars, LV_BTN_PART_MAIN, LV_STATE_FOCUSED, DEFAULT_BORDER * 2);
        lv_obj_set_style_local_pad_ver(btn_calendars, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, DEFAULT_PADDING * 2);
        lv_obj_set_event_cb(btn_calendars, cb_list_btn_calendars);

        lv_obj_t * actions_bar = lv_obj_create(p_settings->main, NULL);
        lv_obj_set_width(actions_bar, lv_obj_get_width(p_settings->main) - lv_obj_get_width(p_settings->list));
        lv_obj_align(actions_bar, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
        lv_obj_add_style(actions_bar, LV_OBJ_PART_MAIN, &style_default_border_none);
        lv_obj_add_style(actions_bar, LV_OBJ_PART_MAIN, &style_default_background_transparent_full);

        static const char * btns[] = {"Cancel", "Save", ""};

        p_settings->action_btns = lv_btnmatrix_create(actions_bar, NULL);
        lv_obj_set_height(p_settings->action_btns, lv_obj_get_height(actions_bar));
        lv_obj_align(p_settings->action_btns, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 0);
        lv_obj_add_style(p_settings->action_btns, LV_BTNMATRIX_PART_BG, &style_default_border_none);
        lv_obj_add_style(p_settings->action_btns, LV_BTNMATRIX_PART_BG, &style_default_background_transparent_full);
        lv_obj_add_style(p_settings->action_btns, LV_BTNMATRIX_PART_BTN, &style_default_border_color_white);
        lv_obj_add_style(p_settings->action_btns, LV_BTNMATRIX_PART_BTN, &style_default_background_color_black);
        lv_obj_add_style(p_settings->action_btns, LV_BTNMATRIX_PART_BTN, &style_pressed_background_color_white);
        lv_obj_add_style(p_settings->action_btns, LV_BTNMATRIX_PART_BTN, &style_pressed_text_color_black);

        lv_btnmatrix_set_map(p_settings->action_btns, btns);
        lv_obj_set_event_cb(p_settings->action_btns, cb_settings_btnmatrix);

        p_settings->header_offset = p_settings->header_offset + lv_obj_get_height(actions_bar);

        lv_list_focus_btn(p_settings->list, btn_general);
        lv_event_send(btn_general, LV_EVENT_RELEASED, NULL);
    }
}

void cb_list_btn_general(lv_obj_t * obj, lv_event_t event) {
    if (lv_debug_check_obj_type(obj, "lv_btn") && event == LV_EVENT_RELEASED) {
        if (p_settings->calendars.main && lv_debug_check_obj_valid(p_settings->calendars.main)) {
            lv_obj_del(p_settings->calendars.main);
            p_settings->calendars.main = NULL;
        }

        p_settings->general.main = lv_page_create(p_settings->main, NULL);
        lv_obj_set_size(p_settings->general.main, lv_obj_get_width_fit(p_settings->main) - DEFAULT_LIST_WIDTH, lv_obj_get_height_fit(p_settings->main) - p_settings->header_offset);
        lv_obj_set_pos(p_settings->general.main, DEFAULT_LIST_WIDTH, 0);
        lv_obj_add_style(p_settings->general.main, LV_STATE_DEFAULT, &style_default_border_none);
        lv_obj_add_style(p_settings->general.main, LV_STATE_DEFAULT, &style_default_background_transparent_full);
        lv_obj_add_style(p_settings->general.main, LV_STATE_DEFAULT, &style_default_padding_default);

        lv_obj_t * heading_time = lv_obj_create(p_settings->general.main, NULL);
        lv_obj_set_width(heading_time, lv_obj_get_width_fit(p_settings->general.main));
        lv_obj_add_style(heading_time, LV_OBJ_PART_MAIN, &style_default_border_sides_only_bottom);
        lv_obj_add_style(heading_time, LV_OBJ_PART_MAIN, &style_default_border_thin);
        lv_obj_add_style(heading_time, LV_OBJ_PART_MAIN, &style_default_radius_none);
        lv_obj_add_style(heading_time, LV_OBJ_PART_MAIN, &style_default_background_transparent_full);

        lv_obj_t * heading_label = lv_label_create(heading_time, NULL);
        lv_label_set_text(heading_label, "Time");

        lv_obj_set_height(heading_time, lv_obj_get_height(heading_label));

        lv_obj_t * row_format = lv_label_create(p_settings->general.main, NULL);
        lv_label_set_long_mode(row_format, LV_LABEL_LONG_BREAK);
        lv_obj_set_width(row_format, lv_obj_get_width_fit(p_settings->general.main));
        lv_label_set_text(row_format, "24-hour Formatting (e.g., 16:00)");
        lv_obj_set_pos(row_format, 0, get_next_row_pos(heading_time, DEFAULT_PADDING));

        p_settings->general.toggle_format = lv_switch_create(p_settings->general.main, NULL);
        lv_obj_set_event_cb(p_settings->general.toggle_format, cb_toggle_switch);
        lv_obj_align(p_settings->general.toggle_format, row_format, LV_ALIGN_IN_RIGHT_MID, 0, 0);

        lv_obj_t * row_meridiem = lv_label_create(p_settings->general.main, NULL);
        lv_label_set_long_mode(row_meridiem, LV_LABEL_LONG_BREAK);
        lv_obj_set_width(row_meridiem, lv_obj_get_width_fit(p_settings->general.main));
        lv_label_set_text(row_meridiem, "Use Meridiem (e.g., am/pm)");
        lv_obj_set_pos(row_meridiem, 0, get_next_row_pos(row_format, DEFAULT_PADDING * 2));

        p_settings->general.toggle_meridiem = lv_switch_create(p_settings->general.main, NULL);
        lv_obj_set_event_cb(p_settings->general.toggle_meridiem, cb_toggle_switch);
        lv_obj_align(p_settings->general.toggle_meridiem, row_meridiem, LV_ALIGN_IN_RIGHT_MID, 0, 0);

        lv_obj_t * row_flash_colon = lv_label_create(p_settings->general.main, NULL);
        lv_label_set_long_mode(row_flash_colon, LV_LABEL_LONG_BREAK);
        lv_obj_set_width(row_flash_colon, lv_obj_get_width_fit(p_settings->general.main));
        lv_label_set_text(row_flash_colon, "Flash the Time Separators");
        lv_obj_set_pos(row_flash_colon, 0, get_next_row_pos(row_meridiem, DEFAULT_PADDING * 2));

        p_settings->general.toggle_flash = lv_switch_create(p_settings->general.main, NULL);
        lv_obj_set_event_cb(p_settings->general.toggle_flash, cb_toggle_switch);
        lv_obj_align(p_settings->general.toggle_flash, row_flash_colon, LV_ALIGN_IN_RIGHT_MID, 0, 0);

        lv_obj_t * row_screensaver = lv_label_create(p_settings->general.main, NULL);
        lv_label_set_long_mode(row_screensaver, LV_LABEL_LONG_BREAK);
        lv_obj_set_width(row_screensaver, lv_obj_get_width_fit(p_settings->general.main));
        lv_label_set_text(row_screensaver, "Time as Screensaver");
        lv_obj_set_pos(row_screensaver, 0, get_next_row_pos(row_flash_colon, DEFAULT_PADDING * 2));

        p_settings->general.toggle_screensaver = lv_switch_create(p_settings->general.main, NULL);
        lv_obj_set_event_cb(p_settings->general.toggle_screensaver, cb_toggle_switch);
        lv_obj_align(p_settings->general.toggle_screensaver, row_screensaver, LV_ALIGN_IN_RIGHT_MID, 0, 0);

        update_toggle_switches();
    }
}

void cb_list_btn_calendars(lv_obj_t * obj, lv_event_t event) {
    if (lv_debug_check_obj_type(obj, "lv_btn") && event == LV_EVENT_RELEASED) {
        if (p_settings->general.main && lv_debug_check_obj_valid(p_settings->general.main)) {
            lv_obj_del(p_settings->general.main);
            p_settings->general.main = NULL;
        }

        p_settings->calendars.main = lv_page_create(p_settings->main, NULL);
        lv_obj_set_size(p_settings->calendars.main, lv_obj_get_width_fit(p_settings->main) - DEFAULT_LIST_WIDTH, lv_obj_get_height_fit(p_settings->main) - p_settings->header_offset);
        lv_obj_set_pos(p_settings->calendars.main, DEFAULT_LIST_WIDTH, 0);
        lv_obj_add_style(p_settings->calendars.main, LV_STATE_DEFAULT, &style_default_border_none);
        lv_obj_add_style(p_settings->calendars.main, LV_STATE_DEFAULT, &style_default_background_transparent_full);
    }
}

void cb_settings_btnmatrix(lv_obj_t * obj, lv_event_t event) {
    if (lv_debug_check_obj_type(obj, "lv_btnmatrix") && event == LV_EVENT_RELEASED) {
        const char * text = lv_btnmatrix_get_active_btn_text(obj);

        if (strcasecmp(text, "Save") == 0) {
            if ((*shandler)(&config) != 0) {
                // TODO Tell user that config could not be saved.
                return;
            }

            *p_config = config;
        }

        cb_settings_win_close(p_settings->btn_close, LV_EVENT_RELEASED);
    }
}

void cb_toggle_switch(lv_obj_t * obj, lv_event_t event) {
    if (lv_debug_check_obj_type(obj, "lv_switch") && event == LV_EVENT_VALUE_CHANGED) {
        bool state = lv_switch_get_state(obj);

        if (obj == p_settings->general.toggle_flash) {
            config.time.flash = state ? 1 : 0;
        }

        if (obj == p_settings->general.toggle_format) {
            config.time.format24 = state ? 1 : 0;
        }

        if (obj == p_settings->general.toggle_meridiem) {
            config.time.meridiem = state ? 1 : 0;
        }

        if (obj == p_settings->general.toggle_screensaver) {
            config.time.screensaver = state ? 1 : 0;
        }

        update_toggle_switches();
    }
}

void cb_settings_win_close(lv_obj_t * obj, lv_event_t event) {
    if (lv_debug_check_obj_type(obj, "lv_btn") && event == LV_EVENT_RELEASED) {
        if (compareTo(config, *p_config) != 0) {
            static const char * btns[] = {"Continue", "Go Back", ""};

            msgbox = lv_msgbox_create(p_settings->main, NULL);
            lv_obj_add_style(msgbox, LV_OBJ_PART_MAIN, &style_default_background_color_black);
            lv_obj_add_style(msgbox, LV_OBJ_PART_MAIN, &style_default_border_color_white);
            lv_obj_add_style(msgbox, LV_OBJ_PART_MAIN, &style_default_shadow_none);
            lv_obj_align(msgbox, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);

            lv_msgbox_add_btns(msgbox, btns);
            lv_msgbox_set_text(msgbox, "Unsaved changes will be lost.\n\nDo you wish to continue?");
            lv_msgbox_set_anim_time(msgbox, 0);

            lv_obj_set_event_cb(msgbox, cb_settings_win_msgbox);
            return;
        }

        if (p_settings->general.main && lv_debug_check_obj_valid(p_settings->general.main)) {
            lv_obj_del(p_settings->general.main);
        }

        if (p_settings->calendars.main && lv_debug_check_obj_valid(p_settings->calendars.main)) {
            lv_obj_del(p_settings->calendars.main);
        }

        if (p_settings->overlay && lv_debug_check_obj_valid(p_settings->overlay)) {
            lv_obj_del(p_settings->overlay);
        }

        p_settings->general.main = NULL;
        p_settings->calendars.main = NULL;
        p_settings->overlay = NULL;
    }

    lv_win_close_event_cb(obj, event);
}

void cb_settings_win_msgbox(lv_obj_t * obj, lv_event_t event) {
    if (lv_debug_check_obj_type(obj, "lv_msgbox") && event == LV_EVENT_VALUE_CHANGED) {
        const char * text = lv_msgbox_get_active_btn_text(obj);

        if (strcasecmp(text, "Continue") == 0) {
            // Reset the local config and close the settings
            config = *p_config;
            cb_settings_win_close(p_settings->btn_close, LV_EVENT_RELEASED);
            return;
        }

        lv_msgbox_start_auto_close(msgbox, 0);
    }
}

lv_coord_t get_next_row_pos(lv_obj_t * obj, int padding) {
    return lv_obj_get_y(obj) + lv_obj_get_height(obj) + padding;
}

void update_toggle_switches(void) {
    if (config.time.flash == 1) {
        lv_switch_on(p_settings->general.toggle_flash, false);
    } else {
        lv_switch_off(p_settings->general.toggle_flash, false);
    }

    if (config.time.format24 == 1) {
        lv_switch_on(p_settings->general.toggle_format, false);
        lv_obj_set_click(p_settings->general.toggle_meridiem, false);
        lv_obj_add_style(p_settings->general.toggle_meridiem, LV_SWITCH_PART_BG, &style_default_background_transparent_30);
        lv_obj_add_style(p_settings->general.toggle_meridiem, LV_SWITCH_PART_INDIC, &style_default_background_transparent_30);
        lv_obj_add_style(p_settings->general.toggle_meridiem, LV_SWITCH_PART_KNOB, &style_default_background_transparent_30);
    } else {
        lv_switch_off(p_settings->general.toggle_format, false);
        lv_obj_set_click(p_settings->general.toggle_meridiem, true);
        lv_obj_remove_style(p_settings->general.toggle_meridiem, LV_SWITCH_PART_BG, &style_default_background_transparent_30);
        lv_obj_remove_style(p_settings->general.toggle_meridiem, LV_SWITCH_PART_INDIC, &style_default_background_transparent_30);
        lv_obj_remove_style(p_settings->general.toggle_meridiem, LV_SWITCH_PART_KNOB, &style_default_background_transparent_30);
    }

    if (config.time.meridiem == 1) {
        lv_switch_on(p_settings->general.toggle_meridiem, false);
    } else {
        lv_switch_off(p_settings->general.toggle_meridiem, false);
    }

    if (config.time.screensaver == 1) {
        lv_switch_on(p_settings->general.toggle_screensaver, false);
    } else {
        lv_switch_off(p_settings->general.toggle_screensaver, false);
    }
}

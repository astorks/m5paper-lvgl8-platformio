// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: lvdev_m5paper


#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

uint32_t LV_EVENT_GET_COMP_CHILD;

typedef struct {
    uint32_t child_idx;
    lv_obj_t * child;
} ui_comp_get_child_t;

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx)
{
    ui_comp_get_child_t info;
    info.child = NULL;
    info.child_idx = child_idx;
    lv_event_send(comp, LV_EVENT_GET_COMP_CHILD, &info);
    return info.child;
}

void get_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    ui_comp_get_child_t * info = lv_event_get_param(e);
    info->child = c[info->child_idx];
}

void del_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    lv_mem_free(c);
}


// COMPONENT BatterySocPanel

lv_obj_t * ui_BatterySocPanel_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_BatterySocPanel;
    cui_BatterySocPanel = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_BatterySocPanel, 160);
    lv_obj_set_height(cui_BatterySocPanel, 50);
    lv_obj_set_x(cui_BatterySocPanel, 0);
    lv_obj_set_y(cui_BatterySocPanel, -50);
    lv_obj_set_align(cui_BatterySocPanel, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(cui_BatterySocPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_BatterySocPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_BatterySocPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_BatterySocPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_BatterySocPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_txtA1;
    cui_txtA1 = lv_label_create(cui_BatterySocPanel);
    lv_obj_set_width(cui_txtA1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_txtA1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_txtA1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_txtA1, "A1");

    lv_obj_t * cui_barA1Soc;
    cui_barA1Soc = lv_bar_create(cui_BatterySocPanel);
    lv_bar_set_value(cui_barA1Soc, 25, LV_ANIM_OFF);
    lv_obj_set_width(cui_barA1Soc, 100);
    lv_obj_set_height(cui_barA1Soc, 20);
    lv_obj_set_align(cui_barA1Soc, LV_ALIGN_RIGHT_MID);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BATTERYSOCPANEL_NUM);
    children[UI_COMP_BATTERYSOCPANEL_BATTERYSOCPANEL] = cui_BatterySocPanel;
    children[UI_COMP_BATTERYSOCPANEL_TXTA1] = cui_txtA1;
    children[UI_COMP_BATTERYSOCPANEL_BARA1SOC] = cui_barA1Soc;
    lv_obj_add_event_cb(cui_BatterySocPanel, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_BatterySocPanel, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_BatterySocPanel;
}



void ui_event_comp_panelNav_btnHome(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_panelNav = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_show_screen_home(e);
    }
}
void ui_event_comp_panelNav_btnSolar(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_panelNav = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_show_screen_solar(e);
    }
}
void ui_event_comp_panelNav_btnBattery(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_panelNav = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_show_screen_battery(e);
    }
}
void ui_event_comp_panelNav_btnATS(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_panelNav = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_show_screen_ats(e);
    }
}
void ui_event_comp_panelNav_btnSettings(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_panelNav = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_show_screen_settings(e);
    }
}

// COMPONENT panelNav

lv_obj_t * ui_panelNav_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_panelNav;
    cui_panelNav = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_panelNav, 60);
    lv_obj_set_width(cui_panelNav, lv_pct(100));
    lv_obj_set_align(cui_panelNav, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(cui_panelNav, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_panelNav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_panelNav, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_panelNav, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_panelNav, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_btnHome;
    cui_btnHome = lv_btn_create(cui_panelNav);
    lv_obj_set_width(cui_btnHome, 50);
    lv_obj_set_height(cui_btnHome, 50);
    lv_obj_set_x(cui_btnHome, -110);
    lv_obj_set_y(cui_btnHome, 0);
    lv_obj_set_align(cui_btnHome, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_btnHome, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_btnHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_btnHome, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_btnHome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_btnHome, lv_color_hex(0x0073BB), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_btnHome, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t * cui_Image1;
    cui_Image1 = lv_img_create(cui_btnHome);
    lv_obj_set_width(cui_Image1, 48);
    lv_obj_set_height(cui_Image1, 48);
    lv_obj_set_align(cui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_btnSolar;
    cui_btnSolar = lv_btn_create(cui_panelNav);
    lv_obj_set_width(cui_btnSolar, 50);
    lv_obj_set_height(cui_btnSolar, 50);
    lv_obj_set_x(cui_btnSolar, -55);
    lv_obj_set_y(cui_btnSolar, 0);
    lv_obj_set_align(cui_btnSolar, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_btnSolar, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_btnSolar, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_btnSolar, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_btnSolar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_btnSolar, lv_color_hex(0x0073BB), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_btnSolar, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t * cui_Image2;
    cui_Image2 = lv_img_create(cui_btnSolar);
    lv_obj_set_width(cui_Image2, 48);
    lv_obj_set_height(cui_Image2, 48);
    lv_obj_set_align(cui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_state(cui_Image2, LV_STATE_CHECKED);       /// States
    lv_obj_add_flag(cui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_btnBattery;
    cui_btnBattery = lv_btn_create(cui_panelNav);
    lv_obj_set_width(cui_btnBattery, 50);
    lv_obj_set_height(cui_btnBattery, 50);
    lv_obj_set_align(cui_btnBattery, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_btnBattery, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_btnBattery, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_btnBattery, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_btnBattery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_btnBattery, lv_color_hex(0x0073BB), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_btnBattery, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t * cui_Image3;
    cui_Image3 = lv_img_create(cui_btnBattery);
    lv_obj_set_width(cui_Image3, 48);
    lv_obj_set_height(cui_Image3, 48);
    lv_obj_set_align(cui_Image3, LV_ALIGN_CENTER);
    lv_obj_add_state(cui_Image3, LV_STATE_CHECKED);       /// States
    lv_obj_add_flag(cui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_btnATS;
    cui_btnATS = lv_btn_create(cui_panelNav);
    lv_obj_set_width(cui_btnATS, 50);
    lv_obj_set_height(cui_btnATS, 50);
    lv_obj_set_x(cui_btnATS, 55);
    lv_obj_set_y(cui_btnATS, 0);
    lv_obj_set_align(cui_btnATS, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_btnATS, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_btnATS, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_btnATS, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_btnATS, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_btnATS, lv_color_hex(0x0073BB), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_btnATS, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t * cui_Image4;
    cui_Image4 = lv_img_create(cui_btnATS);
    lv_obj_set_width(cui_Image4, 48);
    lv_obj_set_height(cui_Image4, 48);
    lv_obj_set_align(cui_Image4, LV_ALIGN_CENTER);
    lv_obj_add_state(cui_Image4, LV_STATE_CHECKED);       /// States
    lv_obj_add_flag(cui_Image4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Image4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_btnSettings;
    cui_btnSettings = lv_btn_create(cui_panelNav);
    lv_obj_set_width(cui_btnSettings, 50);
    lv_obj_set_height(cui_btnSettings, 50);
    lv_obj_set_x(cui_btnSettings, 110);
    lv_obj_set_y(cui_btnSettings, 0);
    lv_obj_set_align(cui_btnSettings, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_btnSettings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_btnSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_btnSettings, lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_btnSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_btnSettings, lv_color_hex(0x0073BB), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_btnSettings, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t * cui_Image5;
    cui_Image5 = lv_img_create(cui_btnSettings);
    lv_obj_set_width(cui_Image5, 48);
    lv_obj_set_height(cui_Image5, 48);
    lv_obj_set_align(cui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_state(cui_Image5, LV_STATE_CHECKED);       /// States
    lv_obj_add_flag(cui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_PANELNAV_NUM);
    children[UI_COMP_PANELNAV_PANELNAV] = cui_panelNav;
    children[UI_COMP_PANELNAV_BTNHOME] = cui_btnHome;
    children[UI_COMP_PANELNAV_IMAGE1] = cui_Image1;
    children[UI_COMP_PANELNAV_BTNSOLAR] = cui_btnSolar;
    children[UI_COMP_PANELNAV_IMAGE2] = cui_Image2;
    children[UI_COMP_PANELNAV_BTNBATTERY] = cui_btnBattery;
    children[UI_COMP_PANELNAV_IMAGE3] = cui_Image3;
    children[UI_COMP_PANELNAV_BTNATS] = cui_btnATS;
    children[UI_COMP_PANELNAV_IMAGE4] = cui_Image4;
    children[UI_COMP_PANELNAV_BTNSETTINGS] = cui_btnSettings;
    children[UI_COMP_PANELNAV_IMAGE5] = cui_Image5;
    lv_obj_add_event_cb(cui_panelNav, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_panelNav, del_component_child_event_cb, LV_EVENT_DELETE, children);
    lv_obj_add_event_cb(cui_btnHome, ui_event_comp_panelNav_btnHome, LV_EVENT_ALL, children);
    lv_obj_add_event_cb(cui_btnSolar, ui_event_comp_panelNav_btnSolar, LV_EVENT_ALL, children);
    lv_obj_add_event_cb(cui_btnBattery, ui_event_comp_panelNav_btnBattery, LV_EVENT_ALL, children);
    lv_obj_add_event_cb(cui_btnATS, ui_event_comp_panelNav_btnATS, LV_EVENT_ALL, children);
    lv_obj_add_event_cb(cui_btnSettings, ui_event_comp_panelNav_btnSettings, LV_EVENT_ALL, children);
    return cui_panelNav;
}



// COMPONENT panelTitle

lv_obj_t * ui_panelTitle_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_panelTitle;
    cui_panelTitle = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_panelTitle, 25);
    lv_obj_set_width(cui_panelTitle, lv_pct(100));
    lv_obj_set_align(cui_panelTitle, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_panelTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_panelTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_panelTitle, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_panelTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_panelTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_txtTitleClock;
    cui_txtTitleClock = lv_label_create(cui_panelTitle);
    lv_obj_set_width(cui_txtTitleClock, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_txtTitleClock, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_txtTitleClock, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_txtTitleClock, "12:00PM");

    lv_obj_t * cui_txtTitleSoc;
    cui_txtTitleSoc = lv_label_create(cui_panelTitle);
    lv_obj_set_width(cui_txtTitleSoc, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_txtTitleSoc, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_txtTitleSoc, -30);
    lv_obj_set_y(cui_txtTitleSoc, 1);
    lv_obj_set_align(cui_txtTitleSoc, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(cui_txtTitleSoc, "0.00v");

    lv_obj_t * cui_iconTitleWifi;
    cui_iconTitleWifi = lv_img_create(cui_panelTitle);
    lv_obj_set_width(cui_iconTitleWifi, 20);
    lv_obj_set_height(cui_iconTitleWifi, 20);
    lv_obj_set_align(cui_iconTitleWifi, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(cui_iconTitleWifi, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_iconTitleWifi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_PANELTITLE_NUM);
    children[UI_COMP_PANELTITLE_PANELTITLE] = cui_panelTitle;
    children[UI_COMP_PANELTITLE_TXTTITLECLOCK] = cui_txtTitleClock;
    children[UI_COMP_PANELTITLE_TXTTITLESOC] = cui_txtTitleSoc;
    children[UI_COMP_PANELTITLE_ICONTITLEWIFI] = cui_iconTitleWifi;
    lv_obj_add_event_cb(cui_panelTitle, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_panelTitle, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_panelTitle;
}


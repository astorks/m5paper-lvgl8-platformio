// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: lvdev_m5paper

#ifndef _LVDEV_M5PAPER_UI_COMP_H
#define _LVDEV_M5PAPER_UI_COMP_H

#include "ui.h"

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx);
extern uint32_t LV_EVENT_GET_COMP_CHILD;

// COMPONENT BatterySocPanel
#define UI_COMP_BATTERYSOCPANEL_BATTERYSOCPANEL 0
#define UI_COMP_BATTERYSOCPANEL_TXTA1 1
#define UI_COMP_BATTERYSOCPANEL_BARA1SOC 2
#define _UI_COMP_BATTERYSOCPANEL_NUM 3
lv_obj_t * ui_BatterySocPanel_create(lv_obj_t * comp_parent);

// COMPONENT panelNav
#define UI_COMP_PANELNAV_PANELNAV 0
#define UI_COMP_PANELNAV_BTNHOME 1
#define UI_COMP_PANELNAV_IMAGE1 2
#define UI_COMP_PANELNAV_BTNSOLAR 3
#define UI_COMP_PANELNAV_IMAGE2 4
#define UI_COMP_PANELNAV_BTNBATTERY 5
#define UI_COMP_PANELNAV_IMAGE3 6
#define UI_COMP_PANELNAV_BTNATS 7
#define UI_COMP_PANELNAV_IMAGE4 8
#define UI_COMP_PANELNAV_BTNSETTINGS 9
#define UI_COMP_PANELNAV_IMAGE5 10
#define _UI_COMP_PANELNAV_NUM 11
lv_obj_t * ui_panelNav_create(lv_obj_t * comp_parent);
void ui_event_comp_panelNav_btnHome(lv_event_t * e);
void ui_event_comp_panelNav_btnSolar(lv_event_t * e);
void ui_event_comp_panelNav_btnBattery(lv_event_t * e);
void ui_event_comp_panelNav_btnATS(lv_event_t * e);
void ui_event_comp_panelNav_btnSettings(lv_event_t * e);

// COMPONENT panelTitle
#define UI_COMP_PANELTITLE_PANELTITLE 0
#define UI_COMP_PANELTITLE_TXTTITLECLOCK 1
#define UI_COMP_PANELTITLE_TXTTITLESOC 2
#define UI_COMP_PANELTITLE_ICONTITLEWIFI 3
#define _UI_COMP_PANELTITLE_NUM 4
lv_obj_t * ui_panelTitle_create(lv_obj_t * comp_parent);

#endif

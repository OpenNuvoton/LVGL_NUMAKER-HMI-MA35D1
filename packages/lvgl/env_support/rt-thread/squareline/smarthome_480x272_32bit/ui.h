// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
// LVGL VERSION: 8.3.4
// PROJECT: Smarthome

#ifndef _SMARTHOME_UI_H
#define _SMARTHOME_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

void Sec_Animation(lv_obj_t * TargetObject, int delay);
void Rain_Animation(lv_obj_t * TargetObject, int delay);
void Rain2_Animation(lv_obj_t * TargetObject, int delay);
void SettingsOn_Animation(lv_obj_t * TargetObject, int delay);
void SettingsOpaOn_Animation(lv_obj_t * TargetObject, int delay);
void SettingsOff_Animation(lv_obj_t * TargetObject, int delay);
void SettingsOpaOff_Animation(lv_obj_t * TargetObject, int delay);
void Min_Animation(lv_obj_t * TargetObject, int delay);
void Hour_Animation(lv_obj_t * TargetObject, int delay);
void Notifi_Animation(lv_obj_t * TargetObject, int delay);
void Up_Animation(lv_obj_t * TargetObject, int delay);
void Close_Animation(lv_obj_t * TargetObject, int delay);
void Open_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Home(lv_event_t * e);
extern lv_obj_t * ui_Home;
extern lv_obj_t * ui_Home_Group;
extern lv_obj_t * ui_Header_Group;
void ui_event_Menu_Icon(lv_event_t * e);
extern lv_obj_t * ui_Menu_Icon;
extern lv_obj_t * ui_Date;
extern lv_obj_t * ui_Avatar;
extern lv_obj_t * ui_Home_Label2;
extern lv_obj_t * ui_Content_Group;
extern lv_obj_t * ui_Time_Group;
extern lv_obj_t * ui_Weather_Group;
extern lv_obj_t * ui_Temperature_Group;
extern lv_obj_t * ui_Camera_Group;
extern lv_obj_t * ui_Solarpanels_Group;
extern lv_obj_t * ui_Music_Group;
extern lv_obj_t * ui_Footer;
extern lv_obj_t * ui_Noti_Indicator;
extern lv_obj_t * ui_Notifi_Text_Group;
extern lv_obj_t * ui_Home_Label1;
extern lv_obj_t * ui_Home_Label3;
extern lv_obj_t * ui_Footer_Indicators_Group;
void ui_event_BLE(lv_event_t * e);
extern lv_obj_t * ui_BLE;
void ui_event_Wifi(lv_event_t * e);
extern lv_obj_t * ui_Wifi;
extern lv_obj_t * ui_Battery_Group;
extern lv_obj_t * ui_Battery;
extern lv_obj_t * ui_Home_Label4;
extern lv_obj_t * ui_Settings_Group;
void ui_event_Settings_Group_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group_List_Time_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Weather_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Temperature_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Camera_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Solar_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Music_Switch(lv_event_t * e);
extern lv_obj_t * ui_Notifi_BLE;
extern lv_obj_t * ui_Notifi_Wifi;


LV_IMG_DECLARE(ui_img_bg_png);    // assets\bg.png
LV_IMG_DECLARE(ui_img_hamburger_png);    // assets\hamburger.png
LV_IMG_DECLARE(ui_img_avatar_png);    // assets\avatar.png
LV_IMG_DECLARE(ui_img_clock_bg_png);    // assets\clock_bg.png
LV_IMG_DECLARE(ui_img_clock_hour_shadow_png);    // assets\clock_hour_shadow.png
LV_IMG_DECLARE(ui_img_clock_hour_png);    // assets\clock_hour.png
LV_IMG_DECLARE(ui_img_clock_min_shadow_png);    // assets\clock_min_shadow.png
LV_IMG_DECLARE(ui_img_clock_min_png);    // assets\clock_min.png
LV_IMG_DECLARE(ui_img_clock_sec_shadow_png);    // assets\clock_sec_shadow.png
LV_IMG_DECLARE(ui_img_clock_sec_png);    // assets\clock_sec.png
LV_IMG_DECLARE(ui_img_rain_png);    // assets\rain.png
LV_IMG_DECLARE(ui_img_weather_icon_png);    // assets\weather_icon.png
LV_IMG_DECLARE(ui_img_thermostat_bg_png);    // assets\thermostat_bg.png
LV_IMG_DECLARE(ui_img_gradient_png);    // assets\gradient.png
LV_IMG_DECLARE(ui_img_camera_png);    // assets\camera.png
LV_IMG_DECLARE(ui_img_camera_off_png);    // assets\camera_off.png
LV_IMG_DECLARE(ui_img_music_bg_png);    // assets\music_bg.png
LV_IMG_DECLARE(ui_img_prev_png);    // assets\prev.png
LV_IMG_DECLARE(ui_img_next_png);    // assets\next.png
LV_IMG_DECLARE(ui_img_play_png);    // assets\play.png
LV_IMG_DECLARE(ui_img_pause_png);    // assets\pause.png
LV_IMG_DECLARE(ui_img_bluetooth_png);    // assets\bluetooth.png
LV_IMG_DECLARE(ui_img_wifi_png);    // assets\wifi.png
LV_IMG_DECLARE(ui_img_battery_png);    // assets\battery.png
LV_IMG_DECLARE(ui_img_ble_big_png);    // assets\ble_big.png
LV_IMG_DECLARE(ui_img_wifi_big_png);    // assets\wifi_big.png


LV_FONT_DECLARE(ui_font_BigNumber);
LV_FONT_DECLARE(ui_font_H1);
LV_FONT_DECLARE(ui_font_H2);
LV_FONT_DECLARE(ui_font_Subtitle);
LV_FONT_DECLARE(ui_font_Title);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

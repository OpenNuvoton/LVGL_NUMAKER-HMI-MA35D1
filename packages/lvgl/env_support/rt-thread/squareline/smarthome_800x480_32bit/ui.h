// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
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
void Home_On_Animation(lv_obj_t * TargetObject, int delay);
void Home_Off_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Start_Screen(lv_event_t * e);
extern lv_obj_t * ui_Start_Screen;
void ui_event_Home_Screen(lv_event_t * e);
extern lv_obj_t * ui_Home_Screen;
extern lv_obj_t * ui_Home_Group;
extern lv_obj_t * ui_Header_Group;
void ui_event_Menu_Icon_Group(lv_event_t * e);
extern lv_obj_t * ui_Menu_Icon_Group;
extern lv_obj_t * ui_Menu_Icon;
extern lv_obj_t * ui_Date;
extern lv_obj_t * ui_Avatar;
extern lv_obj_t * ui_Home_Label2;
extern lv_obj_t * ui_Content_Group;
void ui_event_Time_Group_Time_Group(lv_event_t * e);
extern lv_obj_t * ui_Time_Group;
void ui_event_Temperature_Group_Temperature_Group(lv_event_t * e);
extern lv_obj_t * ui_Temperature_Group;
void ui_event_Weather_Group_Weather_Group(lv_event_t * e);
extern lv_obj_t * ui_Weather_Group;
extern lv_obj_t * ui_Footer;
extern lv_obj_t * ui_Settings_Group;
void ui_event_Settings_Group_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group_List_Bluetooth_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Wifi_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Lights_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Windows_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Doors_Switch(lv_event_t * e);
extern lv_obj_t * ui_Notifi_Group;
extern lv_obj_t * ui_Notifi_Windows;
extern lv_obj_t * ui_Notifi_Doors;
extern lv_obj_t * ui_Notifi_Wifi;
extern lv_obj_t * ui_Notifi_BLE;
extern lv_obj_t * ui_Notifi_Lights;
extern lv_obj_t * ui_Notifi_Windows_Off;
extern lv_obj_t * ui_Notifi_Doors_Off;
extern lv_obj_t * ui_Notifi_Wifi_Off;
extern lv_obj_t * ui_Notifi_BLE_Off;
extern lv_obj_t * ui_Notifi_Lights_Off;
void ui_event_Time_Screen(lv_event_t * e);
extern lv_obj_t * ui_Time_Screen;
extern lv_obj_t * ui_Home_Group1;
extern lv_obj_t * ui_Header_Group1;
void ui_event_Menu_Icon_Group1(lv_event_t * e);
extern lv_obj_t * ui_Menu_Icon_Group1;
extern lv_obj_t * ui_Menu_Icon1;
extern lv_obj_t * ui_Date1;
extern lv_obj_t * ui_Avatar1;
extern lv_obj_t * ui_Home_Label5;
extern lv_obj_t * ui_Content_Group1;
extern lv_obj_t * ui_Time_Group1;
extern lv_obj_t * ui_World_Time_Group;
extern lv_obj_t * ui_World_Time_List1;
extern lv_obj_t * ui_World_Time_List2;
extern lv_obj_t * ui_World_Time_List3;
extern lv_obj_t * ui_World_Time_List4;
extern lv_obj_t * ui_Footer2;
void ui_event_Footer2_Home_Button(lv_event_t * e);
extern lv_obj_t * ui_Settings_Group1;
void ui_event_Settings_Group1_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group1_List_Bluetooth_Switch(lv_event_t * e);
void ui_event_Settings_Group1_List_Wifi_Switch(lv_event_t * e);
void ui_event_Settings_Group1_List_Lights_Switch(lv_event_t * e);
void ui_event_Settings_Group1_List_Windows_Switch(lv_event_t * e);
void ui_event_Settings_Group1_List_Doors_Switch(lv_event_t * e);
extern lv_obj_t * ui_Notifi_Group1;
extern lv_obj_t * ui_Notifi_Windows1;
extern lv_obj_t * ui_Notifi_Doors1;
extern lv_obj_t * ui_Notifi_Wifi1;
extern lv_obj_t * ui_Notifi_BLE1;
extern lv_obj_t * ui_Notifi_Lights1;
extern lv_obj_t * ui_Notifi_Windows_Off1;
extern lv_obj_t * ui_Notifi_Doors_Off1;
extern lv_obj_t * ui_Notifi_Wifi_Off1;
extern lv_obj_t * ui_Notifi_BLE_Off1;
extern lv_obj_t * ui_Notifi_Lights_Off1;
void ui_event_Weather_Screen(lv_event_t * e);
extern lv_obj_t * ui_Weather_Screen;
extern lv_obj_t * ui_Home_Group2;
extern lv_obj_t * ui_Header_Group2;
void ui_event_Menu_Icon_Group2(lv_event_t * e);
extern lv_obj_t * ui_Menu_Icon_Group2;
extern lv_obj_t * ui_Menu_Icon2;
extern lv_obj_t * ui_Date2;
extern lv_obj_t * ui_Avatar2;
extern lv_obj_t * ui_Home_Label6;
extern lv_obj_t * ui_Content_Group2;
extern lv_obj_t * ui_Weather_Group1;
extern lv_obj_t * ui_Weather_Content_Group;
extern lv_obj_t * ui_WeatheGroupList;
extern lv_obj_t * ui_WeatheGroupList1;
extern lv_obj_t * ui_WeatheGroupList2;
extern lv_obj_t * ui_Footer1;
void ui_event_Footer1_Home_Button(lv_event_t * e);
extern lv_obj_t * ui_Settings_Group2;
void ui_event_Settings_Group2_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group2_List_Bluetooth_Switch(lv_event_t * e);
void ui_event_Settings_Group2_List_Wifi_Switch(lv_event_t * e);
void ui_event_Settings_Group2_List_Lights_Switch(lv_event_t * e);
void ui_event_Settings_Group2_List_Windows_Switch(lv_event_t * e);
void ui_event_Settings_Group2_List_Doors_Switch(lv_event_t * e);
extern lv_obj_t * ui_Notifi_Group2;
extern lv_obj_t * ui_Notifi_Windows2;
extern lv_obj_t * ui_Notifi_Doors2;
extern lv_obj_t * ui_Notifi_Wifi2;
extern lv_obj_t * ui_Notifi_BLE2;
extern lv_obj_t * ui_Notifi_Lights2;
extern lv_obj_t * ui_Notifi_Windows_Off2;
extern lv_obj_t * ui_Notifi_Doors_Off2;
extern lv_obj_t * ui_Notifi_Wifi_Off2;
extern lv_obj_t * ui_Notifi_BLE_Off2;
extern lv_obj_t * ui_Notifi_Lights_Off2;
void ui_event_Thermostat_Screen(lv_event_t * e);
extern lv_obj_t * ui_Thermostat_Screen;
extern lv_obj_t * ui_Home_Group3;
extern lv_obj_t * ui_Header_Group3;
void ui_event_Menu_Icon_Group3(lv_event_t * e);
extern lv_obj_t * ui_Menu_Icon_Group3;
extern lv_obj_t * ui_Menu_Icon3;
extern lv_obj_t * ui_Date3;
extern lv_obj_t * ui_Avatar3;
extern lv_obj_t * ui_Home_Label7;
extern lv_obj_t * ui_Content_Group3;
extern lv_obj_t * ui_Weather_Content_Group1;
extern lv_obj_t * ui_Chart2;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Temperature_Group2;
extern lv_obj_t * ui_Footer3;
void ui_event_Footer3_Home_Button(lv_event_t * e);
extern lv_obj_t * ui_Settings_Group3;
void ui_event_Settings_Group3_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group3_List_Bluetooth_Switch(lv_event_t * e);
void ui_event_Settings_Group3_List_Wifi_Switch(lv_event_t * e);
void ui_event_Settings_Group3_List_Lights_Switch(lv_event_t * e);
void ui_event_Settings_Group3_List_Windows_Switch(lv_event_t * e);
void ui_event_Settings_Group3_List_Doors_Switch(lv_event_t * e);
extern lv_obj_t * ui_Notifi_Group3;
extern lv_obj_t * ui_Notifi_Windows3;
extern lv_obj_t * ui_Notifi_Doors3;
extern lv_obj_t * ui_Notifi_Wifi3;
extern lv_obj_t * ui_Notifi_BLE3;
extern lv_obj_t * ui_Notifi_Lights3;
extern lv_obj_t * ui_Notifi_Windows_Off3;
extern lv_obj_t * ui_Notifi_Doors_Off3;
extern lv_obj_t * ui_Notifi_Wifi_Off3;
extern lv_obj_t * ui_Notifi_BLE_Off3;
extern lv_obj_t * ui_Notifi_Lights_Off3;


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
LV_IMG_DECLARE(ui_img_thermostat_bg_png);    // assets\thermostat_bg.png
LV_IMG_DECLARE(ui_img_gradient_png);    // assets\gradient.png
LV_IMG_DECLARE(ui_img_rain_png);    // assets\rain.png
LV_IMG_DECLARE(ui_img_weather_icon_png);    // assets\weather_icon.png
LV_IMG_DECLARE(ui_img_home_png);    // assets\home.png
LV_IMG_DECLARE(ui_img_bluetooth_png);    // assets\bluetooth.png
LV_IMG_DECLARE(ui_img_wifi_png);    // assets\wifi.png
LV_IMG_DECLARE(ui_img_battery_png);    // assets\battery.png
LV_IMG_DECLARE(ui_img_ble_big_png);    // assets\ble_big.png
LV_IMG_DECLARE(ui_img_ble_windows_png);    // assets\ble_windows.png
LV_IMG_DECLARE(ui_img_ble_doors_png);    // assets\ble_doors.png
LV_IMG_DECLARE(ui_img_wifi_big_png);    // assets\wifi_big.png
LV_IMG_DECLARE(ui_img_ble_lights_png);    // assets\ble_lights.png
LV_IMG_DECLARE(ui_img_weather_png);    // assets\weather.png
LV_IMG_DECLARE(ui_img_weather_cloud_fog_png);    // assets\weather_cloud_fog.png
LV_IMG_DECLARE(ui_img_weather_cloud_png);    // assets\weather_cloud.png
LV_IMG_DECLARE(ui_img_weather_sun_png);    // assets\weather_sun.png
LV_IMG_DECLARE(ui_img_weather_sun_cloud_png);    // assets\weather_sun_cloud.png


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

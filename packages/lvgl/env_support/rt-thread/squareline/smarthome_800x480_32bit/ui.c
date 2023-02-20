// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.3.4
// PROJECT: Smarthome

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

///////////////////// VARIABLES ////////////////////
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
lv_obj_t * ui_Start_Screen;
void ui_event_Home_Screen(lv_event_t * e);
lv_obj_t * ui_Home_Screen;
lv_obj_t * ui_Home_Group;
lv_obj_t * ui_Header_Group;
void ui_event_Menu_Icon_Group(lv_event_t * e);
lv_obj_t * ui_Menu_Icon_Group;
lv_obj_t * ui_Menu_Icon;
lv_obj_t * ui_Date;
lv_obj_t * ui_Avatar;
lv_obj_t * ui_Home_Label2;
lv_obj_t * ui_Content_Group;
void ui_event_Time_Group_Time_Group(lv_event_t * e);
lv_obj_t * ui_Time_Group;
void ui_event_Temperature_Group_Temperature_Group(lv_event_t * e);
lv_obj_t * ui_Temperature_Group;
void ui_event_Weather_Group_Weather_Group(lv_event_t * e);
lv_obj_t * ui_Weather_Group;
lv_obj_t * ui_Footer;
lv_obj_t * ui_Settings_Group;
void ui_event_Settings_Group_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group_List_Bluetooth_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Wifi_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Lights_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Windows_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Doors_Switch(lv_event_t * e);
lv_obj_t * ui_Notifi_Group;
lv_obj_t * ui_Notifi_Windows;
lv_obj_t * ui_Notifi_Doors;
lv_obj_t * ui_Notifi_Wifi;
lv_obj_t * ui_Notifi_BLE;
lv_obj_t * ui_Notifi_Lights;
lv_obj_t * ui_Notifi_Windows_Off;
lv_obj_t * ui_Notifi_Doors_Off;
lv_obj_t * ui_Notifi_Wifi_Off;
lv_obj_t * ui_Notifi_BLE_Off;
lv_obj_t * ui_Notifi_Lights_Off;
void ui_event_Time_Screen(lv_event_t * e);
lv_obj_t * ui_Time_Screen;
lv_obj_t * ui_Home_Group1;
lv_obj_t * ui_Header_Group1;
void ui_event_Menu_Icon_Group1(lv_event_t * e);
lv_obj_t * ui_Menu_Icon_Group1;
lv_obj_t * ui_Menu_Icon1;
lv_obj_t * ui_Date1;
lv_obj_t * ui_Avatar1;
lv_obj_t * ui_Home_Label5;
lv_obj_t * ui_Content_Group1;
lv_obj_t * ui_Time_Group1;
lv_obj_t * ui_World_Time_Group;
lv_obj_t * ui_World_Time_List1;
lv_obj_t * ui_World_Time_List2;
lv_obj_t * ui_World_Time_List3;
lv_obj_t * ui_World_Time_List4;
lv_obj_t * ui_Footer2;
void ui_event_Footer2_Home_Button(lv_event_t * e);
lv_obj_t * ui_Settings_Group1;
void ui_event_Settings_Group1_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group1_List_Bluetooth_Switch(lv_event_t * e);
void ui_event_Settings_Group1_List_Wifi_Switch(lv_event_t * e);
void ui_event_Settings_Group1_List_Lights_Switch(lv_event_t * e);
void ui_event_Settings_Group1_List_Windows_Switch(lv_event_t * e);
void ui_event_Settings_Group1_List_Doors_Switch(lv_event_t * e);
lv_obj_t * ui_Notifi_Group1;
lv_obj_t * ui_Notifi_Windows1;
lv_obj_t * ui_Notifi_Doors1;
lv_obj_t * ui_Notifi_Wifi1;
lv_obj_t * ui_Notifi_BLE1;
lv_obj_t * ui_Notifi_Lights1;
lv_obj_t * ui_Notifi_Windows_Off1;
lv_obj_t * ui_Notifi_Doors_Off1;
lv_obj_t * ui_Notifi_Wifi_Off1;
lv_obj_t * ui_Notifi_BLE_Off1;
lv_obj_t * ui_Notifi_Lights_Off1;
void ui_event_Weather_Screen(lv_event_t * e);
lv_obj_t * ui_Weather_Screen;
lv_obj_t * ui_Home_Group2;
lv_obj_t * ui_Header_Group2;
void ui_event_Menu_Icon_Group2(lv_event_t * e);
lv_obj_t * ui_Menu_Icon_Group2;
lv_obj_t * ui_Menu_Icon2;
lv_obj_t * ui_Date2;
lv_obj_t * ui_Avatar2;
lv_obj_t * ui_Home_Label6;
lv_obj_t * ui_Content_Group2;
lv_obj_t * ui_Weather_Group1;
lv_obj_t * ui_Weather_Content_Group;
lv_obj_t * ui_WeatheGroupList;
lv_obj_t * ui_WeatheGroupList1;
lv_obj_t * ui_WeatheGroupList2;
lv_obj_t * ui_Footer1;
void ui_event_Footer1_Home_Button(lv_event_t * e);
lv_obj_t * ui_Settings_Group2;
void ui_event_Settings_Group2_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group2_List_Bluetooth_Switch(lv_event_t * e);
void ui_event_Settings_Group2_List_Wifi_Switch(lv_event_t * e);
void ui_event_Settings_Group2_List_Lights_Switch(lv_event_t * e);
void ui_event_Settings_Group2_List_Windows_Switch(lv_event_t * e);
void ui_event_Settings_Group2_List_Doors_Switch(lv_event_t * e);
lv_obj_t * ui_Notifi_Group2;
lv_obj_t * ui_Notifi_Windows2;
lv_obj_t * ui_Notifi_Doors2;
lv_obj_t * ui_Notifi_Wifi2;
lv_obj_t * ui_Notifi_BLE2;
lv_obj_t * ui_Notifi_Lights2;
lv_obj_t * ui_Notifi_Windows_Off2;
lv_obj_t * ui_Notifi_Doors_Off2;
lv_obj_t * ui_Notifi_Wifi_Off2;
lv_obj_t * ui_Notifi_BLE_Off2;
lv_obj_t * ui_Notifi_Lights_Off2;
void ui_event_Thermostat_Screen(lv_event_t * e);
lv_obj_t * ui_Thermostat_Screen;
lv_obj_t * ui_Home_Group3;
lv_obj_t * ui_Header_Group3;
void ui_event_Menu_Icon_Group3(lv_event_t * e);
lv_obj_t * ui_Menu_Icon_Group3;
lv_obj_t * ui_Menu_Icon3;
lv_obj_t * ui_Date3;
lv_obj_t * ui_Avatar3;
lv_obj_t * ui_Home_Label7;
lv_obj_t * ui_Content_Group3;
lv_obj_t * ui_Weather_Content_Group1;
lv_obj_t * ui_Chart2;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Temperature_Group2;
lv_obj_t * ui_Footer3;
void ui_event_Footer3_Home_Button(lv_event_t * e);
lv_obj_t * ui_Settings_Group3;
void ui_event_Settings_Group3_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group3_List_Bluetooth_Switch(lv_event_t * e);
void ui_event_Settings_Group3_List_Wifi_Switch(lv_event_t * e);
void ui_event_Settings_Group3_List_Lights_Switch(lv_event_t * e);
void ui_event_Settings_Group3_List_Windows_Switch(lv_event_t * e);
void ui_event_Settings_Group3_List_Doors_Switch(lv_event_t * e);
lv_obj_t * ui_Notifi_Group3;
lv_obj_t * ui_Notifi_Windows3;
lv_obj_t * ui_Notifi_Doors3;
lv_obj_t * ui_Notifi_Wifi3;
lv_obj_t * ui_Notifi_BLE3;
lv_obj_t * ui_Notifi_Lights3;
lv_obj_t * ui_Notifi_Windows_Off3;
lv_obj_t * ui_Notifi_Doors_Off3;
lv_obj_t * ui_Notifi_Wifi_Off3;
lv_obj_t * ui_Notifi_BLE_Off3;
lv_obj_t * ui_Notifi_Lights_Off3;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void Sec_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 60000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_start(&PropertyAnimation_0);

}
void Rain_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, 42);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 1000);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_1, 0, -14);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_1);

}
void Rain2_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, 42);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 1500);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_1, 0, -14);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_1);

}
void SettingsOn_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, -300, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}
void SettingsOpaOn_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_0);

}
void SettingsOff_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, -400);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);

}
void SettingsOpaOff_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 255, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_0);

}
void Min_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 2000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 800);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void Hour_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 1600, 2250);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void Notifi_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_height);
    lv_anim_set_values(&PropertyAnimation_0, 0, 70);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 300);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_height);
    lv_anim_set_values(&PropertyAnimation_1, 70, 0);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 2000);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);

}
void Up_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 60, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 400);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, true);
    lv_anim_start(&PropertyAnimation_1);

}
void Close_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_width);
    lv_anim_set_values(&PropertyAnimation_0, 230, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void Open_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_width);
    lv_anim_set_values(&PropertyAnimation_0, 0, 230);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_width);
    lv_anim_start(&PropertyAnimation_0);

}
void Home_On_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_width);
    lv_anim_set_values(&PropertyAnimation_0, 0, 50);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}
void Home_Off_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 100);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_width);
    lv_anim_set_values(&PropertyAnimation_0, 50, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_Start_Screen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        Sec_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_SEC_SHADOW), 0);
        Sec_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_SEC), 0);
        Sec_Animation(ui_comp_get_child(ui_Time_Group1, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_SEC_SHADOW), 0);
        Sec_Animation(ui_comp_get_child(ui_Time_Group1, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_SEC), 0);
        Rain2_Animation(ui_comp_get_child(ui_Weather_Group, UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_RAIN), 0);
        Rain_Animation(ui_comp_get_child(ui_Weather_Group, UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_RAIN1), 0);
        Rain_Animation(ui_comp_get_child(ui_Weather_Group1, UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_RAIN1), 0);
        Rain2_Animation(ui_comp_get_child(ui_Weather_Group1, UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_RAIN), 0);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_screen_change(ui_Home_Screen, LV_SCR_LOAD_ANIM_NONE, 0, 0);
    }
}
void ui_event_Home_Screen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        Min_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_MIN), 0);
        Min_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_MIN_SHADOW), 0);
        Hour_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_HOUR), 0);
        Hour_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_HOUR_SHADOW), 0);
    }
}
void ui_event_Menu_Icon_Group(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOn_Animation(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        SettingsOpaOn_Animation(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_CHECKABLE,
                        _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Time_Group_Time_Group(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Time_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
void ui_event_Temperature_Group_Temperature_Group(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Thermostat_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
void ui_event_Weather_Group_Weather_Group(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Weather_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
void ui_event_Settings_Group_Settings_Dark(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOff_Animation(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Settings_Group_List_Bluetooth_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE_Off, 0);
    }
}
void ui_event_Settings_Group_List_Wifi_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi_Off, 0);
    }
}
void ui_event_Settings_Group_List_Lights_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Lights, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Lights_Off, 0);
    }
}
void ui_event_Settings_Group_List_Windows_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Windows, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Windows_Off, 0);
    }
}
void ui_event_Settings_Group_List_Doors_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Doors, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Doors_Off, 0);
    }
}
void ui_event_Time_Screen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        Home_On_Animation(ui_comp_get_child(ui_Footer2, UI_COMP_FOOTER_HOME_BUTTON), 0);
    }
    if(event_code == LV_EVENT_SCREEN_UNLOAD_START) {
        Home_Off_Animation(ui_comp_get_child(ui_Footer2, UI_COMP_FOOTER_HOME_BUTTON), 0);
    }
}
void ui_event_Menu_Icon_Group1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOn_Animation(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        SettingsOpaOn_Animation(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_CHECKABLE,
                        _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Footer2_Home_Button(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
void ui_event_Settings_Group1_Settings_Dark(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOff_Animation(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Settings_Group1_List_Bluetooth_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE1, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE_Off1, 0);
    }
}
void ui_event_Settings_Group1_List_Wifi_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi1, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi_Off1, 0);
    }
}
void ui_event_Settings_Group1_List_Lights_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Lights1, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Lights_Off1, 0);
    }
}
void ui_event_Settings_Group1_List_Windows_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Windows1, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Windows_Off1, 0);
    }
}
void ui_event_Settings_Group1_List_Doors_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Doors1, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Doors_Off1, 0);
    }
}
void ui_event_Weather_Screen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        Home_On_Animation(ui_comp_get_child(ui_Footer1, UI_COMP_FOOTER_HOME_BUTTON), 0);
    }
    if(event_code == LV_EVENT_SCREEN_UNLOAD_START) {
        Home_Off_Animation(ui_comp_get_child(ui_Footer1, UI_COMP_FOOTER_HOME_BUTTON), 0);
    }
}
void ui_event_Menu_Icon_Group2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOn_Animation(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        SettingsOpaOn_Animation(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_CHECKABLE,
                        _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Footer1_Home_Button(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
void ui_event_Settings_Group2_Settings_Dark(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOff_Animation(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Settings_Group2_List_Bluetooth_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE2, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE_Off2, 0);
    }
}
void ui_event_Settings_Group2_List_Wifi_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi2, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi_Off2, 0);
    }
}
void ui_event_Settings_Group2_List_Lights_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Lights2, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Lights_Off2, 0);
    }
}
void ui_event_Settings_Group2_List_Windows_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Windows2, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Windows_Off2, 0);
    }
}
void ui_event_Settings_Group2_List_Doors_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Doors2, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Doors_Off2, 0);
    }
}
void ui_event_Thermostat_Screen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOAD_START) {
        Home_On_Animation(ui_comp_get_child(ui_Footer3, UI_COMP_FOOTER_HOME_BUTTON), 0);
    }
    if(event_code == LV_EVENT_SCREEN_UNLOAD_START) {
        Home_Off_Animation(ui_comp_get_child(ui_Footer3, UI_COMP_FOOTER_HOME_BUTTON), 0);
    }
}
void ui_event_Menu_Icon_Group3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOn_Animation(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        SettingsOpaOn_Animation(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_CHECKABLE,
                        _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_Footer3_Home_Button(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Home_Screen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }
}
void ui_event_Settings_Group3_Settings_Dark(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOff_Animation(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_Settings_Group3_List_Bluetooth_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE3, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE_Off3, 0);
    }
}
void ui_event_Settings_Group3_List_Wifi_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi3, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi_Off3, 0);
    }
}
void ui_event_Settings_Group3_List_Lights_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Lights3, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Lights_Off3, 0);
    }
}
void ui_event_Settings_Group3_List_Windows_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Windows3, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Windows_Off3, 0);
    }
}
void ui_event_Settings_Group3_List_Doors_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Doors3, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Doors_Off3, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Start_Screen_screen_init(void)
{
    ui_Start_Screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Start_Screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Start_Screen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Start_Screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Start_Screen, ui_event_Start_Screen, LV_EVENT_ALL, NULL);

}
void ui_Home_Screen_screen_init(void)
{
    ui_Home_Screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Home_Screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Home_Screen, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Group = lv_obj_create(ui_Home_Screen);
    lv_obj_set_width(ui_Home_Group, lv_pct(100));
    lv_obj_set_height(ui_Home_Group, lv_pct(100));
    lv_obj_set_align(ui_Home_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Home_Group, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Home_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Home_Group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Home_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Home_Group, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Home_Group, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Home_Group, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Home_Group, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Home_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Home_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Group = lv_obj_create(ui_Home_Group);
    lv_obj_set_height(ui_Header_Group, 48);
    lv_obj_set_width(ui_Header_Group, lv_pct(100));
    lv_obj_set_align(ui_Header_Group, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Header_Group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Header_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon_Group = lv_obj_create(ui_Header_Group);
    lv_obj_set_width(ui_Menu_Icon_Group, 54);
    lv_obj_set_height(ui_Menu_Icon_Group, 50);
    lv_obj_set_align(ui_Menu_Icon_Group, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_Menu_Icon_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Menu_Icon_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Menu_Icon_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon = lv_img_create(ui_Menu_Icon_Group);
    lv_img_set_src(ui_Menu_Icon, &ui_img_hamburger_png);
    lv_obj_set_width(ui_Menu_Icon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Menu_Icon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Menu_Icon, 5);
    lv_obj_set_y(ui_Menu_Icon, 0);
    lv_obj_set_align(ui_Menu_Icon, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Menu_Icon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Menu_Icon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Date = lv_label_create(ui_Header_Group);
    lv_obj_set_width(ui_Date, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Date, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Date, 40);
    lv_obj_set_y(ui_Date, 0);
    lv_obj_set_align(ui_Date, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Date, "Thu, October 24");
    lv_obj_set_style_text_color(ui_Date, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Date, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Avatar = lv_img_create(ui_Header_Group);
    lv_img_set_src(ui_Avatar, &ui_img_avatar_png);
    lv_obj_set_width(ui_Avatar, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Avatar, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Avatar, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_Avatar, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Avatar, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Home_Label2 = lv_label_create(ui_Header_Group);
    lv_obj_set_width(ui_Home_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Home_Label2, -60);
    lv_obj_set_y(ui_Home_Label2, 0);
    lv_obj_set_align(ui_Home_Label2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Home_Label2, "Good morning, Elena!");
    lv_obj_set_style_text_color(ui_Home_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Home_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Home_Label2, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Content_Group = lv_obj_create(ui_Home_Group);
    lv_obj_set_width(ui_Content_Group, lv_pct(100));
    lv_obj_set_flex_grow(ui_Content_Group, 1);
    lv_obj_set_align(ui_Content_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Content_Group, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Content_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Content_Group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_ELASTIC);      /// Flags
    lv_obj_set_style_bg_color(ui_Content_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Content_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Content_Group, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Content_Group, lv_color_hex(0x6D7293), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_Time_Group = ui_Time_Group_create(ui_Content_Group);
    lv_obj_set_height(ui_Time_Group, 310);
    lv_obj_set_flex_grow(ui_Time_Group, 1);
    lv_obj_set_x(ui_Time_Group, 0);
    lv_obj_set_y(ui_Time_Group, 0);
    lv_obj_clear_flag(ui_Time_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT), LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP),
                      LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_Temperature_Group = ui_Temperature_Group_create(ui_Content_Group);
    lv_obj_set_height(ui_Temperature_Group, 310);
    lv_obj_set_flex_grow(ui_Temperature_Group, 1);
    lv_obj_set_x(ui_Temperature_Group, 0);
    lv_obj_set_y(ui_Temperature_Group, 0);
    lv_obj_clear_flag(ui_Temperature_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Temperature_Group, UI_COMP_TEMPERATURE_GROUP_CONTENT),
                      LV_OBJ_FLAG_CLICKABLE);    /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Temperature_Group, UI_COMP_TEMPERATURE_GROUP_CONTENT_CONTENT_GROUP_1),
                      LV_OBJ_FLAG_CLICKABLE);     /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Temperature_Group, UI_COMP_TEMPERATURE_GROUP_TITLE_NUMBER_GROUP1),
                      LV_OBJ_FLAG_CLICKABLE);     /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Temperature_Group, UI_COMP_TEMPERATURE_GROUP_TITLE_NUMBER_GROUP2),
                      LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_Weather_Group = ui_Weather_Group_create(ui_Content_Group);
    lv_obj_set_height(ui_Weather_Group, 310);
    lv_obj_set_flex_grow(ui_Weather_Group, 1);
    lv_obj_set_x(ui_Weather_Group, 0);
    lv_obj_set_y(ui_Weather_Group, 0);
    lv_obj_clear_flag(ui_Weather_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Weather_Group, UI_COMP_WEATHER_GROUP_CONTENT),
                      LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Weather_Group, UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP),
                      LV_OBJ_FLAG_CLICKABLE);     /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Weather_Group, UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP3),
                      LV_OBJ_FLAG_CLICKABLE);    /// Flags

    lv_obj_clear_flag(ui_comp_get_child(ui_Weather_Group, UI_COMP_WEATHER_GROUP_CONTENT_CONTENT_GROUP_2),
                      LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_Footer = ui_Footer_create(ui_Home_Group);
    lv_obj_set_x(ui_Footer, 0);
    lv_obj_set_y(ui_Footer, 0);

    lv_obj_add_flag(ui_comp_get_child(ui_Footer, UI_COMP_FOOTER_HOME_BUTTON), LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_Settings_Group = ui_Settings_Group_create(ui_Home_Screen);
    lv_obj_set_x(ui_Settings_Group, 0);
    lv_obj_set_y(ui_Settings_Group, 0);
    lv_obj_clear_flag(ui_Settings_Group, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_add_flag(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                    LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);    /// Flags

    lv_obj_set_x(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), -350);
    lv_obj_set_y(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL),
                              lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), &ui_img_bg_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH),
                       LV_STATE_CHECKED);     /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH),
                       LV_STATE_CHECKED);     /// States

    ui_Notifi_Group = lv_obj_create(ui_Home_Screen);
    lv_obj_set_width(ui_Notifi_Group, 335);
    lv_obj_set_height(ui_Notifi_Group, lv_pct(100));
    lv_obj_set_align(ui_Notifi_Group, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_Notifi_Group, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Notifi_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Notifi_Group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Notifi_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Notifi_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Notifi_Windows = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_Windows, 0);
    lv_obj_set_width(ui_Notifi_Windows, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Windows, 0);
    lv_obj_set_y(ui_Notifi_Windows, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Windows, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Windows have been opened!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Windows, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_windows_png);

    ui_Notifi_Doors = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_Doors, 0);
    lv_obj_set_width(ui_Notifi_Doors, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Doors, 0);
    lv_obj_set_y(ui_Notifi_Doors, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Doors, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Doors have been opened!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Doors, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_ble_doors_png);

    ui_Notifi_Wifi = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_Wifi, 0);
    lv_obj_set_width(ui_Notifi_Wifi, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Wifi, 0);
    lv_obj_set_y(ui_Notifi_Wifi, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "WiFi has been connected!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    ui_Notifi_BLE = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_BLE, 0);
    lv_obj_set_width(ui_Notifi_BLE, lv_pct(100));
    lv_obj_set_x(ui_Notifi_BLE, 0);
    lv_obj_set_y(ui_Notifi_BLE, -70);

    ui_Notifi_Lights = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_Lights, 0);
    lv_obj_set_width(ui_Notifi_Lights, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Lights, 0);
    lv_obj_set_y(ui_Notifi_Lights, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Lights, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Lights have been turned on!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Lights, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_ble_lights_png);

    ui_Notifi_Windows_Off = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_Windows_Off, 0);
    lv_obj_set_width(ui_Notifi_Windows_Off, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Windows_Off, 0);
    lv_obj_set_y(ui_Notifi_Windows_Off, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Windows_Off, UI_COMP_NOTIFI_GROUP_CONTENT),
                              lv_color_hex(0xD22832), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Windows_Off, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Windows_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Windows have been closed!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Windows_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_windows_png);

    ui_Notifi_Doors_Off = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_Doors_Off, 0);
    lv_obj_set_width(ui_Notifi_Doors_Off, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Doors_Off, 0);
    lv_obj_set_y(ui_Notifi_Doors_Off, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Doors_Off, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Doors_Off, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Doors_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Doors have been closed!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Doors_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_doors_png);

    ui_Notifi_Wifi_Off = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_Wifi_Off, 0);
    lv_obj_set_width(ui_Notifi_Wifi_Off, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Wifi_Off, 0);
    lv_obj_set_y(ui_Notifi_Wifi_Off, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Wifi_Off, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Wifi_Off, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "WiFi has been disconnected!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    ui_Notifi_BLE_Off = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_BLE_Off, 0);
    lv_obj_set_width(ui_Notifi_BLE_Off, lv_pct(100));
    lv_obj_set_x(ui_Notifi_BLE_Off, 0);
    lv_obj_set_y(ui_Notifi_BLE_Off, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_BLE_Off, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_BLE_Off, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_BLE_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Bluetooth has been disconnected!");

    ui_Notifi_Lights_Off = ui_Notifi_Group_create(ui_Notifi_Group);
    lv_obj_set_height(ui_Notifi_Lights_Off, 0);
    lv_obj_set_width(ui_Notifi_Lights_Off, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Lights_Off, 0);
    lv_obj_set_y(ui_Notifi_Lights_Off, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Lights_Off, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Lights_Off, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Lights_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Lights have been turned off!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Lights_Off, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_lights_png);

    lv_obj_add_event_cb(ui_Menu_Icon_Group, ui_event_Menu_Icon_Group, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Time_Group, ui_event_Time_Group_Time_Group, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Temperature_Group, ui_event_Temperature_Group_Temperature_Group, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Weather_Group, ui_event_Weather_Group_Weather_Group, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                        ui_event_Settings_Group_Settings_Dark, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH),
                        ui_event_Settings_Group_List_Bluetooth_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH),
                        ui_event_Settings_Group_List_Wifi_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH),
                        ui_event_Settings_Group_List_Lights_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH),
                        ui_event_Settings_Group_List_Windows_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH),
                        ui_event_Settings_Group_List_Doors_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Home_Screen, ui_event_Home_Screen, LV_EVENT_ALL, NULL);

}
void ui_Time_Screen_screen_init(void)
{
    ui_Time_Screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Time_Screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Time_Screen, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Group1 = lv_obj_create(ui_Time_Screen);
    lv_obj_set_width(ui_Home_Group1, lv_pct(100));
    lv_obj_set_height(ui_Home_Group1, lv_pct(100));
    lv_obj_set_align(ui_Home_Group1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Home_Group1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Home_Group1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Home_Group1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Home_Group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home_Group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Home_Group1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Home_Group1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Home_Group1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Home_Group1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Home_Group1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Home_Group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Group1 = lv_obj_create(ui_Home_Group1);
    lv_obj_set_height(ui_Header_Group1, 48);
    lv_obj_set_width(ui_Header_Group1, lv_pct(100));
    lv_obj_set_align(ui_Header_Group1, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Header_Group1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Header_Group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header_Group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon_Group1 = lv_obj_create(ui_Header_Group1);
    lv_obj_set_width(ui_Menu_Icon_Group1, 54);
    lv_obj_set_height(ui_Menu_Icon_Group1, 50);
    lv_obj_set_align(ui_Menu_Icon_Group1, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_Menu_Icon_Group1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Menu_Icon_Group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Menu_Icon_Group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon1 = lv_img_create(ui_Menu_Icon_Group1);
    lv_img_set_src(ui_Menu_Icon1, &ui_img_hamburger_png);
    lv_obj_set_width(ui_Menu_Icon1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Menu_Icon1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Menu_Icon1, 5);
    lv_obj_set_y(ui_Menu_Icon1, 0);
    lv_obj_set_align(ui_Menu_Icon1, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Menu_Icon1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Menu_Icon1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Date1 = lv_label_create(ui_Header_Group1);
    lv_obj_set_width(ui_Date1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Date1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Date1, 40);
    lv_obj_set_y(ui_Date1, 0);
    lv_obj_set_align(ui_Date1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Date1, "Thu, October 24");
    lv_obj_set_style_text_color(ui_Date1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Date1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Date1, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Avatar1 = lv_img_create(ui_Header_Group1);
    lv_img_set_src(ui_Avatar1, &ui_img_avatar_png);
    lv_obj_set_width(ui_Avatar1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Avatar1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Avatar1, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_Avatar1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Avatar1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Home_Label5 = lv_label_create(ui_Header_Group1);
    lv_obj_set_width(ui_Home_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Home_Label5, -60);
    lv_obj_set_y(ui_Home_Label5, 0);
    lv_obj_set_align(ui_Home_Label5, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Home_Label5, "Good morning, Elena!");
    lv_obj_set_style_text_color(ui_Home_Label5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Home_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Home_Label5, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Content_Group1 = lv_obj_create(ui_Home_Group1);
    lv_obj_set_width(ui_Content_Group1, lv_pct(100));
    lv_obj_set_flex_grow(ui_Content_Group1, 1);
    lv_obj_set_align(ui_Content_Group1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Content_Group1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Content_Group1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Content_Group1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_ELASTIC);      /// Flags
    lv_obj_set_style_bg_color(ui_Content_Group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Content_Group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Content_Group1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Content_Group1, lv_color_hex(0x6D7293), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group1, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_Time_Group1 = ui_Time_Group_create(ui_Content_Group1);
    lv_obj_set_height(ui_Time_Group1, 310);
    lv_obj_set_flex_grow(ui_Time_Group1, 1);
    lv_obj_set_x(ui_Time_Group1, 0);
    lv_obj_set_y(ui_Time_Group1, 0);
    lv_obj_clear_flag(ui_Time_Group1, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_World_Time_Group = lv_obj_create(ui_Content_Group1);
    lv_obj_set_height(ui_World_Time_Group, 310);
    lv_obj_set_flex_grow(ui_World_Time_Group, 1);
    lv_obj_set_align(ui_World_Time_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_World_Time_Group, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_World_Time_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_World_Time_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_World_Time_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_World_Time_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_World_Time_Group, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_World_Time_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_World_Time_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_World_Time_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_World_Time_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_World_Time_Group, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_World_Time_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_World_Time_List1 = ui_World_Time_List_create(ui_World_Time_Group);
    lv_obj_set_x(ui_World_Time_List1, 0);
    lv_obj_set_y(ui_World_Time_List1, 0);

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List1, UI_COMP_WORLD_TIME_LIST_WORLD_TIME), "20:14");

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List1, UI_COMP_WORLD_TIME_LIST_TIME_DELAY), "Today, +0 hour");

    ui_World_Time_List2 = ui_World_Time_List_create(ui_World_Time_Group);
    lv_obj_set_x(ui_World_Time_List2, 0);
    lv_obj_set_y(ui_World_Time_List2, 0);

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List2, UI_COMP_WORLD_TIME_LIST_WORLD_TIME), "17:14");

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List2, UI_COMP_WORLD_TIME_LIST_TIME_DELAY), "Today, -3 hours");

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List2, UI_COMP_WORLD_TIME_LIST_WORLD_TIME_CITY), "Los Angeles");

    ui_World_Time_List3 = ui_World_Time_List_create(ui_World_Time_Group);
    lv_obj_set_x(ui_World_Time_List3, 0);
    lv_obj_set_y(ui_World_Time_List3, 0);

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List3, UI_COMP_WORLD_TIME_LIST_WORLD_TIME), "04:14");

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List3, UI_COMP_WORLD_TIME_LIST_TIME_DELAY), "Tomorrow, +6 hours");

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List3, UI_COMP_WORLD_TIME_LIST_WORLD_TIME_CITY), "Budapest");

    ui_World_Time_List4 = ui_World_Time_List_create(ui_World_Time_Group);
    lv_obj_set_x(ui_World_Time_List4, 0);
    lv_obj_set_y(ui_World_Time_List4, 0);

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List4, UI_COMP_WORLD_TIME_LIST_WORLD_TIME), "00:14");

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List4, UI_COMP_WORLD_TIME_LIST_TIME_DELAY), "Tomorrow, +4 hours");

    lv_label_set_text(ui_comp_get_child(ui_World_Time_List4, UI_COMP_WORLD_TIME_LIST_WORLD_TIME_CITY), "Sydney");

    ui_Footer2 = ui_Footer_create(ui_Home_Group1);
    lv_obj_set_x(ui_Footer2, 0);
    lv_obj_set_y(ui_Footer2, 0);

    ui_Settings_Group1 = ui_Settings_Group_create(ui_Time_Screen);
    lv_obj_set_x(ui_Settings_Group1, 0);
    lv_obj_set_y(ui_Settings_Group1, 0);
    lv_obj_clear_flag(ui_Settings_Group1, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_add_flag(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                    LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);    /// Flags

    lv_obj_set_x(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), -350);
    lv_obj_set_y(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL),
                              lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL),
                                &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH),
                       LV_STATE_CHECKED);    /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH),
                       LV_STATE_CHECKED);     /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    ui_Notifi_Group1 = lv_obj_create(ui_Time_Screen);
    lv_obj_set_width(ui_Notifi_Group1, 335);
    lv_obj_set_height(ui_Notifi_Group1, lv_pct(100));
    lv_obj_set_align(ui_Notifi_Group1, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_Notifi_Group1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Notifi_Group1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Notifi_Group1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Notifi_Group1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Notifi_Group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Notifi_Windows1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_Windows1, 0);
    lv_obj_set_width(ui_Notifi_Windows1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Windows1, 0);
    lv_obj_set_y(ui_Notifi_Windows1, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Windows1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Windows have been opened!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Windows1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_windows_png);

    ui_Notifi_Doors1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_Doors1, 0);
    lv_obj_set_width(ui_Notifi_Doors1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Doors1, 0);
    lv_obj_set_y(ui_Notifi_Doors1, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Doors1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Doors have been opened!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Doors1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_ble_doors_png);

    ui_Notifi_Wifi1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_Wifi1, 0);
    lv_obj_set_width(ui_Notifi_Wifi1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Wifi1, 0);
    lv_obj_set_y(ui_Notifi_Wifi1, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "WiFi has been connected!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    ui_Notifi_BLE1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_BLE1, 0);
    lv_obj_set_width(ui_Notifi_BLE1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_BLE1, 0);
    lv_obj_set_y(ui_Notifi_BLE1, -70);

    ui_Notifi_Lights1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_Lights1, 0);
    lv_obj_set_width(ui_Notifi_Lights1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Lights1, 0);
    lv_obj_set_y(ui_Notifi_Lights1, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Lights1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Lights have been turned on!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Lights1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_ble_lights_png);

    ui_Notifi_Windows_Off1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_Windows_Off1, 0);
    lv_obj_set_width(ui_Notifi_Windows_Off1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Windows_Off1, 0);
    lv_obj_set_y(ui_Notifi_Windows_Off1, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Windows_Off1, UI_COMP_NOTIFI_GROUP_CONTENT),
                              lv_color_hex(0xD22832), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Windows_Off1, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Windows_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Windows have been closed!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Windows_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_windows_png);

    ui_Notifi_Doors_Off1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_Doors_Off1, 0);
    lv_obj_set_width(ui_Notifi_Doors_Off1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Doors_Off1, 0);
    lv_obj_set_y(ui_Notifi_Doors_Off1, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Doors_Off1, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Doors_Off1, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Doors_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Doors have been closed!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Doors_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_doors_png);

    ui_Notifi_Wifi_Off1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_Wifi_Off1, 0);
    lv_obj_set_width(ui_Notifi_Wifi_Off1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Wifi_Off1, 0);
    lv_obj_set_y(ui_Notifi_Wifi_Off1, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Wifi_Off1, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Wifi_Off1, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "WiFi has been disconnected!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    ui_Notifi_BLE_Off1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_BLE_Off1, 0);
    lv_obj_set_width(ui_Notifi_BLE_Off1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_BLE_Off1, 0);
    lv_obj_set_y(ui_Notifi_BLE_Off1, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_BLE_Off1, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_BLE_Off1, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_BLE_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Bluetooth has been disconnected!");

    ui_Notifi_Lights_Off1 = ui_Notifi_Group_create(ui_Notifi_Group1);
    lv_obj_set_height(ui_Notifi_Lights_Off1, 0);
    lv_obj_set_width(ui_Notifi_Lights_Off1, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Lights_Off1, 0);
    lv_obj_set_y(ui_Notifi_Lights_Off1, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Lights_Off1, UI_COMP_NOTIFI_GROUP_CONTENT),
                              lv_color_hex(0xD22832), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Lights_Off1, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Lights_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Lights have been turned off!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Lights_Off1, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_lights_png);

    lv_obj_add_event_cb(ui_Menu_Icon_Group1, ui_event_Menu_Icon_Group1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Footer2, UI_COMP_FOOTER_HOME_BUTTON), ui_event_Footer2_Home_Button,
                        LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                        ui_event_Settings_Group1_Settings_Dark, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH),
                        ui_event_Settings_Group1_List_Bluetooth_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH),
                        ui_event_Settings_Group1_List_Wifi_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH),
                        ui_event_Settings_Group1_List_Lights_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH),
                        ui_event_Settings_Group1_List_Windows_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group1, UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH),
                        ui_event_Settings_Group1_List_Doors_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Time_Screen, ui_event_Time_Screen, LV_EVENT_ALL, NULL);

}
void ui_Weather_Screen_screen_init(void)
{
    ui_Weather_Screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Weather_Screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Weather_Screen, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Group2 = lv_obj_create(ui_Weather_Screen);
    lv_obj_set_width(ui_Home_Group2, lv_pct(100));
    lv_obj_set_height(ui_Home_Group2, lv_pct(100));
    lv_obj_set_align(ui_Home_Group2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Home_Group2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Home_Group2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Home_Group2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Home_Group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Home_Group2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Home_Group2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Home_Group2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Home_Group2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Home_Group2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Home_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Group2 = lv_obj_create(ui_Home_Group2);
    lv_obj_set_height(ui_Header_Group2, 48);
    lv_obj_set_width(ui_Header_Group2, lv_pct(100));
    lv_obj_set_align(ui_Header_Group2, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Header_Group2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Header_Group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon_Group2 = lv_obj_create(ui_Header_Group2);
    lv_obj_set_width(ui_Menu_Icon_Group2, 54);
    lv_obj_set_height(ui_Menu_Icon_Group2, 50);
    lv_obj_set_align(ui_Menu_Icon_Group2, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_Menu_Icon_Group2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Menu_Icon_Group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Menu_Icon_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon2 = lv_img_create(ui_Menu_Icon_Group2);
    lv_img_set_src(ui_Menu_Icon2, &ui_img_hamburger_png);
    lv_obj_set_width(ui_Menu_Icon2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Menu_Icon2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Menu_Icon2, 5);
    lv_obj_set_y(ui_Menu_Icon2, 0);
    lv_obj_set_align(ui_Menu_Icon2, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Menu_Icon2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Menu_Icon2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Date2 = lv_label_create(ui_Header_Group2);
    lv_obj_set_width(ui_Date2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Date2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Date2, 40);
    lv_obj_set_y(ui_Date2, 0);
    lv_obj_set_align(ui_Date2, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Date2, "Thu, October 24");
    lv_obj_set_style_text_color(ui_Date2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Date2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Date2, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Avatar2 = lv_img_create(ui_Header_Group2);
    lv_img_set_src(ui_Avatar2, &ui_img_avatar_png);
    lv_obj_set_width(ui_Avatar2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Avatar2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Avatar2, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_Avatar2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Avatar2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Home_Label6 = lv_label_create(ui_Header_Group2);
    lv_obj_set_width(ui_Home_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Home_Label6, -60);
    lv_obj_set_y(ui_Home_Label6, 0);
    lv_obj_set_align(ui_Home_Label6, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Home_Label6, "Good morning, Elena!");
    lv_obj_set_style_text_color(ui_Home_Label6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Home_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Home_Label6, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Content_Group2 = lv_obj_create(ui_Home_Group2);
    lv_obj_set_width(ui_Content_Group2, lv_pct(100));
    lv_obj_set_flex_grow(ui_Content_Group2, 1);
    lv_obj_set_align(ui_Content_Group2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Content_Group2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Content_Group2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Content_Group2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_ELASTIC);      /// Flags
    lv_obj_set_style_bg_color(ui_Content_Group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Content_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Content_Group2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Content_Group2, lv_color_hex(0x6D7293), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_Weather_Group1 = ui_Weather_Group_create(ui_Content_Group2);
    lv_obj_set_height(ui_Weather_Group1, 310);
    lv_obj_set_flex_grow(ui_Weather_Group1, 1);
    lv_obj_set_x(ui_Weather_Group1, 0);
    lv_obj_set_y(ui_Weather_Group1, 0);
    lv_obj_clear_flag(ui_Weather_Group1, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_Weather_Content_Group = lv_obj_create(ui_Content_Group2);
    lv_obj_set_height(ui_Weather_Content_Group, 310);
    lv_obj_set_flex_grow(ui_Weather_Content_Group, 2);
    lv_obj_set_align(ui_Weather_Content_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Weather_Content_Group, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Weather_Content_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Weather_Content_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Weather_Content_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Weather_Content_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Weather_Content_Group, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Weather_Content_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Weather_Content_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Weather_Content_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Weather_Content_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Weather_Content_Group, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Weather_Content_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeatheGroupList = ui_WeatheGroupList_create(ui_Weather_Content_Group);
    lv_obj_set_x(ui_WeatheGroupList, 0);
    lv_obj_set_y(ui_WeatheGroupList, 0);

    ui_WeatheGroupList1 = ui_WeatheGroupList_create(ui_Weather_Content_Group);
    lv_obj_set_x(ui_WeatheGroupList1, 0);
    lv_obj_set_y(ui_WeatheGroupList1, 0);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList1,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_WEATHER_CITY_STATUS_WEATHER_CITY), "Budapest");

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList1,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_WEATHER_CITY_STATUS_WEATHER_STATUS), "Suny");

    lv_img_set_src(ui_comp_get_child(ui_WeatheGroupList1, UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP_WEATHER_ICON_1),
                   &ui_img_weather_sun_png);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList1,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE), "31°");

    lv_img_set_src(ui_comp_get_child(ui_WeatheGroupList1, UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP1_WEATHER_ICON_1),
                   &ui_img_weather_sun_png);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList1,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP1_WEATHER_ICON_DEGREE), "32°");

    lv_img_set_src(ui_comp_get_child(ui_WeatheGroupList1, UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP2_WEATHER_ICON_1),
                   &ui_img_weather_sun_cloud_png);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList1,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP2_WEATHER_ICON_DEGREE), "30°");

    lv_img_set_src(ui_comp_get_child(ui_WeatheGroupList1, UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP3_WEATHER_ICON_1),
                   &ui_img_weather_sun_cloud_png);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList1,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP3_WEATHER_ICON_DEGREE), "29°");

    ui_WeatheGroupList2 = ui_WeatheGroupList_create(ui_Weather_Content_Group);
    lv_obj_set_x(ui_WeatheGroupList2, 0);
    lv_obj_set_y(ui_WeatheGroupList2, 0);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList2,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_WEATHER_CITY_STATUS_WEATHER_CITY), "New York");

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList2,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_WEATHER_CITY_STATUS_WEATHER_STATUS), "Cloudy");

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList2,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_DEGREE_GRUP_DEGREE1), "18°");

    lv_img_set_src(ui_comp_get_child(ui_WeatheGroupList2, UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP_WEATHER_ICON_1),
                   &ui_img_weather_cloud_png);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList2,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE), "18°");

    lv_img_set_src(ui_comp_get_child(ui_WeatheGroupList2, UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP1_WEATHER_ICON_1),
                   &ui_img_weather_cloud_fog_png);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList2,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP1_WEATHER_ICON_DEGREE), "20°");

    lv_img_set_src(ui_comp_get_child(ui_WeatheGroupList2, UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP2_WEATHER_ICON_1),
                   &ui_img_weather_cloud_fog_png);

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList2,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP2_WEATHER_ICON_DEGREE), "18°");

    lv_label_set_text(ui_comp_get_child(ui_WeatheGroupList2,
                                        UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP3_WEATHER_ICON_DEGREE), "16°");

    ui_Footer1 = ui_Footer_create(ui_Home_Group2);
    lv_obj_set_x(ui_Footer1, 0);
    lv_obj_set_y(ui_Footer1, 0);

    ui_Settings_Group2 = ui_Settings_Group_create(ui_Weather_Screen);
    lv_obj_set_x(ui_Settings_Group2, 0);
    lv_obj_set_y(ui_Settings_Group2, 0);
    lv_obj_clear_flag(ui_Settings_Group2, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_add_flag(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                    LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);    /// Flags

    lv_obj_set_x(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), -350);
    lv_obj_set_y(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL),
                              lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL),
                                &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH),
                       LV_STATE_CHECKED);    /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH),
                       LV_STATE_CHECKED);     /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    ui_Notifi_Group2 = lv_obj_create(ui_Weather_Screen);
    lv_obj_set_width(ui_Notifi_Group2, 335);
    lv_obj_set_height(ui_Notifi_Group2, lv_pct(100));
    lv_obj_set_align(ui_Notifi_Group2, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_Notifi_Group2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Notifi_Group2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Notifi_Group2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Notifi_Group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Notifi_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Notifi_Windows2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_Windows2, 0);
    lv_obj_set_width(ui_Notifi_Windows2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Windows2, 0);
    lv_obj_set_y(ui_Notifi_Windows2, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Windows2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Windows have been opened!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Windows2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_windows_png);

    ui_Notifi_Doors2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_Doors2, 0);
    lv_obj_set_width(ui_Notifi_Doors2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Doors2, 0);
    lv_obj_set_y(ui_Notifi_Doors2, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Doors2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Doors have been opened!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Doors2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_ble_doors_png);

    ui_Notifi_Wifi2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_Wifi2, 0);
    lv_obj_set_width(ui_Notifi_Wifi2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Wifi2, 0);
    lv_obj_set_y(ui_Notifi_Wifi2, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "WiFi has been connected!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    ui_Notifi_BLE2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_BLE2, 0);
    lv_obj_set_width(ui_Notifi_BLE2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_BLE2, 0);
    lv_obj_set_y(ui_Notifi_BLE2, -70);

    ui_Notifi_Lights2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_Lights2, 0);
    lv_obj_set_width(ui_Notifi_Lights2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Lights2, 0);
    lv_obj_set_y(ui_Notifi_Lights2, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Lights2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Lights have been turned on!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Lights2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_ble_lights_png);

    ui_Notifi_Windows_Off2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_Windows_Off2, 0);
    lv_obj_set_width(ui_Notifi_Windows_Off2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Windows_Off2, 0);
    lv_obj_set_y(ui_Notifi_Windows_Off2, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Windows_Off2, UI_COMP_NOTIFI_GROUP_CONTENT),
                              lv_color_hex(0xD22832), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Windows_Off2, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Windows_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Windows have been closed!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Windows_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_windows_png);

    ui_Notifi_Doors_Off2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_Doors_Off2, 0);
    lv_obj_set_width(ui_Notifi_Doors_Off2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Doors_Off2, 0);
    lv_obj_set_y(ui_Notifi_Doors_Off2, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Doors_Off2, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Doors_Off2, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Doors_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Doors have been closed!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Doors_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_doors_png);

    ui_Notifi_Wifi_Off2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_Wifi_Off2, 0);
    lv_obj_set_width(ui_Notifi_Wifi_Off2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Wifi_Off2, 0);
    lv_obj_set_y(ui_Notifi_Wifi_Off2, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Wifi_Off2, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Wifi_Off2, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "WiFi has been disconnected!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    ui_Notifi_BLE_Off2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_BLE_Off2, 0);
    lv_obj_set_width(ui_Notifi_BLE_Off2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_BLE_Off2, 0);
    lv_obj_set_y(ui_Notifi_BLE_Off2, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_BLE_Off2, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_BLE_Off2, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_BLE_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Bluetooth has been disconnected!");

    ui_Notifi_Lights_Off2 = ui_Notifi_Group_create(ui_Notifi_Group2);
    lv_obj_set_height(ui_Notifi_Lights_Off2, 0);
    lv_obj_set_width(ui_Notifi_Lights_Off2, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Lights_Off2, 0);
    lv_obj_set_y(ui_Notifi_Lights_Off2, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Lights_Off2, UI_COMP_NOTIFI_GROUP_CONTENT),
                              lv_color_hex(0xD22832), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Lights_Off2, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Lights_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Lights have been turned off!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Lights_Off2, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_lights_png);

    lv_obj_add_event_cb(ui_Menu_Icon_Group2, ui_event_Menu_Icon_Group2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Footer1, UI_COMP_FOOTER_HOME_BUTTON), ui_event_Footer1_Home_Button,
                        LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                        ui_event_Settings_Group2_Settings_Dark, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH),
                        ui_event_Settings_Group2_List_Bluetooth_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH),
                        ui_event_Settings_Group2_List_Wifi_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH),
                        ui_event_Settings_Group2_List_Lights_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH),
                        ui_event_Settings_Group2_List_Windows_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group2, UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH),
                        ui_event_Settings_Group2_List_Doors_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Weather_Screen, ui_event_Weather_Screen, LV_EVENT_ALL, NULL);

}
void ui_Thermostat_Screen_screen_init(void)
{
    ui_Thermostat_Screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Thermostat_Screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Thermostat_Screen, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Group3 = lv_obj_create(ui_Thermostat_Screen);
    lv_obj_set_width(ui_Home_Group3, lv_pct(100));
    lv_obj_set_height(ui_Home_Group3, lv_pct(100));
    lv_obj_set_align(ui_Home_Group3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Home_Group3, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Home_Group3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Home_Group3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Home_Group3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home_Group3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Home_Group3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Home_Group3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Home_Group3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Home_Group3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Home_Group3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Home_Group3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Group3 = lv_obj_create(ui_Home_Group3);
    lv_obj_set_height(ui_Header_Group3, 48);
    lv_obj_set_width(ui_Header_Group3, lv_pct(100));
    lv_obj_set_align(ui_Header_Group3, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Header_Group3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Header_Group3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header_Group3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon_Group3 = lv_obj_create(ui_Header_Group3);
    lv_obj_set_width(ui_Menu_Icon_Group3, 54);
    lv_obj_set_height(ui_Menu_Icon_Group3, 50);
    lv_obj_set_align(ui_Menu_Icon_Group3, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_Menu_Icon_Group3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Menu_Icon_Group3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Menu_Icon_Group3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon3 = lv_img_create(ui_Menu_Icon_Group3);
    lv_img_set_src(ui_Menu_Icon3, &ui_img_hamburger_png);
    lv_obj_set_width(ui_Menu_Icon3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Menu_Icon3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Menu_Icon3, 5);
    lv_obj_set_y(ui_Menu_Icon3, 0);
    lv_obj_set_align(ui_Menu_Icon3, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Menu_Icon3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Menu_Icon3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Date3 = lv_label_create(ui_Header_Group3);
    lv_obj_set_width(ui_Date3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Date3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Date3, 40);
    lv_obj_set_y(ui_Date3, 0);
    lv_obj_set_align(ui_Date3, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Date3, "Thu, October 24");
    lv_obj_set_style_text_color(ui_Date3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Date3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Date3, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Avatar3 = lv_img_create(ui_Header_Group3);
    lv_img_set_src(ui_Avatar3, &ui_img_avatar_png);
    lv_obj_set_width(ui_Avatar3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Avatar3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Avatar3, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_Avatar3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Avatar3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Home_Label7 = lv_label_create(ui_Header_Group3);
    lv_obj_set_width(ui_Home_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Home_Label7, -60);
    lv_obj_set_y(ui_Home_Label7, 0);
    lv_obj_set_align(ui_Home_Label7, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Home_Label7, "Good morning, Elena!");
    lv_obj_set_style_text_color(ui_Home_Label7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Home_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Home_Label7, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Content_Group3 = lv_obj_create(ui_Home_Group3);
    lv_obj_set_width(ui_Content_Group3, lv_pct(100));
    lv_obj_set_flex_grow(ui_Content_Group3, 1);
    lv_obj_set_align(ui_Content_Group3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Content_Group3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Content_Group3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Content_Group3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLL_ELASTIC);      /// Flags
    lv_obj_set_style_bg_color(ui_Content_Group3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Content_Group3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Content_Group3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Content_Group3, lv_color_hex(0x6D7293), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group3, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_Weather_Content_Group1 = lv_obj_create(ui_Content_Group3);
    lv_obj_set_height(ui_Weather_Content_Group1, 310);
    lv_obj_set_flex_grow(ui_Weather_Content_Group1, 2);
    lv_obj_set_align(ui_Weather_Content_Group1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Weather_Content_Group1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Weather_Content_Group1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Weather_Content_Group1, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Weather_Content_Group1, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Weather_Content_Group1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Weather_Content_Group1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Weather_Content_Group1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Weather_Content_Group1, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Weather_Content_Group1, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Weather_Content_Group1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chart2 = lv_chart_create(ui_Weather_Content_Group1);
    lv_obj_set_width(ui_Chart2, lv_pct(95));
    lv_obj_set_height(ui_Chart2, lv_pct(100));
    lv_obj_set_align(ui_Chart2, LV_ALIGN_RIGHT_MID);
    lv_chart_set_type(ui_Chart2, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(ui_Chart2, 24);
    lv_chart_set_range(ui_Chart2, LV_CHART_AXIS_PRIMARY_Y, 15, 30);
    lv_chart_set_div_line_count(ui_Chart2, 5, 5);
    lv_chart_set_zoom_x(ui_Chart2, 320);
    lv_chart_set_zoom_y(ui_Chart2, 256);
    lv_chart_set_axis_tick(ui_Chart2, LV_CHART_AXIS_PRIMARY_X, 10, 5, 0, 0, true, 50);
    lv_chart_set_axis_tick(ui_Chart2, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 2, true, 50);
    lv_chart_series_t * ui_Chart2_series_1 = lv_chart_add_series(ui_Chart2, lv_color_hex(0x0084FF),
                                                                 LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_Chart2_series_1_array[] = { 19, 20, 20, 21, 20, 21, 23, 23, 24, 23, 23, 23, 22, 22, 22, 23, 23, 23, 23, 24, 25, 25, 24, 23 };
    lv_chart_set_ext_y_array(ui_Chart2, ui_Chart2_series_1, ui_Chart2_series_1_array);
    lv_obj_set_style_bg_color(ui_Chart2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chart2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui_Chart2, lv_color_hex(0x332B5E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui_Chart2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Chart2, lv_color_hex(0x355396), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chart2, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Chart2, 10, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Chart2, 10, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Chart2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Chart2, 5, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    lv_obj_set_style_line_width(ui_Chart2, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui_Chart2, true, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Chart2, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Chart2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chart2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_size(ui_Chart2, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Chart2, lv_color_hex(0xFFFFFF), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Chart2, 255, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Chart2, &ui_font_Subtitle, LV_PART_TICKS | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Chart2);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 0);
    lv_obj_set_y(ui_Label2, 12);
    lv_obj_set_align(ui_Label2, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label2, "Last 24 hours");
    lv_obj_add_flag(ui_Label2, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0x7F84BC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Temperature_Group2 = ui_Temperature_Group_create(ui_Content_Group3);
    lv_obj_set_x(ui_Temperature_Group2, 0);
    lv_obj_set_y(ui_Temperature_Group2, 0);

    ui_Footer3 = ui_Footer_create(ui_Home_Group3);
    lv_obj_set_x(ui_Footer3, 0);
    lv_obj_set_y(ui_Footer3, 0);

    ui_Settings_Group3 = ui_Settings_Group_create(ui_Thermostat_Screen);
    lv_obj_set_x(ui_Settings_Group3, 0);
    lv_obj_set_y(ui_Settings_Group3, 0);
    lv_obj_clear_flag(ui_Settings_Group3, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_add_flag(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                    LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);    /// Flags

    lv_obj_set_x(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), -350);
    lv_obj_set_y(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL),
                              lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0,
                            LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL),
                                &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH),
                       LV_STATE_CHECKED);    /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH),
                       LV_STATE_CHECKED);     /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    lv_obj_clear_state(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH),
                       LV_STATE_CHECKED);   /// States

    ui_Notifi_Group3 = lv_obj_create(ui_Thermostat_Screen);
    lv_obj_set_width(ui_Notifi_Group3, 335);
    lv_obj_set_height(ui_Notifi_Group3, lv_pct(100));
    lv_obj_set_align(ui_Notifi_Group3, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_Notifi_Group3, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Notifi_Group3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Notifi_Group3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Notifi_Group3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Notifi_Group3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Notifi_Windows3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_Windows3, 0);
    lv_obj_set_width(ui_Notifi_Windows3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Windows3, 0);
    lv_obj_set_y(ui_Notifi_Windows3, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Windows3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Windows have been opened!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Windows3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_windows_png);

    ui_Notifi_Doors3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_Doors3, 0);
    lv_obj_set_width(ui_Notifi_Doors3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Doors3, 0);
    lv_obj_set_y(ui_Notifi_Doors3, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Doors3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Doors have been opened!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Doors3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_ble_doors_png);

    ui_Notifi_Wifi3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_Wifi3, 0);
    lv_obj_set_width(ui_Notifi_Wifi3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Wifi3, 0);
    lv_obj_set_y(ui_Notifi_Wifi3, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "WiFi has been connected!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    ui_Notifi_BLE3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_BLE3, 0);
    lv_obj_set_width(ui_Notifi_BLE3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_BLE3, 0);
    lv_obj_set_y(ui_Notifi_BLE3, -70);

    ui_Notifi_Lights3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_Lights3, 0);
    lv_obj_set_width(ui_Notifi_Lights3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Lights3, 0);
    lv_obj_set_y(ui_Notifi_Lights3, -70);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Lights3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Lights have been turned on!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Lights3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_ble_lights_png);

    ui_Notifi_Windows_Off3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_Windows_Off3, 0);
    lv_obj_set_width(ui_Notifi_Windows_Off3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Windows_Off3, 0);
    lv_obj_set_y(ui_Notifi_Windows_Off3, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Windows_Off3, UI_COMP_NOTIFI_GROUP_CONTENT),
                              lv_color_hex(0xD22832), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Windows_Off3, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Windows_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Windows have been closed!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Windows_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_windows_png);

    ui_Notifi_Doors_Off3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_Doors_Off3, 0);
    lv_obj_set_width(ui_Notifi_Doors_Off3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Doors_Off3, 0);
    lv_obj_set_y(ui_Notifi_Doors_Off3, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Doors_Off3, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Doors_Off3, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Doors_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Doors have been closed!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Doors_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_doors_png);

    ui_Notifi_Wifi_Off3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_Wifi_Off3, 0);
    lv_obj_set_width(ui_Notifi_Wifi_Off3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Wifi_Off3, 0);
    lv_obj_set_y(ui_Notifi_Wifi_Off3, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Wifi_Off3, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Wifi_Off3, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "WiFi has been disconnected!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    ui_Notifi_BLE_Off3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_BLE_Off3, 0);
    lv_obj_set_width(ui_Notifi_BLE_Off3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_BLE_Off3, 0);
    lv_obj_set_y(ui_Notifi_BLE_Off3, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_BLE_Off3, UI_COMP_NOTIFI_GROUP_CONTENT), lv_color_hex(0xD22832),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_BLE_Off3, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_BLE_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Bluetooth has been disconnected!");

    ui_Notifi_Lights_Off3 = ui_Notifi_Group_create(ui_Notifi_Group3);
    lv_obj_set_height(ui_Notifi_Lights_Off3, 0);
    lv_obj_set_width(ui_Notifi_Lights_Off3, lv_pct(100));
    lv_obj_set_x(ui_Notifi_Lights_Off3, 0);
    lv_obj_set_y(ui_Notifi_Lights_Off3, -70);

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Notifi_Lights_Off3, UI_COMP_NOTIFI_GROUP_CONTENT),
                              lv_color_hex(0xD22832), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Notifi_Lights_Off3, UI_COMP_NOTIFI_GROUP_CONTENT), 255,
                            LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Lights_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL),
                      "Lights have been turned off!");

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Lights_Off3, UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE),
                   &ui_img_ble_lights_png);

    lv_obj_add_event_cb(ui_Menu_Icon_Group3, ui_event_Menu_Icon_Group3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Footer3, UI_COMP_FOOTER_HOME_BUTTON), ui_event_Footer3_Home_Button,
                        LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                        ui_event_Settings_Group3_Settings_Dark, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH),
                        ui_event_Settings_Group3_List_Bluetooth_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH),
                        ui_event_Settings_Group3_List_Wifi_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH),
                        ui_event_Settings_Group3_List_Lights_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH),
                        ui_event_Settings_Group3_List_Windows_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group3, UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH),
                        ui_event_Settings_Group3_List_Doors_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Thermostat_Screen, ui_event_Thermostat_Screen, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_basic_init(dispp);
    lv_disp_set_theme(dispp, theme);
    ui_Start_Screen_screen_init();
    ui_Home_Screen_screen_init();
    ui_Time_Screen_screen_init();
    ui_Weather_Screen_screen_init();
    ui_Thermostat_Screen_screen_init();
    lv_disp_load_scr(ui_Start_Screen);
}

// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
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
void ui_event_Home(lv_event_t * e);
lv_obj_t * ui_Home;
lv_obj_t * ui_Home_Group;
lv_obj_t * ui_Header_Group;
void ui_event_Menu_Icon(lv_event_t * e);
lv_obj_t * ui_Menu_Icon;
lv_obj_t * ui_Date;
lv_obj_t * ui_Avatar;
lv_obj_t * ui_Home_Label2;
lv_obj_t * ui_Content_Group;
lv_obj_t * ui_Time_Group;
lv_obj_t * ui_Weather_Group;
lv_obj_t * ui_Temperature_Group;
lv_obj_t * ui_Camera_Group;
lv_obj_t * ui_Solarpanels_Group;
lv_obj_t * ui_Music_Group;
lv_obj_t * ui_Footer;
lv_obj_t * ui_Noti_Indicator;
lv_obj_t * ui_Notifi_Text_Group;
lv_obj_t * ui_Home_Label1;
lv_obj_t * ui_Home_Label3;
lv_obj_t * ui_Footer_Indicators_Group;
void ui_event_BLE(lv_event_t * e);
lv_obj_t * ui_BLE;
void ui_event_Wifi(lv_event_t * e);
lv_obj_t * ui_Wifi;
lv_obj_t * ui_Battery_Group;
lv_obj_t * ui_Battery;
lv_obj_t * ui_Home_Label4;
lv_obj_t * ui_Settings_Group;
void ui_event_Settings_Group_Settings_Dark(lv_event_t * e);
void ui_event_Settings_Group_List_Time_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Weather_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Temperature_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Camera_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Solar_Switch(lv_event_t * e);
void ui_event_Settings_Group_List_Music_Switch(lv_event_t * e);
lv_obj_t * ui_Notifi_BLE;
lv_obj_t * ui_Notifi_Wifi;

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
    lv_anim_set_values(&PropertyAnimation_0, 0, 25);
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
    lv_anim_set_values(&PropertyAnimation_1, 0, -8);
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
    lv_anim_set_values(&PropertyAnimation_0, 0, 25);
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
    lv_anim_set_values(&PropertyAnimation_1, 0, -8);
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
    lv_anim_set_values(&PropertyAnimation_0, -200, 0);
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
    lv_anim_set_values(&PropertyAnimation_0, 0, -200);
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
    lv_anim_set_values(&PropertyAnimation_0, -900, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_start(&PropertyAnimation_0);

}
void Hour_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 1700);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_start(&PropertyAnimation_0);

}
void Notifi_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, -70, 10);
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
    lv_anim_set_time(&PropertyAnimation_1, 500);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_1, 10, -70);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_out);
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
    lv_anim_set_values(&PropertyAnimation_0, 134, 0);
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
    lv_anim_set_values(&PropertyAnimation_0, 0, 134);
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

///////////////////// FUNCTIONS ////////////////////
void ui_event_Home(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Sec_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_SEC), 0);
        Sec_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_SEC_SHADOW), 0);
        Rain2_Animation(ui_comp_get_child(ui_Weather_Group, UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_RAIN), 200);
        Rain_Animation(ui_comp_get_child(ui_Weather_Group, UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_RAIN1), 0);
        Min_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_MIN), 0);
        Min_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_MIN_SHADOW), 0);
        Hour_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_HOUR), 0);
        Hour_Animation(ui_comp_get_child(ui_Time_Group, UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_HOUR_SHADOW), 0);
    }
}
void ui_event_Menu_Icon(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SettingsOn_Animation(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL), 0);
        SettingsOpaOn_Animation(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), 0);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_CLICKABLE,
                        _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK), LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_BLE(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_BLE, 0);
    }
}
void ui_event_Wifi(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Notifi_Animation(ui_Notifi_Wifi, 0);
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
void ui_event_Settings_Group_List_Time_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Open_Animation(ui_Time_Group, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Close_Animation(ui_Time_Group, 0);
    }
}
void ui_event_Settings_Group_List_Weather_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Open_Animation(ui_Weather_Group, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Close_Animation(ui_Weather_Group, 0);
    }
}
void ui_event_Settings_Group_List_Temperature_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Open_Animation(ui_Temperature_Group, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Close_Animation(ui_Temperature_Group, 0);
    }
}
void ui_event_Settings_Group_List_Camera_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Open_Animation(ui_Camera_Group, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Close_Animation(ui_Camera_Group, 0);
    }
}
void ui_event_Settings_Group_List_Solar_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Open_Animation(ui_Solarpanels_Group, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Close_Animation(ui_Solarpanels_Group, 0);
    }
}
void ui_event_Settings_Group_List_Music_Switch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Open_Animation(ui_Music_Group, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        Close_Animation(ui_Music_Group, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Home_screen_init(void)
{
    ui_Home = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Home, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Group = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_Home_Group, lv_pct(100));
    lv_obj_set_height(ui_Home_Group, lv_pct(100));
    lv_obj_set_align(ui_Home_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Home_Group, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Home_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Home_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Home_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Home_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Home_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Home_Group, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Home_Group, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Home_Group, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Home_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Group = lv_obj_create(ui_Home_Group);
    lv_obj_set_height(ui_Header_Group, 28);
    lv_obj_set_width(ui_Header_Group, lv_pct(100));
    lv_obj_set_align(ui_Header_Group, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Header_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Header_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu_Icon = lv_img_create(ui_Header_Group);
    lv_img_set_src(ui_Menu_Icon, &ui_img_hamburger_png);
    lv_obj_set_width(ui_Menu_Icon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Menu_Icon, LV_SIZE_CONTENT);    /// 15
    lv_obj_set_align(ui_Menu_Icon, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Menu_Icon, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Menu_Icon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Date = lv_label_create(ui_Header_Group);
    lv_obj_set_width(ui_Date, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Date, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Date, 24);
    lv_obj_set_y(ui_Date, 0);
    lv_obj_set_align(ui_Date, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Date, "Thu, October 24");
    lv_obj_set_style_text_color(ui_Date, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Date, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

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
    lv_obj_set_x(ui_Home_Label2, -40);
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
    lv_obj_set_flex_align(ui_Content_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Content_Group, LV_OBJ_FLAG_SCROLL_ELASTIC);      /// Flags
    lv_obj_set_style_bg_color(ui_Content_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Content_Group, lv_color_hex(0x6D7293), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Content_Group, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_Time_Group = ui_Time_Group_create(ui_Content_Group);
    lv_obj_set_x(ui_Time_Group, 0);
    lv_obj_set_y(ui_Time_Group, 0);
    lv_obj_clear_flag(ui_Time_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_Weather_Group = ui_Weather_Group_create(ui_Content_Group);
    lv_obj_set_x(ui_Weather_Group, 0);
    lv_obj_set_y(ui_Weather_Group, 0);
    lv_obj_clear_flag(ui_Weather_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_Temperature_Group = ui_Temperature_Group_create(ui_Content_Group);
    lv_obj_set_x(ui_Temperature_Group, 0);
    lv_obj_set_y(ui_Temperature_Group, 0);
    lv_obj_clear_flag(ui_Temperature_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_Camera_Group = ui_Camera_Group_create(ui_Content_Group);
    lv_obj_set_x(ui_Camera_Group, 0);
    lv_obj_set_y(ui_Camera_Group, 0);
    lv_obj_clear_flag(ui_Camera_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_Solarpanels_Group = ui_Solarpanels_Group_create(ui_Content_Group);
    lv_obj_set_x(ui_Solarpanels_Group, 0);
    lv_obj_set_y(ui_Solarpanels_Group, 0);
    lv_obj_clear_flag(ui_Solarpanels_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_Music_Group = ui_Music_Group_create(ui_Content_Group);
    lv_obj_set_x(ui_Music_Group, 0);
    lv_obj_set_y(ui_Music_Group, 0);
    lv_obj_clear_flag(ui_Music_Group, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_Footer = lv_obj_create(ui_Home_Group);
    lv_obj_set_height(ui_Footer, 28);
    lv_obj_set_width(ui_Footer, lv_pct(100));
    lv_obj_set_align(ui_Footer, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_Footer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Footer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Footer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Footer, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Footer, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Noti_Indicator = lv_obj_create(ui_Footer);
    lv_obj_set_width(ui_Noti_Indicator, 6);
    lv_obj_set_height(ui_Noti_Indicator, lv_pct(100));
    lv_obj_set_align(ui_Noti_Indicator, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_Noti_Indicator, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Noti_Indicator, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Noti_Indicator, lv_color_hex(0x0084FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Noti_Indicator, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Notifi_Text_Group = lv_obj_create(ui_Footer);
    lv_obj_set_height(ui_Notifi_Text_Group, lv_pct(85));
    lv_obj_set_flex_grow(ui_Notifi_Text_Group, 1);
    lv_obj_set_align(ui_Notifi_Text_Group, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_Notifi_Text_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Notifi_Text_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Notifi_Text_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Label1 = lv_label_create(ui_Notifi_Text_Group);
    lv_obj_set_width(ui_Home_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Label1, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_Home_Label1, "3 upcoming events");
    lv_obj_set_style_text_color(ui_Home_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Home_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Home_Label1, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Label3 = lv_label_create(ui_Notifi_Text_Group);
    lv_obj_set_width(ui_Home_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Home_Label3, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_Home_Label3, "3:00 PM - 4:00 PM : Meeting about Thomas will retire at 30 years old");
    lv_obj_set_style_text_color(ui_Home_Label3, lv_color_hex(0x868BC4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Home_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Home_Label3, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Footer_Indicators_Group = lv_obj_create(ui_Footer);
    lv_obj_set_height(ui_Footer_Indicators_Group, lv_pct(100));
    lv_obj_set_width(ui_Footer_Indicators_Group, LV_SIZE_CONTENT);   /// 124
    lv_obj_set_align(ui_Footer_Indicators_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Footer_Indicators_Group, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Footer_Indicators_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Footer_Indicators_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Footer_Indicators_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Footer_Indicators_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Footer_Indicators_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Footer_Indicators_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Footer_Indicators_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Footer_Indicators_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Footer_Indicators_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Footer_Indicators_Group, 30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BLE = lv_img_create(ui_Footer_Indicators_Group);
    lv_img_set_src(ui_BLE, &ui_img_bluetooth_png);
    lv_obj_set_width(ui_BLE, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BLE, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_BLE, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BLE, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BLE, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_BLE, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_BLE, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_BLE, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui_BLE, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_Wifi = lv_img_create(ui_Footer_Indicators_Group);
    lv_img_set_src(ui_Wifi, &ui_img_wifi_png);
    lv_obj_set_width(ui_Wifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Wifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Wifi, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Wifi, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Wifi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Wifi, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Wifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui_Wifi, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui_Wifi, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_Battery_Group = lv_obj_create(ui_Footer_Indicators_Group);
    lv_obj_set_height(ui_Battery_Group, lv_pct(100));
    lv_obj_set_width(ui_Battery_Group, LV_SIZE_CONTENT);   /// 42
    lv_obj_set_align(ui_Battery_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Battery_Group, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Battery_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Battery_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Battery_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Battery_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Battery_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Battery_Group, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Battery = lv_img_create(ui_Battery_Group);
    lv_img_set_src(ui_Battery, &ui_img_battery_png);
    lv_obj_set_width(ui_Battery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Battery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Battery, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Battery, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Battery, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Home_Label4 = lv_label_create(ui_Battery_Group);
    lv_obj_set_width(ui_Home_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Home_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Home_Label4, "48%");
    lv_obj_set_style_text_color(ui_Home_Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Home_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Home_Label4, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Settings_Group = ui_Settings_Group_create(ui_Home);
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

    ui_Notifi_BLE = ui_Notifi_Group_create(ui_Home);
    lv_obj_set_x(ui_Notifi_BLE, 0);
    lv_obj_set_y(ui_Notifi_BLE, -70);
    lv_obj_set_style_bg_color(ui_Notifi_BLE, lv_color_hex(0x0084FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Notifi_BLE, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Notifi_Wifi = ui_Notifi_Group_create(ui_Home);
    lv_obj_set_x(ui_Notifi_Wifi, 0);
    lv_obj_set_y(ui_Notifi_Wifi, -70);

    lv_img_set_src(ui_comp_get_child(ui_Notifi_Wifi, UI_COMP_NOTIFI_GROUP_NOTIFI_IMAGE), &ui_img_wifi_big_png);

    lv_label_set_text(ui_comp_get_child(ui_Notifi_Wifi, UI_COMP_NOTIFI_GROUP_NOTIFI_LABEL), "Wifi has been connected!");

    lv_obj_add_event_cb(ui_Menu_Icon, ui_event_Menu_Icon, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BLE, ui_event_BLE, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Wifi, ui_event_Wifi, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_SETTINGS_DARK),
                        ui_event_Settings_Group_Settings_Dark, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_TIME_SWITCH),
                        ui_event_Settings_Group_List_Time_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_WEATHER_SWITCH),
                        ui_event_Settings_Group_List_Weather_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_TEMPERATURE_SWITCH),
                        ui_event_Settings_Group_List_Temperature_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_CAMERA_SWITCH),
                        ui_event_Settings_Group_List_Camera_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_SOLAR_SWITCH),
                        ui_event_Settings_Group_List_Solar_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_comp_get_child(ui_Settings_Group, UI_COMP_SETTINGS_GROUP_LIST_MUSIC_SWITCH),
                        ui_event_Settings_Group_List_Music_Switch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Home, ui_event_Home, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_basic_init(dispp);
    lv_disp_set_theme(dispp, theme);
    ui_Home_screen_init();
    lv_disp_load_scr(ui_Home);
}

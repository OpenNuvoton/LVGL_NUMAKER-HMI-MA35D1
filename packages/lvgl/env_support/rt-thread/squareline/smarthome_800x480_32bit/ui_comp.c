// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.3.4
// PROJECT: Smarthome


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


// COMPONENT Footer

lv_obj_t * ui_Footer_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Footer;
    cui_Footer = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Footer, 50);
    lv_obj_set_width(cui_Footer, lv_pct(100));
    lv_obj_set_align(cui_Footer, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_flex_flow(cui_Footer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Footer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Footer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Footer, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_Footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_Footer, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Home_Button;
    cui_Home_Button = lv_btn_create(cui_Footer);
    lv_obj_set_width(cui_Home_Button, 50);
    lv_obj_set_height(cui_Home_Button, 50);
    lv_obj_set_align(cui_Home_Button, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Home_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_Home_Button, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Home_Button, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Home_Button, lv_color_hex(0x0084FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Home_Button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(cui_Home_Button, &ui_img_home_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Noti_Indicator;
    cui_Noti_Indicator = lv_obj_create(cui_Footer);
    lv_obj_set_width(cui_Noti_Indicator, 6);
    lv_obj_set_height(cui_Noti_Indicator, lv_pct(100));
    lv_obj_set_align(cui_Noti_Indicator, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(cui_Noti_Indicator, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Noti_Indicator, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Noti_Indicator, lv_color_hex(0x52DA1C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Noti_Indicator, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Notifi_Text_Group;
    cui_Notifi_Text_Group = lv_obj_create(cui_Footer);
    lv_obj_set_height(cui_Notifi_Text_Group, lv_pct(85));
    lv_obj_set_flex_grow(cui_Notifi_Text_Group, 1);
    lv_obj_set_align(cui_Notifi_Text_Group, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(cui_Notifi_Text_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Notifi_Text_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Notifi_Text_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Home_Label1;
    cui_Home_Label1 = lv_label_create(cui_Notifi_Text_Group);
    lv_obj_set_width(cui_Home_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Home_Label1, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(cui_Home_Label1, "3 upcoming events");
    lv_obj_set_style_text_color(cui_Home_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Home_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Home_Label1, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Home_Label3;
    cui_Home_Label3 = lv_label_create(cui_Notifi_Text_Group);
    lv_obj_set_width(cui_Home_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Home_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Home_Label3, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(cui_Home_Label3, "3:00 PM - 4:00 PM : Meeting with Tom about the new features");
    lv_obj_set_style_text_color(cui_Home_Label3, lv_color_hex(0x868BC4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Home_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Home_Label3, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Footer_Indicators_Group;
    cui_Footer_Indicators_Group = lv_obj_create(cui_Footer);
    lv_obj_set_height(cui_Footer_Indicators_Group, lv_pct(100));
    lv_obj_set_width(cui_Footer_Indicators_Group, LV_SIZE_CONTENT);   /// 124
    lv_obj_set_align(cui_Footer_Indicators_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_Footer_Indicators_Group, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Footer_Indicators_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Footer_Indicators_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Footer_Indicators_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Footer_Indicators_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Footer_Indicators_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Footer_Indicators_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Footer_Indicators_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Footer_Indicators_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_Footer_Indicators_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_Footer_Indicators_Group, 30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_BLE;
    cui_BLE = lv_img_create(cui_Footer_Indicators_Group);
    lv_img_set_src(cui_BLE, &ui_img_bluetooth_png);
    lv_obj_set_width(cui_BLE, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_BLE, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_BLE, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_BLE, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_BLE, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(cui_BLE, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(cui_BLE, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(cui_BLE, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(cui_BLE, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t * cui_Wifi;
    cui_Wifi = lv_img_create(cui_Footer_Indicators_Group);
    lv_img_set_src(cui_Wifi, &ui_img_wifi_png);
    lv_obj_set_width(cui_Wifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Wifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Wifi, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Wifi, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Wifi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(cui_Wifi, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(cui_Wifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(cui_Wifi, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(cui_Wifi, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_t * cui_Battery_Group;
    cui_Battery_Group = lv_obj_create(cui_Footer_Indicators_Group);
    lv_obj_set_height(cui_Battery_Group, lv_pct(100));
    lv_obj_set_width(cui_Battery_Group, LV_SIZE_CONTENT);   /// 42
    lv_obj_set_align(cui_Battery_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_Battery_Group, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Battery_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Battery_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Battery_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Battery_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_Battery_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_Battery_Group, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Battery;
    cui_Battery = lv_img_create(cui_Battery_Group);
    lv_img_set_src(cui_Battery, &ui_img_battery_png);
    lv_obj_set_width(cui_Battery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Battery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Battery, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Battery, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Battery, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Home_Label4;
    cui_Home_Label4 = lv_label_create(cui_Footer);
    lv_obj_set_width(cui_Home_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Home_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Home_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Home_Label4, "48%");
    lv_obj_set_style_text_color(cui_Home_Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Home_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Home_Label4, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_FOOTER_NUM);
    children[UI_COMP_FOOTER_FOOTER] = cui_Footer;
    children[UI_COMP_FOOTER_HOME_BUTTON] = cui_Home_Button;
    children[UI_COMP_FOOTER_NOTI_INDICATOR] = cui_Noti_Indicator;
    children[UI_COMP_FOOTER_NOTIFI_TEXT_GROUP] = cui_Notifi_Text_Group;
    children[UI_COMP_FOOTER_NOTIFI_TEXT_GROUP_HOME_LABEL1] = cui_Home_Label1;
    children[UI_COMP_FOOTER_NOTIFI_TEXT_GROUP_HOME_LABEL3] = cui_Home_Label3;
    children[UI_COMP_FOOTER_FOOTER_INDICATORS_GROUP] = cui_Footer_Indicators_Group;
    children[UI_COMP_FOOTER_FOOTER_INDICATORS_GROUP_BLE] = cui_BLE;
    children[UI_COMP_FOOTER_FOOTER_INDICATORS_GROUP_WIFI] = cui_Wifi;
    children[UI_COMP_FOOTER_FOOTER_INDICATORS_GROUP_BATTERY_GROUP] = cui_Battery_Group;
    children[UI_COMP_FOOTER_FOOTER_INDICATORS_GROUP_BATTERY_GROUP_BATTERY] = cui_Battery;
    children[UI_COMP_FOOTER_HOME_LABEL4] = cui_Home_Label4;
    lv_obj_add_event_cb(cui_Footer, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Footer, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Footer;
}



// COMPONENT List_comp

lv_obj_t * ui_List_comp_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_List_comp;
    cui_List_comp = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_List_comp, 60);
    lv_obj_set_width(cui_List_comp, lv_pct(100));
    lv_obj_set_align(cui_List_comp, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_List_comp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_List_comp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_List_comp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_List_comp, lv_color_hex(0x41455D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_List_comp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_List_comp, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(cui_List_comp, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Settings_Title1;
    cui_Settings_Title1 = lv_label_create(cui_List_comp);
    lv_obj_set_width(cui_Settings_Title1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Settings_Title1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Settings_Title1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Settings_Title1, "Time widget");
    lv_obj_set_style_text_color(cui_Settings_Title1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Settings_Title1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Settings_Title1, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Switch;
    cui_Switch = lv_switch_create(cui_List_comp);
    lv_obj_set_width(cui_Switch, 40);
    lv_obj_set_height(cui_Switch, 20);
    lv_obj_set_x(cui_Switch, -2);
    lv_obj_set_y(cui_Switch, 0);
    lv_obj_set_align(cui_Switch, LV_ALIGN_RIGHT_MID);
    lv_obj_add_state(cui_Switch, LV_STATE_CHECKED);       /// States
    lv_obj_set_style_radius(cui_Switch, 500, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch, lv_color_hex(0x2C3A5F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Switch, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(cui_Switch, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch, lv_color_hex(0x0084FF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_Switch, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(cui_Switch, 50, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Switch, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_LIST_COMP_NUM);
    children[UI_COMP_LIST_COMP_LIST_COMP] = cui_List_comp;
    children[UI_COMP_LIST_COMP_SETTINGS_TITLE1] = cui_Settings_Title1;
    children[UI_COMP_LIST_COMP_SWITCH] = cui_Switch;
    lv_obj_add_event_cb(cui_List_comp, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_List_comp, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_List_comp;
}



// COMPONENT Notifi Group

lv_obj_t * ui_Notifi_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Notifi_Group;
    cui_Notifi_Group = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Notifi_Group, 70);
    lv_obj_set_width(cui_Notifi_Group, lv_pct(100));
    lv_obj_set_x(cui_Notifi_Group, 0);
    lv_obj_set_y(cui_Notifi_Group, -70);
    lv_obj_set_align(cui_Notifi_Group, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_Notifi_Group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Notifi_Group, lv_color_hex(0x14A632), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Notifi_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Notifi_Group);
    lv_obj_set_height(cui_Content, 60);
    lv_obj_set_width(cui_Content, lv_pct(100));
    lv_obj_set_align(cui_Content, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(cui_Content, LV_FLEX_FLOW_ROW_REVERSE);
    lv_obj_set_flex_align(cui_Content, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x14A632), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(cui_Content, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(cui_Content, lv_color_hex(0x080C20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(cui_Content, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(cui_Content, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(cui_Content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(cui_Content, -9, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(cui_Content, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_Content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Notifi_Label;
    cui_Notifi_Label = lv_label_create(cui_Content);
    lv_obj_set_width(cui_Notifi_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Notifi_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Notifi_Label, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Notifi_Label, "Bluetooth has been connected!");
    lv_obj_set_style_text_color(cui_Notifi_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Notifi_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Notifi_Label, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Notifi_Image;
    cui_Notifi_Image = lv_img_create(cui_Content);
    lv_img_set_src(cui_Notifi_Image, &ui_img_ble_big_png);
    lv_obj_set_width(cui_Notifi_Image, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Notifi_Image, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Notifi_Image, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Notifi_Image, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Notifi_Image, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_NOTIFI_GROUP_NUM);
    children[UI_COMP_NOTIFI_GROUP_NOTIFI_GROUP] = cui_Notifi_Group;
    children[UI_COMP_NOTIFI_GROUP_CONTENT] = cui_Content;
    children[UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_LABEL] = cui_Notifi_Label;
    children[UI_COMP_NOTIFI_GROUP_CONTENT_NOTIFI_IMAGE] = cui_Notifi_Image;
    lv_obj_add_event_cb(cui_Notifi_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Notifi_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Notifi_Group;
}



// COMPONENT Settings Group

lv_obj_t * ui_Settings_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Settings_Group;
    cui_Settings_Group = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Settings_Group, lv_pct(100));
    lv_obj_set_height(cui_Settings_Group, lv_pct(100));
    lv_obj_set_align(cui_Settings_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Settings_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Settings_Group, lv_color_hex(0x0C0E18), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Settings_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Settings_Dark;
    cui_Settings_Dark = lv_obj_create(cui_Settings_Group);
    lv_obj_set_width(cui_Settings_Dark, lv_pct(100));
    lv_obj_set_height(cui_Settings_Dark, lv_pct(100));
    lv_obj_set_align(cui_Settings_Dark, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Settings_Dark, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(cui_Settings_Dark, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Settings_Dark, lv_color_hex(0x0C0E18), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Settings_Dark, 75, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Settings_Panel;
    cui_Settings_Panel = lv_obj_create(cui_Settings_Group);
    lv_obj_set_width(cui_Settings_Panel, 241);
    lv_obj_set_height(cui_Settings_Panel, lv_pct(100));
    lv_obj_set_align(cui_Settings_Panel, LV_ALIGN_LEFT_MID);
    lv_obj_set_flex_flow(cui_Settings_Panel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cui_Settings_Panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(cui_Settings_Panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(cui_Settings_Panel, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(cui_Settings_Panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(cui_Settings_Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(cui_Settings_Panel, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(cui_Settings_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(cui_Settings_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(cui_Settings_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Settings_Panel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Settings_Panel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Settings_Panel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Settings_Panel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Home_Panel;
    cui_Home_Panel = lv_obj_create(cui_Settings_Panel);
    lv_obj_set_height(cui_Home_Panel, 48);
    lv_obj_set_width(cui_Home_Panel, lv_pct(100));
    lv_obj_set_align(cui_Home_Panel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_Home_Panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Home_Panel, lv_color_hex(0x0D101D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Home_Panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Settings_Title;
    cui_Settings_Title = lv_label_create(cui_Home_Panel);
    lv_obj_set_width(cui_Settings_Title, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Settings_Title, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(cui_Settings_Title, "Settings");
    lv_obj_set_style_text_color(cui_Settings_Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Settings_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Settings_Title, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Settings_Content;
    cui_Settings_Content = lv_obj_create(cui_Settings_Panel);
    lv_obj_set_width(cui_Settings_Content, lv_pct(100));
    lv_obj_set_flex_grow(cui_Settings_Content, 1);
    lv_obj_set_align(cui_Settings_Content, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_Settings_Content, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cui_Settings_Content, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(cui_Settings_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Settings_Content, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Settings_Content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_List_Bluetooth;
    cui_List_Bluetooth = ui_List_comp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Bluetooth, 0);
    lv_obj_set_y(cui_List_Bluetooth, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Bluetooth, UI_COMP_LIST_COMP_SETTINGS_TITLE1), "Bluetooth");

    lv_obj_t * cui_List_Wifi;
    cui_List_Wifi = ui_List_comp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Wifi, 0);
    lv_obj_set_y(cui_List_Wifi, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Wifi, UI_COMP_LIST_COMP_SETTINGS_TITLE1), "Wifi");

    lv_obj_t * cui_List_Lights;
    cui_List_Lights = ui_List_comp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Lights, 0);
    lv_obj_set_y(cui_List_Lights, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Lights, UI_COMP_LIST_COMP_SETTINGS_TITLE1), "Lights");

    lv_obj_t * cui_List_Windows;
    cui_List_Windows = ui_List_comp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Windows, 0);
    lv_obj_set_y(cui_List_Windows, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Windows, UI_COMP_LIST_COMP_SETTINGS_TITLE1), "Windows");

    lv_obj_t * cui_List_Doors;
    cui_List_Doors = ui_List_comp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Doors, 0);
    lv_obj_set_y(cui_List_Doors, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Doors, UI_COMP_LIST_COMP_SETTINGS_TITLE1), "Doors");

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SETTINGS_GROUP_NUM);
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_GROUP] = cui_Settings_Group;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_DARK] = cui_Settings_Dark;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL] = cui_Settings_Panel;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL_HOME_PANEL] = cui_Home_Panel;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL_HOME_PANEL_SETTINGS_TITLE] = cui_Settings_Title;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL_SETTINGS_CONTENT] = cui_Settings_Content;
    children[UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH] = cui_List_Bluetooth;
    children[UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Bluetooth,
                                                                                        UI_COMP_LIST_COMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_BLUETOOTH_SWITCH] = ui_comp_get_child(cui_List_Bluetooth,
                                                                               UI_COMP_LIST_COMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_WIFI] = cui_List_Wifi;
    children[UI_COMP_SETTINGS_GROUP_LIST_WIFI_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Wifi,
                                                                                   UI_COMP_LIST_COMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_WIFI_SWITCH] = ui_comp_get_child(cui_List_Wifi, UI_COMP_LIST_COMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_LIGHTS] = cui_List_Lights;
    children[UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Lights,
                                                                                     UI_COMP_LIST_COMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_LIGHTS_SWITCH] = ui_comp_get_child(cui_List_Lights, UI_COMP_LIST_COMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_WINDOWS] = cui_List_Windows;
    children[UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Windows,
                                                                                      UI_COMP_LIST_COMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_WINDOWS_SWITCH] = ui_comp_get_child(cui_List_Windows, UI_COMP_LIST_COMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_DOORS] = cui_List_Doors;
    children[UI_COMP_SETTINGS_GROUP_LIST_DOORS_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Doors,
                                                                                    UI_COMP_LIST_COMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_DOORS_SWITCH] = ui_comp_get_child(cui_List_Doors, UI_COMP_LIST_COMP_SWITCH);
    lv_obj_add_event_cb(cui_Settings_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Settings_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Settings_Group;
}



// COMPONENT Switch

lv_obj_t * ui_Switch_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Switch;
    cui_Switch = lv_switch_create(comp_parent);
    lv_obj_set_width(cui_Switch, 40);
    lv_obj_set_height(cui_Switch, 20);
    lv_obj_set_align(cui_Switch, LV_ALIGN_RIGHT_MID);
    lv_obj_add_state(cui_Switch, LV_STATE_CHECKED);       /// States
    lv_obj_set_style_radius(cui_Switch, 500, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch, lv_color_hex(0x2C3A5F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Switch, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(cui_Switch, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch, lv_color_hex(0x0084FF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_Switch, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(cui_Switch, 50, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch, lv_color_hex(0xA7BCEF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Switch, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Switch, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_Switch, 255, LV_PART_KNOB | LV_STATE_CHECKED);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SWITCH_NUM);
    children[UI_COMP_SWITCH_SWITCH] = cui_Switch;
    lv_obj_add_event_cb(cui_Switch, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Switch, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Switch;
}



void ui_event_comp_Temperature_Group_Thermostat_Arc(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_Temperature_Group = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(comp_Temperature_Group[UI_COMP_TEMPERATURE_GROUP_CONTENT_THERMOSTAT_BG_TEMP_NUMBER], target, "",
                               "°");
    }
}

// COMPONENT Temperature Group

lv_obj_t * ui_Temperature_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Temperature_Group;
    cui_Temperature_Group = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Temperature_Group, 310);
    lv_obj_set_width(cui_Temperature_Group, lv_pct(33));
    lv_obj_set_align(cui_Temperature_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Temperature_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Temperature_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Temperature_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Temperature_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Temperature_Group);
    lv_obj_set_height(cui_Content, 310);
    lv_obj_set_width(cui_Content, lv_pct(100));
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Temp_Title;
    cui_Temp_Title = lv_label_create(cui_Content);
    lv_obj_set_width(cui_Temp_Title, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Temp_Title, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Temp_Title, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_Temp_Title, "Temperature");
    lv_obj_set_style_text_color(cui_Temp_Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Temp_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Temp_Title, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Thermostat_BG;
    cui_Thermostat_BG = lv_img_create(cui_Content);
    lv_img_set_src(cui_Thermostat_BG, &ui_img_thermostat_bg_png);
    lv_obj_set_width(cui_Thermostat_BG, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Thermostat_BG, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Thermostat_BG, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Thermostat_BG, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Thermostat_BG, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Temp_Number;
    cui_Temp_Number = lv_label_create(cui_Thermostat_BG);
    lv_obj_set_width(cui_Temp_Number, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Temp_Number, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Temp_Number, 3);
    lv_obj_set_y(cui_Temp_Number, -10);
    lv_obj_set_align(cui_Temp_Number, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Temp_Number, "23°");
    lv_obj_set_style_text_color(cui_Temp_Number, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Temp_Number, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Temp_Number, &ui_font_BigNumber, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_City2;
    cui_City2 = lv_label_create(cui_Thermostat_BG);
    lv_obj_set_width(cui_City2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_City2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_City2, 0);
    lv_obj_set_y(cui_City2, 30);
    lv_obj_set_align(cui_City2, LV_ALIGN_CENTER);
    lv_label_set_text(cui_City2, "Heat set to");
    lv_obj_set_style_text_color(cui_City2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_City2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_City2, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Thermostat_Arc;
    cui_Thermostat_Arc = lv_arc_create(cui_Thermostat_BG);
    lv_obj_set_width(cui_Thermostat_Arc, 180);
    lv_obj_set_height(cui_Thermostat_Arc, 180);
    lv_obj_set_align(cui_Thermostat_Arc, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Thermostat_Arc, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_arc_set_range(cui_Thermostat_Arc, 15, 30);
    lv_arc_set_value(cui_Thermostat_Arc, 23);
    lv_arc_set_bg_angles(cui_Thermostat_Arc, 180, 0);
    lv_obj_set_style_arc_color(cui_Thermostat_Arc, lv_color_hex(0x2C3A5F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(cui_Thermostat_Arc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(cui_Thermostat_Arc, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(cui_Thermostat_Arc, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_width(cui_Thermostat_Arc, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(cui_Thermostat_Arc, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_img_src(cui_Thermostat_Arc, &ui_img_gradient_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(cui_Thermostat_Arc, 50, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Thermostat_Arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Thermostat_Arc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(cui_Thermostat_Arc, lv_color_hex(0x09112C), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(cui_Thermostat_Arc, 200, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(cui_Thermostat_Arc, 9, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(cui_Thermostat_Arc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(cui_Thermostat_Arc, -5, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(cui_Thermostat_Arc, 5, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_t * cui_Degree_Min;
    cui_Degree_Min = lv_label_create(cui_Thermostat_BG);
    lv_obj_set_width(cui_Degree_Min, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Degree_Min, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Degree_Min, 6);
    lv_obj_set_y(cui_Degree_Min, 16);
    lv_obj_set_align(cui_Degree_Min, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Degree_Min, "15°");
    lv_obj_set_style_text_color(cui_Degree_Min, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Degree_Min, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Degree_Min, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Degree_MAx;
    cui_Degree_MAx = lv_label_create(cui_Thermostat_BG);
    lv_obj_set_width(cui_Degree_MAx, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Degree_MAx, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Degree_MAx, -1);
    lv_obj_set_y(cui_Degree_MAx, 16);
    lv_obj_set_align(cui_Degree_MAx, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(cui_Degree_MAx, "30°");
    lv_obj_set_style_text_color(cui_Degree_MAx, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Degree_MAx, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Degree_MAx, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content_Group_1;
    cui_Content_Group_1 = lv_obj_create(cui_Content);
    lv_obj_set_height(cui_Content_Group_1, 50);
    lv_obj_set_width(cui_Content_Group_1, lv_pct(100));
    lv_obj_set_align(cui_Content_Group_1, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(cui_Content_Group_1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Content_Group_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content_Group_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Title_Number_Group1;
    cui_Title_Number_Group1 = ui_Title_Number_Group_create(cui_Content_Group_1);
    lv_obj_set_x(cui_Title_Number_Group1, 0);
    lv_obj_set_y(cui_Title_Number_Group1, 0);
    lv_obj_set_align(cui_Title_Number_Group1, LV_ALIGN_LEFT_MID);

    lv_obj_t * cui_Title_Number_Group2;
    cui_Title_Number_Group2 = ui_Title_Number_Group_create(cui_Content_Group_1);
    lv_obj_set_x(cui_Title_Number_Group2, 0);
    lv_obj_set_y(cui_Title_Number_Group2, 0);
    lv_obj_set_align(cui_Title_Number_Group2, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_border_color(cui_Title_Number_Group2, lv_color_hex(0x616688), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_Title_Number_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group2, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "HUMIDITY");

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group2, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2), "84%");

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TEMPERATURE_GROUP_NUM);
    children[UI_COMP_TEMPERATURE_GROUP_TEMPERATURE_GROUP] = cui_Temperature_Group;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT] = cui_Content;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT_TEMP_TITLE] = cui_Temp_Title;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT_THERMOSTAT_BG] = cui_Thermostat_BG;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT_THERMOSTAT_BG_TEMP_NUMBER] = cui_Temp_Number;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT_THERMOSTAT_BG_CITY2] = cui_City2;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT_THERMOSTAT_BG_THERMOSTAT_ARC] = cui_Thermostat_Arc;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT_THERMOSTAT_BG_DEGREE_MIN] = cui_Degree_Min;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT_THERMOSTAT_BG_DEGREE_MAX] = cui_Degree_MAx;
    children[UI_COMP_TEMPERATURE_GROUP_CONTENT_CONTENT_GROUP_1] = cui_Content_Group_1;
    children[UI_COMP_TEMPERATURE_GROUP_TITLE_NUMBER_GROUP1] = cui_Title_Number_Group1;
    children[UI_COMP_TEMPERATURE_GROUP_TITLE_NUMBER_GROUP1_TNG_TITLE2] = ui_comp_get_child(cui_Title_Number_Group1,
                                                                                           UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2);
    children[UI_COMP_TEMPERATURE_GROUP_TITLE_NUMBER_GROUP1_TNG_NUMBER2] = ui_comp_get_child(cui_Title_Number_Group1,
                                                                                            UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2);
    children[UI_COMP_TEMPERATURE_GROUP_TITLE_NUMBER_GROUP2] = cui_Title_Number_Group2;
    children[UI_COMP_TEMPERATURE_GROUP_TITLE_NUMBER_GROUP2_TNG_TITLE2] = ui_comp_get_child(cui_Title_Number_Group2,
                                                                                           UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2);
    children[UI_COMP_TEMPERATURE_GROUP_TITLE_NUMBER_GROUP2_TNG_NUMBER2] = ui_comp_get_child(cui_Title_Number_Group2,
                                                                                            UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2);
    lv_obj_add_event_cb(cui_Temperature_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Temperature_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    lv_obj_add_event_cb(cui_Thermostat_Arc, ui_event_comp_Temperature_Group_Thermostat_Arc, LV_EVENT_ALL, children);
    return cui_Temperature_Group;
}



// COMPONENT Time Group

lv_obj_t * ui_Time_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Time_Group;
    cui_Time_Group = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Time_Group, 310);
    lv_obj_set_width(cui_Time_Group, lv_pct(33));
    lv_obj_set_align(cui_Time_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Time_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Time_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Time_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Time_Group);
    lv_obj_set_height(cui_Content, 310);
    lv_obj_set_width(cui_Content, lv_pct(100));
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Time;
    cui_Time = lv_label_create(cui_Content);
    lv_obj_set_width(cui_Time, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Time, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Time, 0);
    lv_obj_set_y(cui_Time, -6);
    lv_obj_set_align(cui_Time, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_Time, "20:14");
    lv_obj_set_style_text_color(cui_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Time, &ui_font_BigNumber, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_City;
    cui_City = lv_label_create(cui_Content);
    lv_obj_set_width(cui_City, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_City, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_City, 0);
    lv_obj_set_y(cui_City, 60);
    lv_obj_set_align(cui_City, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_City, "New York, USA");
    lv_obj_set_style_text_color(cui_City, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_City, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_City, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Clock_Group;
    cui_Clock_Group = lv_obj_create(cui_Content);
    lv_obj_set_width(cui_Clock_Group, 210);
    lv_obj_set_height(cui_Clock_Group, 200);
    lv_obj_set_x(cui_Clock_Group, 0);
    lv_obj_set_y(cui_Clock_Group, 10);
    lv_obj_set_align(cui_Clock_Group, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(cui_Clock_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Clock_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Clock_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Clock_BG;
    cui_Clock_BG = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_BG, &ui_img_clock_bg_png);
    lv_obj_set_width(cui_Clock_BG, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_BG, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Clock_BG, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_BG, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_BG, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Clock_Hour_Shadow;
    cui_Clock_Hour_Shadow = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_Hour_Shadow, &ui_img_clock_hour_shadow_png);
    lv_obj_set_width(cui_Clock_Hour_Shadow, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_Hour_Shadow, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Clock_Hour_Shadow, -9);
    lv_obj_set_y(cui_Clock_Hour_Shadow, 6);
    lv_obj_set_align(cui_Clock_Hour_Shadow, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_Hour_Shadow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_Hour_Shadow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(cui_Clock_Hour_Shadow, 2250);

    lv_obj_t * cui_Clock_Hour;
    cui_Clock_Hour = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_Hour, &ui_img_clock_hour_png);
    lv_obj_set_width(cui_Clock_Hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_Hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Clock_Hour, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_Hour, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_Hour, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(cui_Clock_Hour, 2250);

    lv_obj_t * cui_Clock_Min_Shadow;
    cui_Clock_Min_Shadow = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_Min_Shadow, &ui_img_clock_min_shadow_png);
    lv_obj_set_width(cui_Clock_Min_Shadow, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_Min_Shadow, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Clock_Min_Shadow, -9);
    lv_obj_set_y(cui_Clock_Min_Shadow, 6);
    lv_obj_set_align(cui_Clock_Min_Shadow, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_Min_Shadow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_Min_Shadow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(cui_Clock_Min_Shadow, 800);

    lv_obj_t * cui_Clock_Min;
    cui_Clock_Min = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_Min, &ui_img_clock_min_png);
    lv_obj_set_width(cui_Clock_Min, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_Min, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Clock_Min, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_Min, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_Min, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(cui_Clock_Min, 800);

    lv_obj_t * cui_Clock_Sec_Shadow;
    cui_Clock_Sec_Shadow = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_Sec_Shadow, &ui_img_clock_sec_shadow_png);
    lv_obj_set_width(cui_Clock_Sec_Shadow, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_Sec_Shadow, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Clock_Sec_Shadow, -9);
    lv_obj_set_y(cui_Clock_Sec_Shadow, 6);
    lv_obj_set_align(cui_Clock_Sec_Shadow, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_Sec_Shadow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_Sec_Shadow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(cui_Clock_Sec_Shadow, 2900);

    lv_obj_t * cui_Clock_Sec;
    cui_Clock_Sec = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_Sec, &ui_img_clock_sec_png);
    lv_obj_set_width(cui_Clock_Sec, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_Sec, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Clock_Sec, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_Sec, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_Sec, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(cui_Clock_Sec, 2900);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TIME_GROUP_NUM);
    children[UI_COMP_TIME_GROUP_TIME_GROUP] = cui_Time_Group;
    children[UI_COMP_TIME_GROUP_CONTENT] = cui_Content;
    children[UI_COMP_TIME_GROUP_CONTENT_TIME] = cui_Time;
    children[UI_COMP_TIME_GROUP_CONTENT_CITY] = cui_City;
    children[UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP] = cui_Clock_Group;
    children[UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_BG] = cui_Clock_BG;
    children[UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_HOUR_SHADOW] = cui_Clock_Hour_Shadow;
    children[UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_HOUR] = cui_Clock_Hour;
    children[UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_MIN_SHADOW] = cui_Clock_Min_Shadow;
    children[UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_MIN] = cui_Clock_Min;
    children[UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_SEC_SHADOW] = cui_Clock_Sec_Shadow;
    children[UI_COMP_TIME_GROUP_CONTENT_CLOCK_GROUP_CLOCK_SEC] = cui_Clock_Sec;
    lv_obj_add_event_cb(cui_Time_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Time_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Time_Group;
}



// COMPONENT Title Number Group

lv_obj_t * ui_Title_Number_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Title_Number_Group;
    cui_Title_Number_Group = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Title_Number_Group, 50);
    lv_obj_set_width(cui_Title_Number_Group, lv_pct(50));
    lv_obj_set_align(cui_Title_Number_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Title_Number_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Title_Number_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Title_Number_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_Title_Number_Group, lv_color_hex(0x41455D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_Title_Number_Group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_Title_Number_Group, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(cui_Title_Number_Group, LV_BORDER_SIDE_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_TNG_Title2;
    cui_TNG_Title2 = lv_label_create(cui_Title_Number_Group);
    lv_obj_set_width(cui_TNG_Title2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_TNG_Title2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_TNG_Title2, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_TNG_Title2, "CURRENT");
    lv_obj_set_style_text_color(cui_TNG_Title2, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_TNG_Title2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_TNG_Title2, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_TNG_Number2;
    cui_TNG_Number2 = lv_label_create(cui_Title_Number_Group);
    lv_obj_set_width(cui_TNG_Number2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_TNG_Number2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_TNG_Number2, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(cui_TNG_Number2, "18°");
    lv_obj_set_style_text_color(cui_TNG_Number2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_TNG_Number2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_TNG_Number2, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TITLE_NUMBER_GROUP_NUM);
    children[UI_COMP_TITLE_NUMBER_GROUP_TITLE_NUMBER_GROUP] = cui_Title_Number_Group;
    children[UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2] = cui_TNG_Title2;
    children[UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2] = cui_TNG_Number2;
    lv_obj_add_event_cb(cui_Title_Number_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Title_Number_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Title_Number_Group;
}



// COMPONENT WeatheGroupList

lv_obj_t * ui_WeatheGroupList_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_WeatheGroupList;
    cui_WeatheGroupList = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_WeatheGroupList, lv_pct(100));
    lv_obj_set_flex_grow(cui_WeatheGroupList, 1);
    lv_obj_set_align(cui_WeatheGroupList, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(cui_WeatheGroupList, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_WeatheGroupList, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_WeatheGroupList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_WeatheGroupList, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_WeatheGroupList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_WeatheGroupList, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_WeatheGroupList, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_WeatheGroupList, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_WeatheGroupList, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_WeatheGroupList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_WeatheGroupList, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Weather_City_Degree;
    cui_Weather_City_Degree = lv_obj_create(cui_WeatheGroupList);
    lv_obj_set_width(cui_Weather_City_Degree, 250);
    lv_obj_set_height(cui_Weather_City_Degree, lv_pct(100));
    lv_obj_set_align(cui_Weather_City_Degree, LV_ALIGN_LEFT_MID);
    lv_obj_set_flex_flow(cui_Weather_City_Degree, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Weather_City_Degree, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Weather_City_Degree, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Weather_City_Degree, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Weather_City_Degree, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Weather_City_Status;
    cui_Weather_City_Status = lv_obj_create(cui_Weather_City_Degree);
    lv_obj_set_height(cui_Weather_City_Status, 50);
    lv_obj_set_width(cui_Weather_City_Status, lv_pct(55));
    lv_obj_set_align(cui_Weather_City_Status, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Weather_City_Status, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Weather_City_Status, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Weather_City_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Weather_City;
    cui_Weather_City = lv_label_create(cui_Weather_City_Status);
    lv_obj_set_width(cui_Weather_City, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Weather_City, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(cui_Weather_City, "Panama City");
    lv_obj_set_style_text_color(cui_Weather_City, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Weather_City, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Weather_City, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Weather_Status;
    cui_Weather_Status = lv_label_create(cui_Weather_City_Status);
    lv_obj_set_width(cui_Weather_Status, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Weather_Status, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Weather_Status, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(cui_Weather_Status, "Partly Cloudy");
    lv_obj_set_style_text_color(cui_Weather_Status, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Weather_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Weather_Status, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Degree_Grup;
    cui_Degree_Grup = lv_obj_create(cui_Weather_City_Degree);
    lv_obj_set_width(cui_Degree_Grup, 100);
    lv_obj_set_height(cui_Degree_Grup, 50);
    lv_obj_set_align(cui_Degree_Grup, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Degree_Grup, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Degree_Grup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Degree_Grup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_Degree_Grup, lv_color_hex(0x41455D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_Degree_Grup, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_Degree_Grup, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(cui_Degree_Grup, LV_BORDER_SIDE_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Degree_Grup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Degree_Grup, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Degree_Grup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Degree_Grup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Degree1;
    cui_Degree1 = lv_label_create(cui_Degree_Grup);
    lv_obj_set_width(cui_Degree1, LV_SIZE_CONTENT);   /// 38
    lv_obj_set_height(cui_Degree1, LV_SIZE_CONTENT);    /// 68
    lv_obj_set_align(cui_Degree1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(cui_Degree1, "24°");
    lv_obj_set_style_text_color(cui_Degree1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Degree1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(cui_Degree1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Degree1, &ui_font_BigNumber, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Panel5;
    cui_Panel5 = lv_obj_create(cui_WeatheGroupList);
    lv_obj_set_height(cui_Panel5, lv_pct(100));
    lv_obj_set_flex_grow(cui_Panel5, 1);
    lv_obj_set_align(cui_Panel5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_Panel5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Panel5, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Panel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Weather_Icon_Group;
    cui_Weather_Icon_Group = ui_Weather_Icon_Group_create(cui_Panel5);
    lv_obj_set_x(cui_Weather_Icon_Group, 0);
    lv_obj_set_y(cui_Weather_Icon_Group, 0);

    lv_img_set_src(ui_comp_get_child(cui_Weather_Icon_Group, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1),
                   &ui_img_weather_cloud_fog_png);

    lv_obj_t * cui_Weather_Icon_Group1;
    cui_Weather_Icon_Group1 = ui_Weather_Icon_Group_create(cui_Panel5);
    lv_obj_set_x(cui_Weather_Icon_Group1, 0);
    lv_obj_set_y(cui_Weather_Icon_Group1, 0);

    lv_label_set_text(ui_comp_get_child(cui_Weather_Icon_Group1, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1), "22:00");

    lv_img_set_src(ui_comp_get_child(cui_Weather_Icon_Group1, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1),
                   &ui_img_weather_cloud_png);

    lv_label_set_text(ui_comp_get_child(cui_Weather_Icon_Group1, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE), "25°");

    lv_obj_t * cui_Weather_Icon_Group2;
    cui_Weather_Icon_Group2 = ui_Weather_Icon_Group_create(cui_Panel5);
    lv_obj_set_x(cui_Weather_Icon_Group2, 0);
    lv_obj_set_y(cui_Weather_Icon_Group2, 0);

    lv_label_set_text(ui_comp_get_child(cui_Weather_Icon_Group2, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1), "23:00");

    lv_img_set_src(ui_comp_get_child(cui_Weather_Icon_Group2, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1),
                   &ui_img_weather_cloud_png);

    lv_label_set_text(ui_comp_get_child(cui_Weather_Icon_Group2, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE), "22°");

    lv_obj_t * cui_Weather_Icon_Group3;
    cui_Weather_Icon_Group3 = ui_Weather_Icon_Group_create(cui_Panel5);
    lv_obj_set_x(cui_Weather_Icon_Group3, 0);
    lv_obj_set_y(cui_Weather_Icon_Group3, 0);

    lv_label_set_text(ui_comp_get_child(cui_Weather_Icon_Group3, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1), "00:00");

    lv_img_set_src(ui_comp_get_child(cui_Weather_Icon_Group3, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1),
                   &ui_img_weather_cloud_png);

    lv_label_set_text(ui_comp_get_child(cui_Weather_Icon_Group3, UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE), "20°");

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_WEATHEGROUPLIST_NUM);
    children[UI_COMP_WEATHEGROUPLIST_WEATHEGROUPLIST] = cui_WeatheGroupList;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE] = cui_Weather_City_Degree;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_WEATHER_CITY_STATUS] = cui_Weather_City_Status;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_WEATHER_CITY_STATUS_WEATHER_CITY] = cui_Weather_City;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_WEATHER_CITY_STATUS_WEATHER_STATUS] = cui_Weather_Status;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_DEGREE_GRUP] = cui_Degree_Grup;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_CITY_DEGREE_DEGREE_GRUP_DEGREE1] = cui_Degree1;
    children[UI_COMP_WEATHEGROUPLIST_PANEL5] = cui_Panel5;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP] = cui_Weather_Icon_Group;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1] = ui_comp_get_child(cui_Weather_Icon_Group,
                                                                                                  UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP_WEATHER_ICON_1] = ui_comp_get_child(cui_Weather_Icon_Group,
                                                                                            UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE] = ui_comp_get_child(cui_Weather_Icon_Group,
                                                                                                 UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP1] = cui_Weather_Icon_Group1;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP1_WEATHER_ICON_DEGREE1] = ui_comp_get_child(cui_Weather_Icon_Group1,
                                                                                                   UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP1_WEATHER_ICON_1] = ui_comp_get_child(cui_Weather_Icon_Group1,
                                                                                             UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP1_WEATHER_ICON_DEGREE] = ui_comp_get_child(cui_Weather_Icon_Group1,
                                                                                                  UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP2] = cui_Weather_Icon_Group2;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP2_WEATHER_ICON_DEGREE1] = ui_comp_get_child(cui_Weather_Icon_Group2,
                                                                                                   UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP2_WEATHER_ICON_1] = ui_comp_get_child(cui_Weather_Icon_Group2,
                                                                                             UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP2_WEATHER_ICON_DEGREE] = ui_comp_get_child(cui_Weather_Icon_Group2,
                                                                                                  UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP3] = cui_Weather_Icon_Group3;
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP3_WEATHER_ICON_DEGREE1] = ui_comp_get_child(cui_Weather_Icon_Group3,
                                                                                                   UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP3_WEATHER_ICON_1] = ui_comp_get_child(cui_Weather_Icon_Group3,
                                                                                             UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1);
    children[UI_COMP_WEATHEGROUPLIST_WEATHER_ICON_GROUP3_WEATHER_ICON_DEGREE] = ui_comp_get_child(cui_Weather_Icon_Group3,
                                                                                                  UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE);
    lv_obj_add_event_cb(cui_WeatheGroupList, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_WeatheGroupList, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_WeatheGroupList;
}



// COMPONENT Weather Group

lv_obj_t * ui_Weather_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Weather_Group;
    cui_Weather_Group = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Weather_Group, 310);
    lv_obj_set_width(cui_Weather_Group, lv_pct(33));
    lv_obj_set_align(cui_Weather_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Weather_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Weather_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Weather_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Weather_Group);
    lv_obj_set_height(cui_Content, 310);
    lv_obj_set_width(cui_Content, lv_pct(100));
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Outsite_Temp;
    cui_Outsite_Temp = lv_label_create(cui_Content);
    lv_obj_set_width(cui_Outsite_Temp, lv_pct(50));
    lv_obj_set_height(cui_Outsite_Temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Outsite_Temp, 0);
    lv_obj_set_y(cui_Outsite_Temp, -6);
    lv_label_set_long_mode(cui_Outsite_Temp, LV_LABEL_LONG_CLIP);
    lv_label_set_text(cui_Outsite_Temp, "18°");
    lv_obj_set_style_text_color(cui_Outsite_Temp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Outsite_Temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(cui_Outsite_Temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Outsite_Temp, &ui_font_BigNumber, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Weather_Rain_Group;
    cui_Weather_Rain_Group = lv_obj_create(cui_Content);
    lv_obj_set_width(cui_Weather_Rain_Group, 175);
    lv_obj_set_height(cui_Weather_Rain_Group, 137);
    lv_obj_set_x(cui_Weather_Rain_Group, 0);
    lv_obj_set_y(cui_Weather_Rain_Group, -10);
    lv_obj_set_align(cui_Weather_Rain_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Weather_Rain_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Weather_Rain_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Weather_Rain_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Rain;
    cui_Rain = lv_img_create(cui_Weather_Rain_Group);
    lv_img_set_src(cui_Rain, &ui_img_rain_png);
    lv_obj_set_height(cui_Rain, 83);
    lv_obj_set_width(cui_Rain, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(cui_Rain, 10);
    lv_obj_set_y(cui_Rain, 29);
    lv_obj_set_align(cui_Rain, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Rain, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Rain, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(cui_Rain, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Rain1;
    cui_Rain1 = lv_img_create(cui_Weather_Rain_Group);
    lv_img_set_src(cui_Rain1, &ui_img_rain_png);
    lv_obj_set_height(cui_Rain1, 83);
    lv_obj_set_width(cui_Rain1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(cui_Rain1, 5);
    lv_obj_set_y(cui_Rain1, 19);
    lv_obj_set_align(cui_Rain1, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Rain1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Rain1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Cloud;
    cui_Cloud = lv_img_create(cui_Weather_Rain_Group);
    lv_img_set_src(cui_Cloud, &ui_img_weather_icon_png);
    lv_obj_set_width(cui_Cloud, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Cloud, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Cloud, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Cloud, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Cloud, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Title_Number_Group3;
    cui_Title_Number_Group3 = ui_Title_Number_Group_create(cui_Content);
    lv_obj_set_x(cui_Title_Number_Group3, 0);
    lv_obj_set_y(cui_Title_Number_Group3, 0);
    lv_obj_set_align(cui_Title_Number_Group3, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_style_border_side(cui_Title_Number_Group3, LV_BORDER_SIDE_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group3, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "MAX");

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group3, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2), "26°");
    lv_obj_set_style_text_color(ui_comp_get_child(cui_Title_Number_Group3, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2),
                                lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_comp_get_child(cui_Title_Number_Group3, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2), 255,
                              LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content_Group_2;
    cui_Content_Group_2 = lv_obj_create(cui_Content);
    lv_obj_set_height(cui_Content_Group_2, 50);
    lv_obj_set_width(cui_Content_Group_2, lv_pct(100));
    lv_obj_set_align(cui_Content_Group_2, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(cui_Content_Group_2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Content_Group_2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content_Group_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Title_Number_Group4;
    cui_Title_Number_Group4 = ui_Title_Number_Group_create(cui_Content_Group_2);
    lv_obj_set_height(cui_Title_Number_Group4, 50);
    lv_obj_set_width(cui_Title_Number_Group4, lv_pct(33));
    lv_obj_set_x(cui_Title_Number_Group4, 0);
    lv_obj_set_y(cui_Title_Number_Group4, 0);
    lv_obj_set_align(cui_Title_Number_Group4, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group4, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "FRI");

    lv_obj_t * cui_Title_Number_Group5;
    cui_Title_Number_Group5 = ui_Title_Number_Group_create(cui_Content_Group_2);
    lv_obj_set_height(cui_Title_Number_Group5, 50);
    lv_obj_set_width(cui_Title_Number_Group5, lv_pct(33));
    lv_obj_set_x(cui_Title_Number_Group5, 0);
    lv_obj_set_y(cui_Title_Number_Group5, 0);
    lv_obj_set_align(cui_Title_Number_Group5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group5, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "SAT");

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group5, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2), "24°");

    lv_obj_t * cui_Title_Number_Group6;
    cui_Title_Number_Group6 = ui_Title_Number_Group_create(cui_Content_Group_2);
    lv_obj_set_height(cui_Title_Number_Group6, 50);
    lv_obj_set_width(cui_Title_Number_Group6, lv_pct(33));
    lv_obj_set_x(cui_Title_Number_Group6, 0);
    lv_obj_set_y(cui_Title_Number_Group6, 0);
    lv_obj_set_align(cui_Title_Number_Group6, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_border_color(cui_Title_Number_Group6, lv_color_hex(0x41455D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_Title_Number_Group6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group6, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "SUN");

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group6, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2), "22°");

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_WEATHER_GROUP_NUM);
    children[UI_COMP_WEATHER_GROUP_WEATHER_GROUP] = cui_Weather_Group;
    children[UI_COMP_WEATHER_GROUP_CONTENT] = cui_Content;
    children[UI_COMP_WEATHER_GROUP_CONTENT_OUTSITE_TEMP] = cui_Outsite_Temp;
    children[UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP] = cui_Weather_Rain_Group;
    children[UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_RAIN] = cui_Rain;
    children[UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_RAIN1] = cui_Rain1;
    children[UI_COMP_WEATHER_GROUP_CONTENT_WEATHER_RAIN_GROUP_CLOUD] = cui_Cloud;
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP3] = cui_Title_Number_Group3;
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP3_TNG_TITLE2] = ui_comp_get_child(cui_Title_Number_Group3,
                                                                                       UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2);
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP3_TNG_NUMBER2] = ui_comp_get_child(cui_Title_Number_Group3,
                                                                                        UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2);
    children[UI_COMP_WEATHER_GROUP_CONTENT_CONTENT_GROUP_2] = cui_Content_Group_2;
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP4] = cui_Title_Number_Group4;
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP4_TNG_TITLE2] = ui_comp_get_child(cui_Title_Number_Group4,
                                                                                       UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2);
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP4_TNG_NUMBER2] = ui_comp_get_child(cui_Title_Number_Group4,
                                                                                        UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2);
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP5] = cui_Title_Number_Group5;
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP5_TNG_TITLE2] = ui_comp_get_child(cui_Title_Number_Group5,
                                                                                       UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2);
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP5_TNG_NUMBER2] = ui_comp_get_child(cui_Title_Number_Group5,
                                                                                        UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2);
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP6] = cui_Title_Number_Group6;
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP6_TNG_TITLE2] = ui_comp_get_child(cui_Title_Number_Group6,
                                                                                       UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2);
    children[UI_COMP_WEATHER_GROUP_TITLE_NUMBER_GROUP6_TNG_NUMBER2] = ui_comp_get_child(cui_Title_Number_Group6,
                                                                                        UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2);
    lv_obj_add_event_cb(cui_Weather_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Weather_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Weather_Group;
}



// COMPONENT Weather_Icon_Group

lv_obj_t * ui_Weather_Icon_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Weather_Icon_Group;
    cui_Weather_Icon_Group = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Weather_Icon_Group, 50);
    lv_obj_set_height(cui_Weather_Icon_Group, lv_pct(100));
    lv_obj_set_align(cui_Weather_Icon_Group, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_Weather_Icon_Group, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cui_Weather_Icon_Group, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Weather_Icon_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Weather_Icon_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Weather_Icon_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_Weather_Icon_Group, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_Weather_Icon_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Weather_Icon_Degree1;
    cui_Weather_Icon_Degree1 = lv_label_create(cui_Weather_Icon_Group);
    lv_obj_set_width(cui_Weather_Icon_Degree1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Weather_Icon_Degree1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Weather_Icon_Degree1, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Weather_Icon_Degree1, "21:00");
    lv_obj_set_style_text_color(cui_Weather_Icon_Degree1, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Weather_Icon_Degree1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Weather_Icon_Degree1, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Weather_Icon_1;
    cui_Weather_Icon_1 = lv_img_create(cui_Weather_Icon_Group);
    lv_img_set_src(cui_Weather_Icon_1, &ui_img_weather_png);
    lv_obj_set_width(cui_Weather_Icon_1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Weather_Icon_1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Weather_Icon_1, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Weather_Icon_1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Weather_Icon_1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Weather_Icon_Degree;
    cui_Weather_Icon_Degree = lv_label_create(cui_Weather_Icon_Group);
    lv_obj_set_width(cui_Weather_Icon_Degree, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Weather_Icon_Degree, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Weather_Icon_Degree, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Weather_Icon_Degree, "26°");
    lv_obj_set_style_text_color(cui_Weather_Icon_Degree, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Weather_Icon_Degree, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Weather_Icon_Degree, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_WEATHER_ICON_GROUP_NUM);
    children[UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_GROUP] = cui_Weather_Icon_Group;
    children[UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE1] = cui_Weather_Icon_Degree1;
    children[UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_1] = cui_Weather_Icon_1;
    children[UI_COMP_WEATHER_ICON_GROUP_WEATHER_ICON_DEGREE] = cui_Weather_Icon_Degree;
    lv_obj_add_event_cb(cui_Weather_Icon_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Weather_Icon_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Weather_Icon_Group;
}



// COMPONENT World_Time_List

lv_obj_t * ui_World_Time_List_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_World_Time_List;
    cui_World_Time_List = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_World_Time_List, 59);
    lv_obj_set_width(cui_World_Time_List, lv_pct(100));
    lv_obj_set_align(cui_World_Time_List, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_World_Time_List, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_World_Time_List, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_World_Time_List, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_World_Time_List, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_World_Time_List, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_World_Time_List, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_World_Time_List, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_World_Time;
    cui_World_Time = lv_label_create(cui_World_Time_List);
    lv_obj_set_width(cui_World_Time, lv_pct(50));
    lv_obj_set_height(cui_World_Time, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_World_Time, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(cui_World_Time, "20:14");
    lv_obj_set_style_text_color(cui_World_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_World_Time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(cui_World_Time, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_World_Time, &ui_font_BigNumber, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_World_Time, lv_color_hex(0x41455D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_World_Time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_World_Time, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(cui_World_Time, LV_BORDER_SIDE_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Time_Delay;
    cui_Time_Delay = lv_label_create(cui_World_Time_List);
    lv_obj_set_width(cui_Time_Delay, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Time_Delay, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(cui_Time_Delay, "Today, -6 hours");
    lv_obj_set_style_text_color(cui_Time_Delay, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Time_Delay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Time_Delay, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_World_Time_City;
    cui_World_Time_City = lv_label_create(cui_World_Time_List);
    lv_obj_set_width(cui_World_Time_City, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_World_Time_City, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_World_Time_City, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(cui_World_Time_City, "Panama City");
    lv_obj_set_style_text_color(cui_World_Time_City, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_World_Time_City, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_World_Time_City, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_WORLD_TIME_LIST_NUM);
    children[UI_COMP_WORLD_TIME_LIST_WORLD_TIME_LIST] = cui_World_Time_List;
    children[UI_COMP_WORLD_TIME_LIST_WORLD_TIME] = cui_World_Time;
    children[UI_COMP_WORLD_TIME_LIST_TIME_DELAY] = cui_Time_Delay;
    children[UI_COMP_WORLD_TIME_LIST_WORLD_TIME_CITY] = cui_World_Time_City;
    lv_obj_add_event_cb(cui_World_Time_List, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_World_Time_List, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_World_Time_List;
}


// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.0
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


void ui_event_comp_Camera_Group_Home_Switch1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_Camera_Group = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        _ui_state_modify(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_IMAGE], LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
        _ui_label_set_property(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER_LIVE_TITLE],
                               _UI_LABEL_PROPERTY_TEXT, "Offline");
        _ui_flag_modify(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER_RED_CIRCLE], LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_ADD);
        Up_Animation(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_IMAGE_CAMERE_OFF], 0);
        _ui_flag_modify(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_IMAGE_CAMERE_OFF], LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_REMOVE);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        _ui_state_modify(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_IMAGE], LV_STATE_DISABLED,
                         _UI_MODIFY_STATE_REMOVE);
        _ui_flag_modify(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER_RED_CIRCLE], LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_IMAGE_CAMERE_OFF], LV_OBJ_FLAG_HIDDEN,
                        _UI_MODIFY_FLAG_ADD);
        _ui_label_set_property(comp_Camera_Group[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER_LIVE_TITLE],
                               _UI_LABEL_PROPERTY_TEXT, "Live");
    }
}

// COMPONENT Camera Group

lv_obj_t * ui_Camera_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Camera_Group;
    cui_Camera_Group = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Camera_Group, 134);
    lv_obj_set_height(cui_Camera_Group, 178);
    lv_obj_set_align(cui_Camera_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Camera_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Camera_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Camera_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Camera_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Camera_Group);
    lv_obj_set_width(cui_Content, 126);
    lv_obj_set_height(cui_Content, 178);
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Camera_Header;
    cui_Camera_Header = lv_obj_create(cui_Content);
    lv_obj_set_height(cui_Camera_Header, 18);
    lv_obj_set_width(cui_Camera_Header, lv_pct(100));
    lv_obj_set_align(cui_Camera_Header, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(cui_Camera_Header, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Camera_Header, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Camera_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Camera_Title;
    cui_Camera_Title = lv_label_create(cui_Camera_Header);
    lv_obj_set_width(cui_Camera_Title, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Camera_Title, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Camera_Title, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Camera_Title, "Camera");
    lv_obj_set_style_text_color(cui_Camera_Title, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Camera_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Camera_Title, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Home_Switch1;
    cui_Home_Switch1 = lv_switch_create(cui_Camera_Header);
    lv_obj_set_width(cui_Home_Switch1, 30);
    lv_obj_set_height(cui_Home_Switch1, 15);
    lv_obj_set_x(cui_Home_Switch1, -2);
    lv_obj_set_y(cui_Home_Switch1, 0);
    lv_obj_set_align(cui_Home_Switch1, LV_ALIGN_RIGHT_MID);
    lv_obj_add_state(cui_Home_Switch1, LV_STATE_CHECKED);       /// States
    lv_obj_set_style_radius(cui_Home_Switch1, 500, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Home_Switch1, lv_color_hex(0x2C3A5F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Home_Switch1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(cui_Home_Switch1, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Home_Switch1, lv_color_hex(0x0084FF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(cui_Home_Switch1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(cui_Home_Switch1, 50, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Home_Switch1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Home_Switch1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_t * cui_Room_Title;
    cui_Room_Title = lv_label_create(cui_Content);
    lv_obj_set_width(cui_Room_Title, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Room_Title, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Room_Title, 0);
    lv_obj_set_y(cui_Room_Title, 26);
    lv_obj_set_align(cui_Room_Title, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_Room_Title, "Living room");
    lv_obj_set_style_text_color(cui_Room_Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Room_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Room_Title, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Camera_Image;
    cui_Camera_Image = lv_img_create(cui_Content);
    lv_img_set_src(cui_Camera_Image, &ui_img_camera_png);
    lv_obj_set_width(cui_Camera_Image, lv_pct(100));
    lv_obj_set_height(cui_Camera_Image, lv_pct(57));
    lv_obj_set_x(cui_Camera_Image, 0);
    lv_obj_set_y(cui_Camera_Image, 17);
    lv_obj_set_align(cui_Camera_Image, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Camera_Image, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Camera_Image, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Camera_Image, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(cui_Camera_Image, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(cui_Camera_Image, lv_color_hex(0x0D122C), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_img_recolor_opa(cui_Camera_Image, 150, LV_PART_MAIN | LV_STATE_DISABLED);

    lv_obj_t * cui_Camere_Off;
    cui_Camere_Off = lv_img_create(cui_Camera_Image);
    lv_img_set_src(cui_Camere_Off, &ui_img_camera_off_png);
    lv_obj_set_width(cui_Camere_Off, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Camere_Off, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Camere_Off, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Camere_Off, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Camere_Off, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(cui_Camere_Off, 0, LV_PART_MAIN | LV_STATE_DISABLED);

    lv_obj_t * cui_Camera_Footer;
    cui_Camera_Footer = lv_obj_create(cui_Content);
    lv_obj_set_height(cui_Camera_Footer, 10);
    lv_obj_set_width(cui_Camera_Footer, lv_pct(100));
    lv_obj_set_align(cui_Camera_Footer, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(cui_Camera_Footer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Camera_Footer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(cui_Camera_Footer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Camera_Footer, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Camera_Footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_Camera_Footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_Camera_Footer, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Red_Circle;
    cui_Red_Circle = lv_obj_create(cui_Camera_Footer);
    lv_obj_set_width(cui_Red_Circle, 8);
    lv_obj_set_height(cui_Red_Circle, 8);
    lv_obj_set_align(cui_Red_Circle, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(cui_Red_Circle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Red_Circle, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Red_Circle, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Red_Circle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Live_Title;
    cui_Live_Title = lv_label_create(cui_Camera_Footer);
    lv_obj_set_width(cui_Live_Title, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Live_Title, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Live_Title, 14);
    lv_obj_set_y(cui_Live_Title, 0);
    lv_obj_set_align(cui_Live_Title, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Live_Title, "Live");
    lv_obj_set_style_text_color(cui_Live_Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Live_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Live_Title, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Edit_Panel1;
    cui_Edit_Panel1 = lv_obj_create(cui_Camera_Footer);
    lv_obj_set_height(cui_Edit_Panel1, lv_pct(100));
    lv_obj_set_flex_grow(cui_Edit_Panel1, 1);
    lv_obj_set_align(cui_Edit_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Edit_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Edit_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Edit_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Resolution_Title;
    cui_Resolution_Title = lv_label_create(cui_Camera_Footer);
    lv_obj_set_width(cui_Resolution_Title, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Resolution_Title, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Resolution_Title, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(cui_Resolution_Title, "4k resolution");
    lv_obj_set_style_text_color(cui_Resolution_Title, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Resolution_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Resolution_Title, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_CAMERA_GROUP_NUM);
    children[UI_COMP_CAMERA_GROUP_CAMERA_GROUP] = cui_Camera_Group;
    children[UI_COMP_CAMERA_GROUP_CONTENT] = cui_Content;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_HEADER] = cui_Camera_Header;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_HEADER_CAMERA_TITLE] = cui_Camera_Title;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_HEADER_HOME_SWITCH1] = cui_Home_Switch1;
    children[UI_COMP_CAMERA_GROUP_CONTENT_ROOM_TITLE] = cui_Room_Title;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_IMAGE] = cui_Camera_Image;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_IMAGE_CAMERE_OFF] = cui_Camere_Off;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER] = cui_Camera_Footer;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER_RED_CIRCLE] = cui_Red_Circle;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER_LIVE_TITLE] = cui_Live_Title;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER_EDIT_PANEL1] = cui_Edit_Panel1;
    children[UI_COMP_CAMERA_GROUP_CONTENT_CAMERA_FOOTER_RESOLUTION_TITLE] = cui_Resolution_Title;
    lv_obj_add_event_cb(cui_Camera_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Camera_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    lv_obj_add_event_cb(cui_Home_Switch1, ui_event_comp_Camera_Group_Home_Switch1, LV_EVENT_ALL, children);
    return cui_Camera_Group;
}



// COMPONENT Listcomp

lv_obj_t * ui_Listcomp_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Listcomp;
    cui_Listcomp = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Listcomp, 36);
    lv_obj_set_width(cui_Listcomp, lv_pct(100));
    lv_obj_set_align(cui_Listcomp, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Listcomp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Listcomp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Listcomp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_Listcomp, lv_color_hex(0x41455D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_Listcomp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_Listcomp, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(cui_Listcomp, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Settings_Title1;
    cui_Settings_Title1 = lv_label_create(cui_Listcomp);
    lv_obj_set_width(cui_Settings_Title1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Settings_Title1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Settings_Title1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_Settings_Title1, "Time widget");
    lv_obj_set_style_text_color(cui_Settings_Title1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Settings_Title1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Settings_Title1, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Switch;
    cui_Switch = lv_switch_create(cui_Listcomp);
    lv_obj_set_width(cui_Switch, 30);
    lv_obj_set_height(cui_Switch, 16);
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

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_LISTCOMP_NUM);
    children[UI_COMP_LISTCOMP_LISTCOMP] = cui_Listcomp;
    children[UI_COMP_LISTCOMP_SETTINGS_TITLE1] = cui_Settings_Title1;
    children[UI_COMP_LISTCOMP_SWITCH] = cui_Switch;
    lv_obj_add_event_cb(cui_Listcomp, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Listcomp, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Listcomp;
}



// COMPONENT Music Group

lv_obj_t * ui_Music_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Music_Group;
    cui_Music_Group = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Music_Group, 134);
    lv_obj_set_height(cui_Music_Group, 178);
    lv_obj_set_align(cui_Music_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Music_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Music_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Music_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Music_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Music_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Music_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Music_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Music_Group, 16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Music_Group);
    lv_obj_set_width(cui_Content, 126);
    lv_obj_set_height(cui_Content, 178);
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Home_Image2;
    cui_Home_Image2 = lv_img_create(cui_Content);
    lv_img_set_src(cui_Home_Image2, &ui_img_music_bg_png);
    lv_obj_set_width(cui_Home_Image2, lv_pct(100));
    lv_obj_set_height(cui_Home_Image2, lv_pct(45));
    lv_obj_set_align(cui_Home_Image2, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(cui_Home_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Home_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Home_Image2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(cui_Home_Image2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Music_Text_Group;
    cui_Music_Text_Group = lv_obj_create(cui_Content);
    lv_obj_set_height(cui_Music_Text_Group, 32);
    lv_obj_set_width(cui_Music_Text_Group, lv_pct(100));
    lv_obj_set_x(cui_Music_Text_Group, 0);
    lv_obj_set_y(cui_Music_Text_Group, 7);
    lv_obj_set_align(cui_Music_Text_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Music_Text_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Music_Text_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Music_Text_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Music_Author;
    cui_Music_Author = lv_label_create(cui_Music_Text_Group);
    lv_obj_set_width(cui_Music_Author, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Music_Author, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Music_Author, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(cui_Music_Author, "Harry Styles");
    lv_obj_set_style_text_color(cui_Music_Author, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Music_Author, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Music_Author, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Music_Title;
    cui_Music_Title = lv_label_create(cui_Music_Text_Group);
    lv_obj_set_width(cui_Music_Title, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Music_Title, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Music_Title, 0);
    lv_obj_set_y(cui_Music_Title, 3);
    lv_obj_set_align(cui_Music_Title, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_Music_Title, "Falling");
    lv_obj_set_style_text_color(cui_Music_Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Music_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Music_Title, &ui_font_H2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Slider_Group;
    cui_Slider_Group = lv_obj_create(cui_Content);
    lv_obj_set_height(cui_Slider_Group, 32);
    lv_obj_set_width(cui_Slider_Group, lv_pct(110));
    lv_obj_set_x(cui_Slider_Group, 0);
    lv_obj_set_y(cui_Slider_Group, 40);
    lv_obj_set_align(cui_Slider_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Slider_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Slider_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Slider_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Time_Slider;
    cui_Time_Slider = lv_slider_create(cui_Slider_Group);
    lv_slider_set_value(cui_Time_Slider, 70, LV_ANIM_OFF);
    if(lv_slider_get_mode(cui_Time_Slider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(cui_Time_Slider, 0,
                                                                                                 LV_ANIM_OFF);
    lv_obj_set_height(cui_Time_Slider, 3);
    lv_obj_set_width(cui_Time_Slider, lv_pct(90));
    lv_obj_set_x(cui_Time_Slider, 0);
    lv_obj_set_y(cui_Time_Slider, 10);
    lv_obj_set_align(cui_Time_Slider, LV_ALIGN_TOP_MID);
    lv_obj_set_style_radius(cui_Time_Slider, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Time_Slider, lv_color_hex(0x2C3A5F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Time_Slider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(cui_Time_Slider, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Time_Slider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Time_Slider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(cui_Time_Slider, 40, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Time_Slider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Time_Slider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Time_Slider, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Time_Slider, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Time_Slider, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Time_Slider, 3, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_t * cui_Music_Time_Current;
    cui_Music_Time_Current = lv_label_create(cui_Slider_Group);
    lv_obj_set_width(cui_Music_Time_Current, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Music_Time_Current, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Music_Time_Current, 5);
    lv_obj_set_y(cui_Music_Time_Current, 14);
    lv_label_set_text(cui_Music_Time_Current, "1:55");
    lv_obj_set_style_text_color(cui_Music_Time_Current, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Music_Time_Current, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Music_Time_Current, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Music_Time_Long;
    cui_Music_Time_Long = lv_label_create(cui_Slider_Group);
    lv_obj_set_width(cui_Music_Time_Long, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Music_Time_Long, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Music_Time_Long, -5);
    lv_obj_set_y(cui_Music_Time_Long, 14);
    lv_obj_set_align(cui_Music_Time_Long, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(cui_Music_Time_Long, "3:24");
    lv_obj_set_style_text_color(cui_Music_Time_Long, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Music_Time_Long, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Music_Time_Long, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Control_Group;
    cui_Control_Group = lv_obj_create(cui_Content);
    lv_obj_set_height(cui_Control_Group, 30);
    lv_obj_set_width(cui_Control_Group, lv_pct(110));
    lv_obj_set_align(cui_Control_Group, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(cui_Control_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Control_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Control_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Control_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Control_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Control_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Control_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Prev;
    cui_Prev = lv_img_create(cui_Control_Group);
    lv_img_set_src(cui_Prev, &ui_img_prev_png);
    lv_obj_set_width(cui_Prev, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Prev, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Prev, 6);
    lv_obj_set_y(cui_Prev, 0);
    lv_obj_set_align(cui_Prev, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(cui_Prev, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Prev, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(cui_Prev, lv_color_hex(0x10163A), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(cui_Prev, 150, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_t * cui_Next;
    cui_Next = lv_img_create(cui_Control_Group);
    lv_img_set_src(cui_Next, &ui_img_next_png);
    lv_obj_set_width(cui_Next, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Next, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Next, -6);
    lv_obj_set_y(cui_Next, 0);
    lv_obj_set_align(cui_Next, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(cui_Next, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Next, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(cui_Next, lv_color_hex(0x10163A), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(cui_Next, 150, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_t * cui_Music_Play_Bg;
    cui_Music_Play_Bg = lv_obj_create(cui_Control_Group);
    lv_obj_set_width(cui_Music_Play_Bg, 30);
    lv_obj_set_height(cui_Music_Play_Bg, 30);
    lv_obj_set_align(cui_Music_Play_Bg, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Music_Play_Bg, LV_OBJ_FLAG_CHECKABLE);     /// Flags
    lv_obj_clear_flag(cui_Music_Play_Bg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Music_Play_Bg, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Music_Play_Bg, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Music_Play_Bg, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(cui_Music_Play_Bg, &ui_img_play_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(cui_Music_Play_Bg, &ui_img_pause_png, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(cui_Music_Play_Bg, lv_color_hex(0x1A2045), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(cui_Music_Play_Bg, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_img_recolor(cui_Music_Play_Bg, lv_color_hex(0x10163A), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_img_recolor_opa(cui_Music_Play_Bg, 150, LV_PART_MAIN | LV_STATE_PRESSED);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_MUSIC_GROUP_NUM);
    children[UI_COMP_MUSIC_GROUP_MUSIC_GROUP] = cui_Music_Group;
    children[UI_COMP_MUSIC_GROUP_CONTENT] = cui_Content;
    children[UI_COMP_MUSIC_GROUP_CONTENT_HOME_IMAGE2] = cui_Home_Image2;
    children[UI_COMP_MUSIC_GROUP_CONTENT_MUSIC_TEXT_GROUP] = cui_Music_Text_Group;
    children[UI_COMP_MUSIC_GROUP_CONTENT_MUSIC_TEXT_GROUP_MUSIC_AUTHOR] = cui_Music_Author;
    children[UI_COMP_MUSIC_GROUP_CONTENT_MUSIC_TEXT_GROUP_MUSIC_TITLE] = cui_Music_Title;
    children[UI_COMP_MUSIC_GROUP_CONTENT_SLIDER_GROUP] = cui_Slider_Group;
    children[UI_COMP_MUSIC_GROUP_CONTENT_SLIDER_GROUP_TIME_SLIDER] = cui_Time_Slider;
    children[UI_COMP_MUSIC_GROUP_CONTENT_SLIDER_GROUP_MUSIC_TIME_CURRENT] = cui_Music_Time_Current;
    children[UI_COMP_MUSIC_GROUP_CONTENT_SLIDER_GROUP_MUSIC_TIME_LONG] = cui_Music_Time_Long;
    children[UI_COMP_MUSIC_GROUP_CONTENT_CONTROL_GROUP] = cui_Control_Group;
    children[UI_COMP_MUSIC_GROUP_CONTENT_CONTROL_GROUP_PREV] = cui_Prev;
    children[UI_COMP_MUSIC_GROUP_CONTENT_CONTROL_GROUP_NEXT] = cui_Next;
    children[UI_COMP_MUSIC_GROUP_CONTENT_CONTROL_GROUP_MUSIC_PLAY_BG] = cui_Music_Play_Bg;
    lv_obj_add_event_cb(cui_Music_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Music_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Music_Group;
}



// COMPONENT Notifi Group

lv_obj_t * ui_Notifi_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Notifi_Group;
    cui_Notifi_Group = lv_obj_create(comp_parent);
    lv_obj_set_height(cui_Notifi_Group, 40);
    lv_obj_set_width(cui_Notifi_Group, LV_SIZE_CONTENT);   /// 366
    lv_obj_set_x(cui_Notifi_Group, -156);
    lv_obj_set_y(cui_Notifi_Group, 69);
    lv_obj_set_align(cui_Notifi_Group, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(cui_Notifi_Group, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Notifi_Group, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Notifi_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Notifi_Group, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Notifi_Group, lv_color_hex(0x14A632), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Notifi_Group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(cui_Notifi_Group, lv_color_hex(0x0E142C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(cui_Notifi_Group, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(cui_Notifi_Group, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(cui_Notifi_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(cui_Notifi_Group, -9, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(cui_Notifi_Group, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Notifi_Group, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Notifi_Group, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Notifi_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Notifi_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_Notifi_Group, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_Notifi_Group, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Notifi_Image;
    cui_Notifi_Image = lv_img_create(cui_Notifi_Group);
    lv_img_set_src(cui_Notifi_Image, &ui_img_ble_big_png);
    lv_obj_set_width(cui_Notifi_Image, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Notifi_Image, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Notifi_Image, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Notifi_Image, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Notifi_Image, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_Notifi_Label;
    cui_Notifi_Label = lv_label_create(cui_Notifi_Group);
    lv_obj_set_width(cui_Notifi_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Notifi_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Notifi_Label, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Notifi_Label, "Bluetooth has been connected!");
    lv_obj_set_style_text_color(cui_Notifi_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Notifi_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Notifi_Label, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_NOTIFI_GROUP_NUM);
    children[UI_COMP_NOTIFI_GROUP_NOTIFI_GROUP] = cui_Notifi_Group;
    children[UI_COMP_NOTIFI_GROUP_NOTIFI_IMAGE] = cui_Notifi_Image;
    children[UI_COMP_NOTIFI_GROUP_NOTIFI_LABEL] = cui_Notifi_Label;
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
    lv_obj_set_width(cui_Settings_Panel, 176);
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
    lv_obj_set_style_pad_left(cui_Settings_Panel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Settings_Panel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Settings_Panel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Settings_Panel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Home_Panel;
    cui_Home_Panel = lv_obj_create(cui_Settings_Panel);
    lv_obj_set_height(cui_Home_Panel, 28);
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

    lv_obj_t * cui_List_Time;
    cui_List_Time = ui_Listcomp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Time, 0);
    lv_obj_set_y(cui_List_Time, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Time, UI_COMP_LISTCOMP_SETTINGS_TITLE1), "Time");

    lv_obj_t * cui_List_Weather;
    cui_List_Weather = ui_Listcomp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Weather, 0);
    lv_obj_set_y(cui_List_Weather, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Weather, UI_COMP_LISTCOMP_SETTINGS_TITLE1), "Weather");

    lv_obj_t * cui_List_Temperature;
    cui_List_Temperature = ui_Listcomp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Temperature, 0);
    lv_obj_set_y(cui_List_Temperature, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Temperature, UI_COMP_LISTCOMP_SETTINGS_TITLE1), "Temperature");

    lv_obj_t * cui_List_Camera;
    cui_List_Camera = ui_Listcomp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Camera, 0);
    lv_obj_set_y(cui_List_Camera, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Camera, UI_COMP_LISTCOMP_SETTINGS_TITLE1), "Camera");

    lv_obj_t * cui_List_Solar;
    cui_List_Solar = ui_Listcomp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Solar, 0);
    lv_obj_set_y(cui_List_Solar, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Solar, UI_COMP_LISTCOMP_SETTINGS_TITLE1), "Solar");

    lv_obj_t * cui_List_Music;
    cui_List_Music = ui_Listcomp_create(cui_Settings_Content);
    lv_obj_set_x(cui_List_Music, 0);
    lv_obj_set_y(cui_List_Music, 0);

    lv_label_set_text(ui_comp_get_child(cui_List_Music, UI_COMP_LISTCOMP_SETTINGS_TITLE1), "Music Player");

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SETTINGS_GROUP_NUM);
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_GROUP] = cui_Settings_Group;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_DARK] = cui_Settings_Dark;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL] = cui_Settings_Panel;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL_HOME_PANEL] = cui_Home_Panel;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL_HOME_PANEL_SETTINGS_TITLE] = cui_Settings_Title;
    children[UI_COMP_SETTINGS_GROUP_SETTINGS_PANEL_SETTINGS_CONTENT] = cui_Settings_Content;
    children[UI_COMP_SETTINGS_GROUP_LIST_TIME] = cui_List_Time;
    children[UI_COMP_SETTINGS_GROUP_LIST_TIME_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Time,
                                                                                   UI_COMP_LISTCOMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_TIME_SWITCH] = ui_comp_get_child(cui_List_Time, UI_COMP_LISTCOMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_WEATHER] = cui_List_Weather;
    children[UI_COMP_SETTINGS_GROUP_LIST_WEATHER_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Weather,
                                                                                      UI_COMP_LISTCOMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_WEATHER_SWITCH] = ui_comp_get_child(cui_List_Weather, UI_COMP_LISTCOMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_TEMPERATURE] = cui_List_Temperature;
    children[UI_COMP_SETTINGS_GROUP_LIST_TEMPERATURE_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Temperature,
                                                                                          UI_COMP_LISTCOMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_TEMPERATURE_SWITCH] = ui_comp_get_child(cui_List_Temperature,
                                                                                 UI_COMP_LISTCOMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_CAMERA] = cui_List_Camera;
    children[UI_COMP_SETTINGS_GROUP_LIST_CAMERA_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Camera,
                                                                                     UI_COMP_LISTCOMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_CAMERA_SWITCH] = ui_comp_get_child(cui_List_Camera, UI_COMP_LISTCOMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_SOLAR] = cui_List_Solar;
    children[UI_COMP_SETTINGS_GROUP_LIST_SOLAR_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Solar,
                                                                                    UI_COMP_LISTCOMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_SOLAR_SWITCH] = ui_comp_get_child(cui_List_Solar, UI_COMP_LISTCOMP_SWITCH);
    children[UI_COMP_SETTINGS_GROUP_LIST_MUSIC] = cui_List_Music;
    children[UI_COMP_SETTINGS_GROUP_LIST_MUSIC_SETTINGS_TITLE1] = ui_comp_get_child(cui_List_Music,
                                                                                    UI_COMP_LISTCOMP_SETTINGS_TITLE1);
    children[UI_COMP_SETTINGS_GROUP_LIST_MUSIC_SWITCH] = ui_comp_get_child(cui_List_Music, UI_COMP_LISTCOMP_SWITCH);
    lv_obj_add_event_cb(cui_Settings_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Settings_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Settings_Group;
}



// COMPONENT Solarpanels Group

lv_obj_t * ui_Solarpanels_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Solarpanels_Group;
    cui_Solarpanels_Group = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Solarpanels_Group, 134);
    lv_obj_set_height(cui_Solarpanels_Group, 178);
    lv_obj_set_align(cui_Solarpanels_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Solarpanels_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Solarpanels_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Solarpanels_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Solarpanels_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Solarpanels_Group);
    lv_obj_set_width(cui_Content, 126);
    lv_obj_set_height(cui_Content, 178);
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Solar_Title;
    cui_Solar_Title = lv_label_create(cui_Content);
    lv_obj_set_width(cui_Solar_Title, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Solar_Title, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Solar_Title, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_Solar_Title, "Solar panles");
    lv_obj_set_style_text_color(cui_Solar_Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Solar_Title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Solar_Title, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content_Group_3;
    cui_Content_Group_3 = lv_obj_create(cui_Content);
    lv_obj_set_height(cui_Content_Group_3, 30);
    lv_obj_set_width(cui_Content_Group_3, lv_pct(100));
    lv_obj_set_x(cui_Content_Group_3, 0);
    lv_obj_set_y(cui_Content_Group_3, 3);
    lv_obj_set_align(cui_Content_Group_3, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(cui_Content_Group_3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Content_Group_3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content_Group_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Title_Number_Group7;
    cui_Title_Number_Group7 = ui_Title_Number_Group_create(cui_Content_Group_3);
    lv_obj_set_height(cui_Title_Number_Group7, 30);
    lv_obj_set_width(cui_Title_Number_Group7, lv_pct(55));
    lv_obj_set_x(cui_Title_Number_Group7, 0);
    lv_obj_set_y(cui_Title_Number_Group7, 0);
    lv_obj_set_align(cui_Title_Number_Group7, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group7, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "CAPACITY");

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group7, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2), "4kW");

    lv_obj_t * cui_Title_Number_Group8;
    cui_Title_Number_Group8 = ui_Title_Number_Group_create(cui_Content_Group_3);
    lv_obj_set_x(cui_Title_Number_Group8, 0);
    lv_obj_set_y(cui_Title_Number_Group8, 0);
    lv_obj_set_align(cui_Title_Number_Group8, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_border_color(cui_Title_Number_Group8, lv_color_hex(0x616688), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_Title_Number_Group8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group8, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "CO2");

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group8, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2), "2.4 t");

    lv_obj_t * cui_Home_Chart1;
    cui_Home_Chart1 = lv_chart_create(cui_Content);
    lv_obj_set_height(cui_Home_Chart1, 60);
    lv_obj_set_width(cui_Home_Chart1, lv_pct(100));
    lv_obj_set_x(cui_Home_Chart1, 0);
    lv_obj_set_y(cui_Home_Chart1, 12);
    lv_obj_set_align(cui_Home_Chart1, LV_ALIGN_CENTER);
    lv_chart_set_type(cui_Home_Chart1, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(cui_Home_Chart1, 20);
    lv_chart_set_div_line_count(cui_Home_Chart1, 5, 0);
    lv_chart_set_zoom_x(cui_Home_Chart1, 512);
    lv_chart_set_zoom_y(cui_Home_Chart1, 256);
    lv_chart_set_axis_tick(cui_Home_Chart1, LV_CHART_AXIS_PRIMARY_X, 0, 0, 0, 0, false, 50);
    lv_chart_set_axis_tick(cui_Home_Chart1, LV_CHART_AXIS_PRIMARY_Y, 0, 0, 5, 2, false, 50);
    lv_chart_series_t * cui_Home_Chart1_series_1 = lv_chart_add_series(cui_Home_Chart1, lv_color_hex(0x3186FF),
                                                                       LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t cui_Home_Chart1_series_1_array[] = { 50, 20, 40, 70, 62, 84, 38, 49, 67, 47, 50, 20, 70, 87, 47, 52, 34, 46, 24, 16 };
    lv_chart_set_ext_y_array(cui_Home_Chart1, cui_Home_Chart1_series_1, cui_Home_Chart1_series_1_array);
    lv_obj_set_style_radius(cui_Home_Chart1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Home_Chart1, lv_color_hex(0x2F3F65), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Home_Chart1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(cui_Home_Chart1, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(cui_Home_Chart1, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(cui_Home_Chart1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(cui_Home_Chart1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(cui_Home_Chart1, lv_color_hex(0x444C71), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Home_Chart1, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    lv_obj_set_style_line_width(cui_Home_Chart1, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(cui_Home_Chart1, true, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(cui_Home_Chart1, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Home_Chart1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Home_Chart1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(cui_Home_Chart1, lv_color_hex(0x131D3E), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(cui_Home_Chart1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(cui_Home_Chart1, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(cui_Home_Chart1, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_size(cui_Home_Chart1, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_line_color(cui_Home_Chart1, lv_color_hex(0x6D7593), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(cui_Home_Chart1, 100, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(cui_Home_Chart1, lv_color_hex(0x6D7593), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Home_Chart1, 255, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Home_Chart1, &ui_font_Subtitle, LV_PART_TICKS | LV_STATE_DEFAULT);

    lv_obj_t * cui_Solar_Title1;
    cui_Solar_Title1 = lv_label_create(cui_Content);
    lv_obj_set_width(cui_Solar_Title1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Solar_Title1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Solar_Title1, 0);
    lv_obj_set_y(cui_Solar_Title1, 18);
    lv_obj_set_align(cui_Solar_Title1, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_Solar_Title1, "3.2 kW");
    lv_obj_set_style_text_color(cui_Solar_Title1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_Solar_Title1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Solar_Title1, &ui_font_BigNumber, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SOLARPANELS_GROUP_NUM);
    children[UI_COMP_SOLARPANELS_GROUP_SOLARPANELS_GROUP] = cui_Solarpanels_Group;
    children[UI_COMP_SOLARPANELS_GROUP_CONTENT] = cui_Content;
    children[UI_COMP_SOLARPANELS_GROUP_CONTENT_SOLAR_TITLE] = cui_Solar_Title;
    children[UI_COMP_SOLARPANELS_GROUP_CONTENT_CONTENT_GROUP_3] = cui_Content_Group_3;
    children[UI_COMP_SOLARPANELS_GROUP_TITLE_NUMBER_GROUP7] = cui_Title_Number_Group7;
    children[UI_COMP_SOLARPANELS_GROUP_TITLE_NUMBER_GROUP7_TNG_TITLE2] = ui_comp_get_child(cui_Title_Number_Group7,
                                                                                           UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2);
    children[UI_COMP_SOLARPANELS_GROUP_TITLE_NUMBER_GROUP7_TNG_NUMBER2] = ui_comp_get_child(cui_Title_Number_Group7,
                                                                                            UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2);
    children[UI_COMP_SOLARPANELS_GROUP_TITLE_NUMBER_GROUP8] = cui_Title_Number_Group8;
    children[UI_COMP_SOLARPANELS_GROUP_TITLE_NUMBER_GROUP8_TNG_TITLE2] = ui_comp_get_child(cui_Title_Number_Group8,
                                                                                           UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2);
    children[UI_COMP_SOLARPANELS_GROUP_TITLE_NUMBER_GROUP8_TNG_NUMBER2] = ui_comp_get_child(cui_Title_Number_Group8,
                                                                                            UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2);
    children[UI_COMP_SOLARPANELS_GROUP_CONTENT_HOME_CHART1] = cui_Home_Chart1;
    children[UI_COMP_SOLARPANELS_GROUP_CONTENT_SOLAR_TITLE1] = cui_Solar_Title1;
    lv_obj_add_event_cb(cui_Solarpanels_Group, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Solarpanels_Group, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Solarpanels_Group;
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
    lv_obj_set_width(cui_Temperature_Group, 134);
    lv_obj_set_height(cui_Temperature_Group, 178);
    lv_obj_set_align(cui_Temperature_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Temperature_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Temperature_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Temperature_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Temperature_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Temperature_Group);
    lv_obj_set_width(cui_Content, 126);
    lv_obj_set_height(cui_Content, 178);
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

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
    lv_obj_set_y(cui_City2, 17);
    lv_obj_set_align(cui_City2, LV_ALIGN_CENTER);
    lv_label_set_text(cui_City2, "Heat set to");
    lv_obj_set_style_text_color(cui_City2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_City2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_City2, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Thermostat_Arc;
    cui_Thermostat_Arc = lv_arc_create(cui_Thermostat_BG);
    lv_obj_set_width(cui_Thermostat_Arc, 106);
    lv_obj_set_height(cui_Thermostat_Arc, 106);
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
    lv_obj_set_style_pad_left(cui_Thermostat_Arc, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Thermostat_Arc, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Thermostat_Arc, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Thermostat_Arc, 4, LV_PART_KNOB | LV_STATE_DEFAULT);

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
    lv_obj_set_height(cui_Content_Group_1, 30);
    lv_obj_set_width(cui_Content_Group_1, lv_pct(110));
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
    lv_obj_set_width(cui_Time_Group, 134);
    lv_obj_set_height(cui_Time_Group, 178);
    lv_obj_set_align(cui_Time_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Time_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Time_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Time_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Time_Group);
    lv_obj_set_width(cui_Content, 126);
    lv_obj_set_height(cui_Content, 178);
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

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
    lv_obj_set_y(cui_City, 35);
    lv_obj_set_align(cui_City, LV_ALIGN_TOP_MID);
    lv_label_set_text(cui_City, "New York, USA");
    lv_obj_set_style_text_color(cui_City, lv_color_hex(0x6D7293), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(cui_City, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_City, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Clock_Group;
    cui_Clock_Group = lv_obj_create(cui_Content);
    lv_obj_set_width(cui_Clock_Group, 120);
    lv_obj_set_height(cui_Clock_Group, 120);
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
    lv_img_set_angle(cui_Clock_Hour_Shadow, 180);

    lv_obj_t * cui_Clock_Hour;
    cui_Clock_Hour = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_Hour, &ui_img_clock_hour_png);
    lv_obj_set_width(cui_Clock_Hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_Hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Clock_Hour, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_Hour, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_Hour, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(cui_Clock_Hour, 180);

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
    lv_img_set_angle(cui_Clock_Min_Shadow, 2600);

    lv_obj_t * cui_Clock_Min;
    cui_Clock_Min = lv_img_create(cui_Clock_Group);
    lv_img_set_src(cui_Clock_Min, &ui_img_clock_min_png);
    lv_obj_set_width(cui_Clock_Min, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Clock_Min, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Clock_Min, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Clock_Min, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Clock_Min, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(cui_Clock_Min, 2600);

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
    lv_obj_set_height(cui_Title_Number_Group, 30);
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



// COMPONENT Weather Group

lv_obj_t * ui_Weather_Group_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Weather_Group;
    cui_Weather_Group = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Weather_Group, 134);
    lv_obj_set_height(cui_Weather_Group, 178);
    lv_obj_set_align(cui_Weather_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Weather_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Weather_Group, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Weather_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Weather_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Weather_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Weather_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Weather_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Content;
    cui_Content = lv_obj_create(cui_Weather_Group);
    lv_obj_set_width(cui_Content, 126);
    lv_obj_set_height(cui_Content, 178);
    lv_obj_set_align(cui_Content, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_Content, lv_color_hex(0x0A122B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_Content, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

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
    lv_obj_set_width(cui_Weather_Rain_Group, 120);
    lv_obj_set_height(cui_Weather_Rain_Group, 89);
    lv_obj_set_x(cui_Weather_Rain_Group, 0);
    lv_obj_set_y(cui_Weather_Rain_Group, -10);
    lv_obj_set_align(cui_Weather_Rain_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Weather_Rain_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Weather_Rain_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Weather_Rain_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Rain;
    cui_Rain = lv_img_create(cui_Weather_Rain_Group);
    lv_img_set_src(cui_Rain, &ui_img_rain_png);
    lv_obj_set_height(cui_Rain, 50);
    lv_obj_set_width(cui_Rain, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(cui_Rain, 0);
    lv_obj_set_y(cui_Rain, 17);
    lv_obj_set_align(cui_Rain, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_Rain, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_Rain, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(cui_Rain, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Rain1;
    cui_Rain1 = lv_img_create(cui_Weather_Rain_Group);
    lv_img_set_src(cui_Rain1, &ui_img_rain_png);
    lv_obj_set_height(cui_Rain1, 50);
    lv_obj_set_width(cui_Rain1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(cui_Rain1, 5);
    lv_obj_set_y(cui_Rain1, 22);
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
    lv_obj_set_height(cui_Content_Group_2, 29);
    lv_obj_set_width(cui_Content_Group_2, lv_pct(110));
    lv_obj_set_align(cui_Content_Group_2, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(cui_Content_Group_2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_Content_Group_2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_Content_Group_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Title_Number_Group4;
    cui_Title_Number_Group4 = ui_Title_Number_Group_create(cui_Content_Group_2);
    lv_obj_set_height(cui_Title_Number_Group4, 30);
    lv_obj_set_width(cui_Title_Number_Group4, lv_pct(33));
    lv_obj_set_x(cui_Title_Number_Group4, 0);
    lv_obj_set_y(cui_Title_Number_Group4, 0);
    lv_obj_set_align(cui_Title_Number_Group4, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group4, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "FRI");

    lv_obj_t * cui_Title_Number_Group5;
    cui_Title_Number_Group5 = ui_Title_Number_Group_create(cui_Content_Group_2);
    lv_obj_set_height(cui_Title_Number_Group5, 30);
    lv_obj_set_width(cui_Title_Number_Group5, lv_pct(33));
    lv_obj_set_x(cui_Title_Number_Group5, 0);
    lv_obj_set_y(cui_Title_Number_Group5, 0);
    lv_obj_set_align(cui_Title_Number_Group5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group5, UI_COMP_TITLE_NUMBER_GROUP_TNG_TITLE2), "SAT");

    lv_label_set_text(ui_comp_get_child(cui_Title_Number_Group5, UI_COMP_TITLE_NUMBER_GROUP_TNG_NUMBER2), "24°");

    lv_obj_t * cui_Title_Number_Group6;
    cui_Title_Number_Group6 = ui_Title_Number_Group_create(cui_Content_Group_2);
    lv_obj_set_height(cui_Title_Number_Group6, 30);
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


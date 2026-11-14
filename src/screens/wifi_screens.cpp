#include "wifi_screen.h"
#include "ui.h"
#include "../utils/prog_events.h"

WiFiScreen::WiFiScreen()
{
   
}

WiFiScreen::~WiFiScreen()
{
   
}

void WiFiScreen::initDisplay() {
   ui_wifiSrc_screen_init();
}

void WiFiScreen::destroyDisplay() {
   ui_wifiSrc_screen_init();
}

void WiFiScreen::toggleWiFi() {
    if (lv_obj_has_state(ui_wifiOnOffSwitch, LV_STATE_CHECKED)) {
        lv_obj_clear_state(ui_wifiOnOffSwitch, LV_STATE_CHECKED);
    } else {
        lv_obj_add_state(ui_wifiOnOffSwitch, LV_STATE_CHECKED);
    }
}

void WiFiScreen::addGotoMainListener(void (*cb)()) {
    gotoMainCallback = cb;
}

void WiFiScreen::upKeyPress() {
    uint16_t activeTabIndex = lv_tabview_get_tab_act(ui_wigiTabView);
    lv_tabview_set_act(ui_wigiTabView, activeTabIndex > 0 ? activeTabIndex - 1 : activeTabIndex, LV_ANIM_OFF);
}

void WiFiScreen::downKeyPress() {
    uint16_t activeTabIndex = lv_tabview_get_tab_act(ui_wigiTabView);
    lv_obj_t * content = lv_tabview_get_content(ui_wigiTabView);
    uint16_t tabСount = lv_obj_get_child_cnt(content);
    lv_tabview_set_act(ui_wigiTabView, activeTabIndex < tabСount - 1 ? activeTabIndex + 1 : activeTabIndex, LV_ANIM_OFF);
}

void WiFiScreen::enterKeyPress() {
   uint16_t activeTabIndex = lv_tabview_get_tab_act(ui_wigiTabView);
   switch (activeTabIndex)
    {
    case 0:
        toggleWiFi();
        break;  
    
    default:
        break;
    }
}

void WiFiScreen::backKeyPress() {
   gotoMainCallback();
}

void WiFiScreen::leftKeyPress() {

}

void WiFiScreen::rightKeyPress() {

}
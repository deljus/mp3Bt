#include "main_screen.h"
#include "ui.h"

MainScreen::MainScreen()
{

}

MainScreen::~MainScreen()
{
   
}

void MainScreen::initDisplay() {
   ui_main_screen_init();
}

void MainScreen::destroyDisplay() {
   ui_main_screen_destroy();
}

void MainScreen::addGotoPlayerListener(void (*cb)()) {
    gotoPlayerCallback = cb;
}

void MainScreen::addGotoWifiListener(void (*cb)()) {
    gotoWifiCallback = cb;
}

void MainScreen::upKeyPress() {
    uint16_t activeTabIndex = lv_tabview_get_tab_act(ui_TabView1);
    lv_tabview_set_act(ui_TabView1, activeTabIndex > 0 ? activeTabIndex - 1 : activeTabIndex, LV_ANIM_OFF);
}

void MainScreen::downKeyPress() {
    uint16_t activeTabIndex = lv_tabview_get_tab_act(ui_TabView1);
    lv_obj_t * content = lv_tabview_get_content(ui_TabView1);
    uint16_t tabСount = lv_obj_get_child_cnt(content);
    lv_tabview_set_act(ui_TabView1, activeTabIndex < tabСount - 1 ? activeTabIndex + 1 : activeTabIndex, LV_ANIM_OFF);
}

void MainScreen::enterKeyPress() {
    uint16_t activeTabIndex = lv_tabview_get_tab_act(ui_TabView1);
    switch (activeTabIndex)
    {
    case 0:
        gotoPlayerCallback();
        break;  
    case 1:
        gotoWifiCallback();
        break;

    default:
        break;
    }
}

void MainScreen::backKeyPress() {

}

void MainScreen::leftKeyPress() {

}

void MainScreen::rightKeyPress() {

}
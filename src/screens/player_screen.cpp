#include "player_screen.h"
#include "ui.h"
#include "../utils/prog_events.h"

PlayerScreen::PlayerScreen()
{
   
}

PlayerScreen::~PlayerScreen()
{
   
}

void PlayerScreen::initDisplay() {
   ui_player_screen_init();
}

void PlayerScreen::destroyDisplay() {
   ui_player_screen_destroy();
}

void PlayerScreen::onIncrementVolume(int32_t volume) {

}

void PlayerScreen::onDecrementVolume(int32_t volume) {
   
}

void PlayerScreen::onPlay() {
  
}

void PlayerScreen::onPause() {
   
}

void PlayerScreen::onPrevSound() {
  
}

void PlayerScreen::onNextSound() {
   
}



void PlayerScreen::addGotoMainListener(void (*cb)()) {
    gotoMainCallback = cb;
}

void PlayerScreen::upKeyPress() {
   int32_t val = lv_bar_get_value(ui_volumeBar);
   int32_t max_val = lv_bar_get_max_value(ui_volumeBar);
   val = (val + 1 > max_val) ? max_val : (val + deltaVolume);
   lv_bar_set_value(ui_volumeBar, val, LV_ANIM_ON);
   onIncrementVolume(val);
}

void PlayerScreen::downKeyPress() {
   int32_t val = lv_bar_get_value(ui_volumeBar);
   int32_t min_val = lv_bar_get_min_value(ui_volumeBar);
   val = (val - 1 < min_val) ? min_val : (val - deltaVolume);
   lv_bar_set_value(ui_volumeBar, val, LV_ANIM_ON);
   onDecrementVolume(val);
}

void PlayerScreen::enterKeyPress() {
   progBtnClick(ui_playBtn, 300);
   bool is_checked = lv_obj_has_state(ui_playBtn, LV_STATE_CHECKED);

   is_checked ? onPause() : onPlay();
}

void PlayerScreen::backKeyPress() {
   gotoMainCallback();
}

void PlayerScreen::leftKeyPress() {
   progBtnClick(ui_prevSoungBtn, 300);
   onPrevSound();
}

void PlayerScreen::rightKeyPress() {
   progBtnClick(ui_nextSoungBtn, 300);
   onNextSound();
}
#include "player_screen.h"
#include "ui.h"

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

void PlayerScreen::addGotoMainListener(void (*cb)()) {
    gotoMainCallback = cb;
}

void PlayerScreen::upKeyPress() {

}

void PlayerScreen::downKeyPress() {

}

void PlayerScreen::enterKeyPress() {

}

void PlayerScreen::backKeyPress() {
   gotoMainCallback();
}

void PlayerScreen::leftKeyPress() {

}

void PlayerScreen::rightKeyPress() {

}
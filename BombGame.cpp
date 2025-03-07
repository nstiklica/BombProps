#include "BombGame.h"

BaseView* BombGame::currentView = nullptr;
KeypadModule* BombGame::keypad = nullptr;

void BombGame::setKeypad(KeypadModule& keypadRef) {
  keypad = &keypadRef;
}

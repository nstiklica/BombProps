#include "BasicBombGame.h"

BombState BasicBombGame::currentState = BombState::ARMING;
BaseView* BasicBombGame::currentView = nullptr;
char BasicBombGame::bombCode[7] = "000000";
KeypadModule* BasicBombGame::keypad = nullptr;

byte rowPins[4] = {9, 8, 7, 6};
byte colPins[4] = {5, 4, 3, 2};

BasicBombGame::BasicBombGame() {}

void BasicBombGame::begin() {
  keypad = new KeypadModule(rowPins, colPins);
  keypad->begin();
  // Initialize first view (InitView)
  //currentView = new InitView(changeState);
  currentView = new ArmingView(changeState, setBombCode);
  currentView->render();
}

void BasicBombGame::update() {
   char key = keypad->getKey();  // ✅ Read key input
    if (key && currentView) {
        currentView->handleInput(key);  // ✅ Send key input to current view
    }
}

void BasicBombGame::changeState(BombState newState) {
  if (currentState == newState) return;

  // Delete current view and switch to the new state
  delete currentView;
  currentView = nullptr;
  currentState = newState;

  switch (newState) {
    case BombState::INIT:
      currentView = new InitView(changeState);
      break;
    case BombState::ARMING:
      currentView = new ArmingView(changeState, setBombCode);
      break;
    case BombState::ARMED:
      // currentView = new ArmedView([this](BombState newState) { changeState(newState); });
      break;
    case BombState::DISARMING:
      // currentView = new DisarmView([this](BombState newState) { changeState(newState); });
      break;
    case BombState::DISARMED:
      // currentView = new DisarmedView([this](BombState newState) { changeState(newState); });
      break;
    case BombState::EXPLODED:
      // currentView = new ExplodedView([this](BombState newState) { changeState(newState); });
      break;
  }

  if (currentView) {
    currentView->render();
  }
}

void BasicBombGame::setBombCode(const char* code) {
  strncpy(bombCode, code, 6);
  bombCode[6] = '\0';  // Ensure null termination
}


const char* BasicBombGame::getBombCode() {
  return bombCode;
}

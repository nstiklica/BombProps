#include "BasicBombGame.h"

BombState BasicBombGame::currentState = BombState::ARMING;
BaseView* BasicBombGame::currentView = nullptr;
char BasicBombGame::bombCode[7] = "000000";
KeypadModule* BasicBombGame::keypad = nullptr;

//Timer
int BasicBombGame::minutes = 30;
int BasicBombGame::seconds = 0;
unsigned long BasicBombGame::lastUpdateTime = 0;

byte rowPins[4] = {9, 8, 7, 6};
byte colPins[4] = {5, 4, 3, 2};

bool BasicBombGame::renderTime = false;

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

  char key = keypad->getKey();
  if (key && currentView) {
    currentView->handleInput(key);
  }

  if (currentState == BombState::ARMED || currentState == BombState::DISARMING) {
    updateCountdown();
    if (renderTime) {
      currentView->refresh();
      renderTime = false;
    }
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
      currentView = new ArmedView(changeState);
      break;
    case BombState::DISARMING:
       currentView = new DisarmView(changeState);
      break;
    case BombState::DISARMED:
      currentView = new SuccessView(changeState);
      break;
    case BombState::EXPLODED:
      // currentView = new ExplodedView([this](BombState newState) { changeState(newState); });
      break;
  }

  if (currentView) {
    currentView->render();
  }
}

int BasicBombGame::getMinutes() {
  return minutes;
}

int BasicBombGame::getSeconds() {
  return seconds;
}

void BasicBombGame::setBombCode(const char* code) {
  strncpy(bombCode, code, 6);
  bombCode[6] = '\0';  // Ensure null termination
}


const char* BasicBombGame::getBombCode() {
  return bombCode;
}

void BasicBombGame::updateCountdown() {
  if (millis() - lastUpdateTime >= 1000) {
    lastUpdateTime = millis();

    if (seconds == 0) {
      if (minutes > 0) {
        minutes--;
        seconds = 59;
      }
    } else {
      seconds--;
      renderTime = true;
    }

    if (minutes == 0 && seconds == 0) {
      changeState(BombState::EXPLODED);
    }
  }
}

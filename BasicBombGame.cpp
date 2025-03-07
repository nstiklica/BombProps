#include "BasicBombGame.h"

BasicBombGameStates BasicBombGame::currentState = BasicBombGameStates::INIT;
char BasicBombGame::bombCode[7] = "000000";

//Timer
int BasicBombGame::minutes = 30;
int BasicBombGame::seconds = 0;
unsigned long BasicBombGame::lastUpdateTime = 0;

bool BasicBombGame::renderTime = false;

BasicBombGame::BasicBombGame() { }

void BasicBombGame::begin() {
  currentView = new InitView(changeState);
  currentView->render();
}

void BasicBombGame::update() {

  char key = keypad->getKey();
  if (key && currentView) {
    currentView->handleInput(key);
  }

  if (currentState == BasicBombGameStates::ARMED || currentState == BasicBombGameStates::DISARMING) {
    updateCountdown();
    if (renderTime) {
      currentView->refresh();
      renderTime = false;
    }
  }
}

void BasicBombGame::changeState(BasicBombGameStates newState) {
  if (currentState == newState) return;

  // Delete current view and switch to the new state
  delete currentView;
  currentView = nullptr;
  currentState = newState;

  switch (newState) {
    case BasicBombGameStates::INIT:
      currentView = new InitView(changeState);
      break;
    case BasicBombGameStates::ARMING:
      currentView = new ArmingView(changeState, setBombCode);
      break;
    case BasicBombGameStates::ARMED:
      currentView = new ArmedView(changeState);
      break;
    case BasicBombGameStates::DISARMING:
       currentView = new DisarmView(changeState);
      break;
    case BasicBombGameStates::DISARMED:
      currentView = new SuccessView(changeState);
      break;
    case BasicBombGameStates::EXPLODED:
      // currentView = new ExplodedView([this](BombState newState) { changeState(newState); });
      break;
  }

  if (currentView) {
    currentView->render();
  }
}

void BasicBombGame::setTime(int _seconds, int _minutes) {
    seconds = _seconds;
    minutes = _minutes;
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
      changeState(BasicBombGameStates::EXPLODED);
    }
  }
}

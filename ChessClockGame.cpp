#include "ChessClockGame.h"

int ChessClockGame::blueTime = 0;
int ChessClockGame::redTime = 0;
unsigned long ChessClockGame::lastUpdateTime = 0;
ActiveTeam ChessClockGame::activeTeam = ActiveTeam::NONE;

ChessClockGame::ChessClockGame() {}

void ChessClockGame::begin() {
  activeTeam = ActiveTeam::NONE;
  blueTime = 0;
  redTime = 0;
  currentView = new ChessClockView();
  currentView->render();
}

void ChessClockGame::update() {
  if (currentView) {
    char key = keypad->getKey();
    currentView->handleInput(key, keypad->getKeypadState());
  }

  // Only update the time when a team is active
  if (activeTeam != ActiveTeam::NONE && millis() - lastUpdateTime >= 1000) {
    lastUpdateTime = millis();

    if (activeTeam == ActiveTeam::BLUE) {
      blueTime++;
    } else if (activeTeam == ActiveTeam::RED) {
      redTime++;
    }

    // Refresh the view only when time changes
    currentView->refresh();
  }
}

void ChessClockGame::switchTeam(ActiveTeam team) {
  if (activeTeam != team) {
    activeTeam = team;
    lastUpdateTime = millis();
    currentView->refresh();
  }
}

ActiveTeam ChessClockGame::getActiveTeam() {
  return activeTeam;
}

int ChessClockGame::getBlueTime() {
  return blueTime;
}

int ChessClockGame::getRedTime() {
  return redTime;
}

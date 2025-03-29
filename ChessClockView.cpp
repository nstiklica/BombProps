#include "ChessClockView.h"
#include <Keypad.h>

char ChessClockView::lastKey = '\0';
unsigned long ChessClockView::keyPressStartTime = 0;
ActiveTeam ChessClockView::currentActiveTeam = ActiveTeam::NONE;

ChessClockView::ChessClockView() {}

void ChessClockView::render() {
  drawInfoSection("Team possesion", ST77XX_WHITE, ST77XX_BLACK);
  drawMainSection("", ST77XX_WHITE, ST77XX_BLACK);
  // drawControlSection("Choose color key", ST77XX_WHITE, ST77XX_BLACK);
}

void ChessClockView::refresh() {
  drawInfoSection("Team possesion", ST77XX_WHITE, ST77XX_BLACK);
  drawMainSection("", ST77XX_WHITE, ST77XX_BLACK);
  // drawControlSection("Choose color key", ST77XX_WHITE, ST77XX_BLACK);
}

void ChessClockView::drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) {

  ActiveTeam activeTeam = ChessClockGame::getActiveTeam();

  if (activeTeam == ActiveTeam::NONE) {
    drawSplitMainSection();
    return;
  }

  drawActiveTeamMainSection();
}

void ChessClockView::drawInfoSection(const char* text, uint16_t textColor, uint16_t bgColor)
{
  screen->fillRect(0, 0, 160, 26, bgColor);
  screen->setTextSize(1);
  screen->setTextColor(textColor);
  screen->setCursor(5, 5);
  screen->print(infoContent);
}

void ChessClockView::drawActiveTeamMainSection() {

  char activeTeamTimeStr[6];
  ActiveTeam activeTeam = ChessClockGame::getActiveTeam();
  int16_t bgColor = 0;

  if (activeTeam == ActiveTeam::BLUE) {
    snprintf(activeTeamTimeStr, sizeof(activeTeamTimeStr), "%d", ChessClockGame::getBlueTime());
    bgColor = ST77XX_BLUE;
  }
  else if (activeTeam == ActiveTeam::RED) {
    snprintf(activeTeamTimeStr, sizeof(activeTeamTimeStr), "%d", ChessClockGame::getRedTime());
    bgColor = ST77XX_RED;
  }

  screen->setTextSize(2);
  screen->setTextColor(ST77XX_WHITE);
  screen->setCursor(10, 50);
  screen->fillRect(0, 30, 160, 112, bgColor);
  screen->print(activeTeamTimeStr);

}

void ChessClockView::drawSplitMainSection() {

  char blueTimeStr[6], redTimeStr[6];
  snprintf(blueTimeStr, sizeof(blueTimeStr), "%d", ChessClockGame::getBlueTime());
  snprintf(redTimeStr, sizeof(redTimeStr), "%d", ChessClockGame::getRedTime());

  int screenWidth = 160;
  int mainSectionY = 30;
  int mainSectionHeight = 90;
  int halfHeight = mainSectionHeight / 2;

  ActiveTeam activeTeam = ChessClockGame::getActiveTeam();

  // Top half (Red Team)
  uint16_t redBgColor = (activeTeam == ActiveTeam::RED) ? ST77XX_WHITE : ST77XX_RED;
  uint16_t redTextColor = (activeTeam == ActiveTeam::RED) ? ST77XX_RED : ST77XX_WHITE;
  screen->fillRect(0, mainSectionY, screenWidth, halfHeight, redBgColor);
  screen->setTextSize(2);
  screen->setTextColor(redTextColor);
  screen->setCursor((screenWidth - 40) / 2, mainSectionY + (halfHeight / 2) - 8);
  screen->print(redTimeStr);

  // Bottom half (Blue Team)
  uint16_t blueBgColor = (activeTeam == ActiveTeam::BLUE) ? ST77XX_WHITE : ST77XX_BLUE;
  uint16_t blueTextColor = (activeTeam == ActiveTeam::BLUE) ? ST77XX_BLUE : ST77XX_WHITE;
  screen->fillRect(0, mainSectionY + halfHeight, screenWidth, halfHeight, blueBgColor);
  screen->setTextSize(2);
  screen->setTextColor(blueTextColor);
  screen->setCursor((screenWidth - 40) / 2, mainSectionY + halfHeight + (halfHeight / 2) - 8);
  screen->print(blueTimeStr);
}

void ChessClockView::handleInput(char key,  KeyState keyboardState) {

  if(lastKey == '\0'){
    lastKey = key;
  }

  if (keyboardState == HOLD) {
    infoContent = "Taking control!";

    if (keyPressStartTime == 0) {
      keyPressStartTime = millis();
    }

    auto timePassed = millis() - keyPressStartTime;
    if (timePassed > 2500) {
      ActiveTeam team = getTeamForKey(lastKey);
      if (currentActiveTeam != team) {
        currentActiveTeam = team;
        ChessClockGame::switchTeam(currentActiveTeam);
      }
    }

  }
  else if(keyboardState == IDLE	){
    lastKey = '\0';
    keyPressStartTime = 0;
    infoContent = "";
  }
}

ActiveTeam ChessClockView::getTeamForKey(char key) {
  if (key >= '0' && key <= '9') {
    return ActiveTeam::BLUE;
  }
  else if (key == 'A' || key == 'B' || key == 'C' || key == 'D' || key == '#') {
    return ActiveTeam::RED;
  }
  return ActiveTeam::NONE;
}

#include "InitView.h"

InitView::InitView(void (*stateChangeCallback)(BasicBombGameStates))
  : BaseView(stateChangeCallback) {}

void InitView::render() {
  screen->fillScreen(ST77XX_BLACK);
  drawInfoSection("Select Mode", ST77XX_WHITE, ST77XX_BLUE);
  drawMainSection("(1) 5 mins\n----------\n(2) 30 mins", ST77XX_WHITE, ST77XX_BLACK);
  drawControlSection("Press (1) or (2)", ST77XX_WHITE, ST77XX_BLACK);
}

void InitView::drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) {
  screen->setTextSize(2);
  screen->setTextColor(textColor);
  screen->setCursor(0, 45);
  screen->print(content);
}

void InitView::handleInput(char key) {
  if (key == '1') {
    BasicBombGame::setTime(0 , 5);
    stateChangeCallback(BasicBombGameStates::ARMING);
  }
  else if (key == '2') {
    BasicBombGame::setTime(0 , 30);
    stateChangeCallback(BasicBombGameStates::ARMING);
  }
}

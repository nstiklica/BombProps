#include "ArmedView.h"

ArmedView::ArmedView(void (*stateChangeCallback)(BombState))
  : BaseView(stateChangeCallback) {}

void ArmedView::render() {
  screen->fillScreen(ST77XX_BLACK);
  drawInfoSection("Bomb Armed!", ST77XX_WHITE, ST77XX_RED);

  char timeDisplay[6];
  snprintf(timeDisplay, sizeof(timeDisplay), "%02d:%02d", BasicBombGame::minutes, BasicBombGame::seconds);
  drawMainSection(timeDisplay, ST77XX_WHITE, ST77XX_BLACK);

  drawControlSection("(D)isarm", ST77XX_WHITE, ST77XX_BLACK);
}

void ArmedView::refresh() {
  char timeDisplay[6];
  snprintf(timeDisplay, sizeof(timeDisplay), "%02d:%02d", BasicBombGame::minutes, BasicBombGame::seconds);

  drawMainSection(timeDisplay, ST77XX_WHITE, ST77XX_BLACK);
  drawControlSection("(D)isarm", ST77XX_WHITE, ST77XX_BLACK);
}

void ArmedView::handleInput(char key) {
  if (key == 'D') {
    stateChangeCallback(BombState::DISARMING);
  }
}

void ArmedView::updateCountdown() {

}

void ArmedView::drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) {
  screen->setTextSize(4);
  screen->setTextColor(textColor);
  screen->fillRect(10, 50, 140, 40, bgColor);
  screen->setCursor(10, 50);
  screen->print(content);
}

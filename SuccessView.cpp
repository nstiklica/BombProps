#include "SuccessView.h"

SuccessView::SuccessView(void (*stateChangeCallback)(BasicBombGameStates))
    : BaseView(stateChangeCallback) {}

void SuccessView::render() {
    screen->fillScreen(ST77XX_GREEN); 
    drawInfoSection("", ST77XX_WHITE, ST77XX_GREEN);
    drawMainSection("--------Disarmed--------", ST77XX_WHITE, ST77XX_GREEN);
    drawControlSection("(A) Restart", ST77XX_WHITE, ST77XX_BLACK);
}

void SuccessView::drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) {
  screen->setTextSize(3);
  screen->setTextColor(textColor);
  screen->setCursor(0, 25);
  screen->print(content);
}

void SuccessView::refresh() {
}

void SuccessView::handleInput(char key) {
    if (key == 'A') {
        stateChangeCallback(BasicBombGameStates::INIT);
    }
}

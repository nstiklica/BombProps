#include "BaseView.h"

Adafruit_ST7735* BaseView::screen = nullptr;

BaseView::BaseView(void (*stateChangeCallback)(BasicBombGameStates))
  : stateChangeCallback(stateChangeCallback) {
  if (screen == nullptr) {
    initializeScreen();
  }
}

void BaseView::initializeScreen() {
  static Adafruit_ST7735 screenInstance(10, A1, A0);

  screen = &screenInstance;
  screen->initR(INITR_BLACKTAB);
  screen->setRotation(1);
  screen->fillScreen(ST77XX_BLACK);

  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH); // Turn on backlight
}

void BaseView::drawInfoSection(const char* text, uint16_t textColor, uint16_t bgColor) {
  screen->fillRect(0, 0, 160, 26, bgColor);
  screen->setTextSize(2);
  screen->setTextColor(textColor);
  screen->setCursor(5, 5);
  screen->print(text);
}

void BaseView::drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) {
  screen->setTextSize(4);
  screen->setTextColor(textColor);
  screen->setCursor(10, 50);
  screen->fillRect(0, 30, 160, 112, bgColor);
  screen->print(content);
}

void BaseView::drawControlSection(const char* controls, uint16_t textColor, uint16_t bgColor) {
  screen->fillRect(0, 145, 160, 20, bgColor);
  screen->setTextSize(1);
  screen->setTextColor(textColor);
  screen->setCursor(5, 120);
  screen->print(controls);
}

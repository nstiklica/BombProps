#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Keypad.h>

#include "BasicBombGameStates.h"

class BaseView {
  public:
    BaseView(void (*stateChangeCallback)(BasicBombGameStates));
    BaseView();

    virtual void render() = 0;
    virtual void refresh() {};
    virtual void handleInput(char key) {};
    virtual void handleInput(char key, KeyState keyboardState) {};

  protected:
    static Adafruit_ST7735* screen;
    void (*stateChangeCallback)(BasicBombGameStates);

    virtual void drawInfoSection(const char* text, uint16_t textColor, uint16_t bgColor);
    virtual void drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor);
    void drawControlSection(const char* controls, uint16_t textColor, uint16_t bgColor);

  private:
    static void initializeScreen();
};

#endif

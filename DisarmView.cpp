#include "DisarmView.h"

DisarmView::DisarmView(void (*stateChangeCallback)(BasicBombGameStates))
    : BaseView(stateChangeCallback), codeIndex(0) {
    memset(enteredCode, 0, sizeof(enteredCode));
}

void DisarmView::render() {
    screen->fillScreen(ST77XX_BLACK); 
    updateCodeDisplay();
    drawControlSection("(B)ack (D)elete (C)ontinue", ST77XX_WHITE, ST77XX_BLACK);
    refresh();
}

void DisarmView::drawInfoSection(const char* text, uint16_t textColor, uint16_t bgColor){
  screen->fillRect(0, 0, 160, 26, bgColor);
  screen->setTextSize(2);
  screen->setTextColor(textColor);
  screen->setCursor(0, 5);
  screen->print(text);
}

void DisarmView::refresh() {
    char timeDisplay[10];
    snprintf(timeDisplay, sizeof(timeDisplay), "%02d:%02d", 
         BasicBombGame::getMinutes(), BasicBombGame::getSeconds());
    drawInfoSection(timeDisplay, ST77XX_WHITE, ST77XX_BLUE);
}

void DisarmView::handleInput(char key) {
    if (key >= '0' && key <= '9') {
        if (codeIndex < 6) {
            enteredCode[codeIndex] = key;
            codeIndex++;
            enteredCode[codeIndex] = '\0';
            updateCodeDisplay();
        }
    } else if (key == 'D') {
        if (codeIndex > 0) {
            codeIndex--;
            enteredCode[codeIndex] = '\0';
            updateCodeDisplay();
        }
    } else if (key == 'C' && codeIndex == 6) {
        if (strcmp(enteredCode, BasicBombGame::getBombCode()) == 0) {
            stateChangeCallback(BasicBombGameStates::DISARMED); 
        } else {
            drawInfoSection("Wrong Code!", ST77XX_WHITE, ST77XX_RED);
        }
    } else if (key == 'B') { 
        stateChangeCallback(BasicBombGameStates::ARMED);
    }
}

void DisarmView::updateCodeDisplay() {
    char displayCode[7];
    for (int i = 0; i < 6; i++) {
        displayCode[i] = (i < codeIndex) ? enteredCode[i] : '_';
    }
    displayCode[6] = '\0';

    drawMainSection(displayCode, ST77XX_WHITE, ST77XX_BLACK);
    drawControlSection("(B)ack (D)elete (C)ontinue", ST77XX_WHITE, ST77XX_BLACK);
}

#include "ArmingView.h"

ArmingView::ArmingView(void (*stateChangeCallback)(BasicBombGameStates), void (*codeCallback)(const char*))
    : BaseView(stateChangeCallback), codeCallback(codeCallback), codeIndex(0) {
    memset(enteredCode, 0, sizeof(enteredCode));
}

void ArmingView::render() {
    drawInfoSection("Enter Code:", ST77XX_WHITE, ST77XX_BLUE);
    drawMainSection("______", ST77XX_WHITE, ST77XX_BLACK);
    drawControlSection("(B)ack (D)elete (C)ontinue", ST77XX_WHITE, ST77XX_BLACK);
}

void ArmingView::handleInput(char key) {
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
        codeCallback(enteredCode);
        stateChangeCallback(BasicBombGameStates::ARMED);
    } else if (key == 'B') { 
        stateChangeCallback(BasicBombGameStates::INIT);
    }
}

void ArmingView::updateCodeDisplay() {
    char displayCode[7];
    for (int i = 0; i < 6; i++) {
        displayCode[i] = (i < codeIndex) ? enteredCode[i] : '_';
    }
    displayCode[6] = '\0';

    drawMainSection(displayCode, ST77XX_WHITE, ST77XX_BLACK);
    drawControlSection("(B)ack (D)elete (C)ontinue", ST77XX_WHITE, ST77XX_BLACK);
}

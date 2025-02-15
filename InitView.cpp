#include "InitView.h"

InitView::InitView(void (*stateChangeCallback)(BombState))
    : BaseView(stateChangeCallback) {}

void InitView::render() {
    drawInfoSection("To Arm Press", ST77XX_WHITE, ST77XX_BLUE);
    drawMainSection("A", ST77XX_WHITE, ST77XX_BLACK);
    drawControlSection("", ST77XX_WHITE, ST77XX_BLACK);
}

void InitView::handleInput(char key) {
    if (key == 'A') {
        stateChangeCallback(BombState::ARMING);
    }
}
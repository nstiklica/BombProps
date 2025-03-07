#ifndef DISARMVIEW_H
#define DISARMVIEW_H

#include "BaseView.h"
#include "BasicBombGame.h"

class DisarmView : public BaseView {
public:
    DisarmView(void (*stateChangeCallback)(BasicBombGameStates));

    void render() override;
    void refresh() override;
    void handleInput(char key) override;
    void drawInfoSection(const char* text, uint16_t textColor, uint16_t bgColor) override;
private:
    char enteredCode[7];
    int codeIndex;

    void updateCodeDisplay();
};

#endif
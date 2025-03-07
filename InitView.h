#ifndef INITVIEW_H
#define INITVIEW_H

#include "BaseView.h"
#include "BasicBombGame.h"

class InitView : public BaseView {
public:
    InitView(void (*stateChangeCallback)(BasicBombGameStates));

    void render() override;
    void handleInput(char key) override;

    void drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) override;
};

#endif
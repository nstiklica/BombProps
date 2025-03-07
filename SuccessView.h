#ifndef SUCCESSVIEW_H
#define SUCCESSVIEW_H

#include "BaseView.h"

class SuccessView : public BaseView {
public:
    SuccessView(void (*stateChangeCallback)(BasicBombGameStates));

    void render() override;
    void refresh() override;
    void drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) override;
    void handleInput(char key) override;
};

#endif
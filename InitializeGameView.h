#ifndef INITIALIZEGAMEVIEW_H
#define INITIALIZEGAMEVIEW_H

#include "BaseView.h"
#include "GameFactory.h"

class InitializeGameView : public BaseView {
  public:
    InitializeGameView();

    void render() override;
    void handleInput(char key) override;

    void drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) override;
};

#endif

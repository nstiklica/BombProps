#ifndef ARMEDVIEW_H
#define ARMEDVIEW_H

#include "BaseView.h"
#include "BasicBombGame.h"

class ArmedView : public BaseView {
  public:
    ArmedView(void (*stateChangeCallback)(BasicBombGameStates));

    void updateCountdown();
    void render() override;
    void refresh() override;
    void handleInput(char key) override;

    void drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) override;
  private:
};

#endif

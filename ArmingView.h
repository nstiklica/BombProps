#ifndef ARMINGVIEW_H
#define ARMINGVIEW_H

#include "BaseView.h"

class ArmingView : public BaseView {
  public:
    ArmingView(void (*stateChangeCallback)(BasicBombGameStates), void (*codeCallback)(const char*));

    void render() override;
    void handleInput(char key) override;

  private:
    char enteredCode[7];
    int codeIndex;
    void (*codeCallback)(const char*);

    void updateCodeDisplay();
};

#endif

#ifndef ARMINGVIEW_H
#define ARMINGVIEW_H

#include "BaseView.h"

class ArmingView : public BaseView{
public:
    ArmingView(void (*stateChangeCallback)(BombState), void (*codeCallback)(const char*));

    void render() override;
    void handleInput(char key) override;

    private:
    char enteredCode[7];  // Buffer for 6-digit code
    int codeIndex;
    void (*codeCallback)(const char*);  // ✅ Callback to store the code

    void updateCodeDisplay();
};

#endif

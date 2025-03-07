#ifndef BOMBGAME_H
#define BOMBGAME_H

#include "KeypadModule.h"
#include "BasicBombGameStates.h"
#include "BaseView.h"

class BombGame {
public:
    virtual void begin() = 0;
    virtual void update() = 0;

    void setKeypad(KeypadModule& keypadRef);

protected:
    static KeypadModule* keypad;
    static BaseView* currentView;
};

#endif

#ifndef BASICBOMBGAME_H
#define BASICBOMBGAME_H

#include "KeypadModule.h"
#include "BombStates.h"
#include "BaseView.h"
#include "InitView.h"
#include "ArmingView.h"

class BasicBombGame {
public:
    BasicBombGame();
    void begin();
    void update();
    static void changeState(BombState newState);
    static void setBombCode(const char* code);
    static const char* getBombCode(); 
    
private:
    static BombState currentState;
    static BaseView* currentView;
    static char bombCode[7];
    static KeypadModule* keypad;
};

#endif

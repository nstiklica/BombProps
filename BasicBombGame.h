#ifndef BASICBOMBGAME_H
#define BASICBOMBGAME_H

#include "KeypadModule.h"
#include "BombStates.h"
#include "BaseView.h"
#include "InitView.h"
#include "ArmingView.h"
#include "ArmedView.h"
#include "DisarmView.h"
#include "SuccessView.h"

class BasicBombGame {
  public:
    BasicBombGame();

    void begin();
    void update();

    static void changeState(BombState newState);
    static void updateCountdown();

    static void setBombCode(const char* code);
    static const char* getBombCode();

    static int getMinutes();
    static int getSeconds();

    //Timer
    static int minutes;
    static int seconds;
    static unsigned long lastUpdateTime;

  private:
    static BombState currentState;
    static BaseView* currentView;
    static char bombCode[7];
    static KeypadModule* keypad;

    static bool renderTime;
};

#endif

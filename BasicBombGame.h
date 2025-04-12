#ifndef BASICBOMBGAME_H
#define BASICBOMBGAME_H

#include "BombGame.h"
#include "BasicBombGameStates.h"
#include "BaseView.h"
#include "InitView.h"
#include "ArmingView.h"
#include "ArmedView.h"
#include "DisarmView.h"
#include "SuccessView.h"
#include "ExplodedView.h"

class BasicBombGame : public BombGame {
  public:
    BasicBombGame();

    void begin() override;
    void update() override;

    static void changeState(BasicBombGameStates newState);
    static void updateCountdown();

    static void setBombCode(const char* code);
    static const char* getBombCode();

    static void setTime(int _seconds, int _minutes);
    static int getMinutes();
    static int getSeconds();

    //Timer
    static int minutes;
    static int seconds;
    static unsigned long lastUpdateTime;

  private:
    static char bombCode[7];
    static bool renderTime;
    static BasicBombGameStates currentState;
};

#endif

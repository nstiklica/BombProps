#ifndef BASICBOMBGAME_H
#define BASICBOMBGAME_H

#include "BombStates.h"
#include "BaseView.h"
#include "InitView.h"

class BasicBombGame {
public:
    BasicBombGame();
    void begin();
    void update();
    static void changeState(BombState newState);

private:
    static BombState currentState;
    static BaseView* currentView;
};

#endif

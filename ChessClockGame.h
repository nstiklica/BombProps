#ifndef CHESSCLOCKGAME_H
#define CHESSCLOCKGAME_H

#include "BombGame.h"
#include "ChessClockView.h"
#include "ChessClockGameStates.h"

class ChessClockGame : public BombGame {
public:
    ChessClockGame();

    void begin() override;
    void update() override;

    static void switchTeam(ActiveTeam team);
    static ActiveTeam getActiveTeam();
    static int getBlueTime();
    static int getRedTime();

private:
    static int blueTime;
    static int redTime;
    static unsigned long lastUpdateTime;
    static ActiveTeam activeTeam;
    static unsigned long keyPressStartTime;
};

#endif

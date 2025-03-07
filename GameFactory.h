#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "BombGame.h"
#include "BasicBombGame.h"
#include "ChessClockGame.h"

enum class GameMode {
    BASIC,
    CHESS_CLOCK
};

class GameFactory {
public:
    static BombGame* createGame(GameMode mode);
};

#endif
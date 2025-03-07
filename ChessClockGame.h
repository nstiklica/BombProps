#ifndef CHESSCLOCKGAME_H
#define CHESSCLOCKGAME_H

#include "BombGame.h"

class ChessClockGame : public BombGame {
  public:
    ChessClockGame();

    void begin() override;
    void update() override;
};

#endif

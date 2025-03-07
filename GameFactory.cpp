#include "GameFactory.h"

BombGame* GameFactory::createGame(GameMode mode) {
    switch (mode) {
        case GameMode::BASIC:
            return new BasicBombGame();
        case GameMode::CHESS_CLOCK:
            return new ChessClockGame();
        default:
            return nullptr;
    }
}
#include "GameFactory.h"

BombGame* GameFactory::createGame(int gameMode) {
  if (gameMode == 1) {
    return new BasicBombGame();
  } else if (gameMode == 2) {
    return new ChessClockGame();
  }
  return nullptr;
}

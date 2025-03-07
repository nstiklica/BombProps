#include "BombGame.h"
#include "BasicBombGame.h"


BombGame* game;

void setup() {
    game = new BasicBombGame();
    game->begin();
}

void loop() {
    game->update();
}

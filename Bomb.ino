#include "BombStates.h"
#include "BasicBombGame.h"

BasicBombGame bomb;

void setup() {
    bomb.begin();
}

void loop() {
    bomb.update();
}
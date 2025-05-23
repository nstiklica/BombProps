#include "BombGame.h"
#include "BasicBombGame.h"
#include "InitializeGameView.h"

byte rowPins2[4] = {9, 6, A3, A4};
byte colPins2[4] = {5, 4, 3, 2};
KeypadModule keypad(rowPins2, colPins2);

BombGame* game;

void setup() {
 
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);

  keypad.begin();

  InitializeGameView initGameView;
  initGameView.render();
  while (game == nullptr) {

    char key = keypad.getKey();
    if (key) {
      initGameView.handleInput(key);
    }
  }

  if (game) {
    game->setKeypad(keypad);
    game->begin();
  }

}

void loop() {
  if (game) {
    game->update();
  }
}

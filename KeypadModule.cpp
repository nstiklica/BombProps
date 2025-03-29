#include "KeypadModule.h"

KeypadModule::KeypadModule(byte* rowPins, byte* colPins) {
  this->rowPins = rowPins;
  this->colPins = colPins;
  keypad = new Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
}

void KeypadModule::begin() {
  //Some initialization logic if needed
}

char KeypadModule::getKey() {
  return keypad->getKey();
}

String KeypadModule::getKeys() {
    String pressedKeys = "";
    keypad->getKeys();

    for (int i = 0; i < LIST_MAX; i++) {
        if (keypad->key[i].kstate == PRESSED) {
            pressedKeys += keypad->key[i].kchar;
        }
    }

    return pressedKeys;
}

KeyState KeypadModule::getKeypadState(){
  return keypad->getState();
}

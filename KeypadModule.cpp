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

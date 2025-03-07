#ifndef KEYPADMODULE_H
#define KEYPADMODULE_H

#include <Arduino.h>
#include <Keypad.h>

class KeypadModule {
  public:
    KeypadModule(byte* rowPins, byte* colPins);
    void begin();
    char getKey();

  private:
    static const byte ROWS = 4;
    static const byte COLS = 4;
    char keys[ROWS][COLS] = {
      {'1', '2', '3', 'A'},
      {'4', '5', '6', 'B'},
      {'7', '8', '9', 'C'},
      {'*', '0', '#', 'D'}
    };

    byte* rowPins;
    byte* colPins;
    Keypad* keypad;
};

#endif

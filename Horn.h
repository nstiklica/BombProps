#ifndef HORN_H
#define HORN_H

#include <Arduino.h>
#include "pt.h"

class Horn {

public:
    Horn(int pinNumber);

    void sound(int durationMillis); // ON for fixed duration
    void beep(int times);           // N beeps (1s ON / 1s OFF)
    void update();

private:
    int m_pinNumber;

    // For sound()
    bool m_isSounding;
    unsigned long m_soundStartTime;
    int m_soundDuration;

    // For beep()
    bool m_isBeeping;
    int m_totalBeeps;
    int m_currentBeep;
    bool m_beepStateOn;
    unsigned long m_lastBeepToggleTime;
};

#endif
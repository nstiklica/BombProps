#ifndef HORN_H
#define HORN_H

#include <Arduino.h>
#include "pt.h"

class Horn {
public:
    Horn(int pinNumber);
    void sound(int duration);
    void update();

private:
    int m_pinNumber;
    int m_duration;
    unsigned long m_soundStartTime;
    static struct pt m_hornThread;
    bool m_isActive;
};

#endif
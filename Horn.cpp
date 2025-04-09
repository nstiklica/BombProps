#include "Horn.h"

struct pt Horn::m_hornThread;

Horn::Horn(int pinNumber) {
    m_pinNumber = pinNumber;
    pinMode(m_pinNumber, OUTPUT);
    digitalWrite(m_pinNumber, LOW);
    PT_INIT(&m_hornThread);
    m_isActive = false;
}

void Horn::sound(int durationMillis) {
    m_duration = durationMillis;
    m_soundStartTime = millis();
    m_isActive = true;
}

void Horn::update() {
    if (!m_isActive) return;

    PT_BEGIN(&m_hornThread);

    digitalWrite(m_pinNumber, HIGH);
    PT_WAIT_UNTIL(&m_hornThread, millis() - m_soundStartTime >= m_duration);
    digitalWrite(m_pinNumber, LOW);

    m_isActive = false;

    PT_END(&m_hornThread);
}
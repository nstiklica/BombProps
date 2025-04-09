#include "Horn.h"

Horn::Horn(int pinNumber)
    : m_pinNumber(pinNumber),
      m_isSounding(false),
      m_isBeeping(false),
      m_currentBeep(0),
      m_beepStateOn(false)
{
    pinMode(m_pinNumber, OUTPUT);
    digitalWrite(m_pinNumber, HIGH); // start OFF (relay idle)
}

void Horn::sound(int durationMillis) {
    m_isSounding = true;
    m_soundStartTime = millis();
    m_soundDuration = durationMillis;
    digitalWrite(m_pinNumber, LOW); // ON (relay active LOW)
}

void Horn::beep(int times) {
    m_isBeeping = true;
    m_totalBeeps = times;
    m_currentBeep = 0;
    m_beepStateOn = true; // start ON immediately
    m_lastBeepToggleTime = millis();
    digitalWrite(m_pinNumber, LOW); // Relay ON immediately
}

void Horn::update() {
    unsigned long now = millis();

    if (m_isSounding) {
        if (now - m_soundStartTime >= m_soundDuration) {
            digitalWrite(m_pinNumber, HIGH); // OFF
            m_isSounding = false;
        }
    }

    if (m_isBeeping) {
        if (m_beepStateOn && now - m_lastBeepToggleTime >= 1000) {
            // Turn OFF
            digitalWrite(m_pinNumber, HIGH);
            m_beepStateOn = false;
            m_lastBeepToggleTime = now;
        }
        else if (!m_beepStateOn && now - m_lastBeepToggleTime >= 1000) {
            // Turn ON again
            m_currentBeep++;
            if (m_currentBeep >= m_totalBeeps) {
                m_isBeeping = false;
                return;
            }
            digitalWrite(m_pinNumber, LOW);
            m_beepStateOn = true;
            m_lastBeepToggleTime = now;
        }
    }
}
#ifndef BOMBSTATES_H
#define BOMBSTATES_H

enum class BombState {
    INIT,
    ARMING,
    ARMED,
    DISARMING,
    DISARMED,
    EXPLODED
};

#endif
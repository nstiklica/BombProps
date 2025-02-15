#ifndef INITVIEW_H
#define INITVIEW_H

#include "BaseView.h"

class InitView : public BaseView {
public:
    InitView(void (*stateChangeCallback)(BombState));

    void render() override;
    void handleInput(char key) override;
};

#endif
#include "BasicBombGame.h"

BombState BasicBombGame::currentState = BombState::INIT;
BaseView* BasicBombGame::currentView = nullptr;

BasicBombGame::BasicBombGame() {}

void BasicBombGame::begin() {
    // Initialize first view (InitView)
    currentView = new InitView(changeState); 
    currentView->render();
}

void BasicBombGame::update() {
    // Future: handle game updates like countdown
}

void BasicBombGame::changeState(BombState newState) {
    if(currentState == newState)

    // Delete current view and switch to the new state

    delete currentView;
    currentView = nullptr;
    currentState = newState;

    switch (newState) {
        case BombState::INIT:
            currentView = new InitView(changeState);
            break;
        case BombState::ARMING:
            // currentView = new ArmView([this](BombState newState) { changeState(newState); });
            break;
        case BombState::ARMED:
            // currentView = new ArmedView([this](BombState newState) { changeState(newState); });
            break;
        case BombState::DISARMING:
            // currentView = new DisarmView([this](BombState newState) { changeState(newState); });
            break;
        case BombState::DISARMED:
            // currentView = new DisarmedView([this](BombState newState) { changeState(newState); });
            break;
        case BombState::EXPLODED:
            // currentView = new ExplodedView([this](BombState newState) { changeState(newState); });
            break;
    }

    if (currentView) {
        currentView->render();
    }
}

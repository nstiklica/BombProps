#include "InitializeGameView.h"
#include "BombGame.h"

extern BombGame* game; 

InitializeGameView::InitializeGameView() : BaseView(){
    
}

void InitializeGameView::render(){
    drawInfoSection("Game mode:", ST77XX_WHITE, ST77XX_BLUE);
    drawMainSection("(1) plant and destroy\n------------------\n(2)chess game", ST77XX_WHITE, ST77XX_BLACK);
    drawControlSection("Press 1 or 2", ST77XX_WHITE, ST77XX_BLACK);
}

void InitializeGameView::drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) {
    screen->setTextSize(1);
    screen->setTextColor(textColor);
    screen->setCursor(0, 60);
    screen->fillRect(0, 30, 160, 112, bgColor);  // Clear section before printing
    screen->print(content);
}

void InitializeGameView::handleInput(char key){
     if (key == '1') {
        game = GameFactory::createGame(1);
    } else if (key == '2') {
        game = GameFactory::createGame(2);
    }
}
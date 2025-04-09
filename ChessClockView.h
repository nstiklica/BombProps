#ifndef CHESSCLOCKVIEW_H
#define CHESSCLOCKVIEW_H

#include "BaseView.h"
#include "ChessClockGame.h"
#include "ChessClockGameStates.h"
#include "Horn.h"

class ChessClockView : public BaseView {

    public:
        ChessClockView();

        void render() override;
        void refresh() override;
    
        void handleInput(char key, KeyState keyboardState) override;
    
    private:
        void drawMainSection(const char* content, uint16_t textColor, uint16_t bgColor) override;
        void drawInfoSection(const char* text, uint16_t textColor, uint16_t bgColor) override;

        void drawSplitMainSection();
        void drawActiveTeamMainSection();

        ActiveTeam getTeamForKey(char key);

        static char lastKey;
        static unsigned long keyPressStartTime;
        static ActiveTeam currentActiveTeam;
        String infoContent;
        Horn m_horn;
};

#endif

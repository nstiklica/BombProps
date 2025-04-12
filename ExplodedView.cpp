#include "ExplodedView.h"

ExplodedView::ExplodedView() : BaseView(), m_horn(A5)
{

}

void ExplodedView::render() {
    drawInfoSection("Game won", ST77XX_WHITE, ST77XX_BLACK);
    drawMainSection("BoOOoM", ST77XX_RED, ST77XX_WHITE);
    m_horn.sound(7000);
  }

void ExplodedView::refresh(){
    m_horn.update();
}
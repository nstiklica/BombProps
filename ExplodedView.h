#ifndef EXPLODEDVIEW_H
#define EXPLODEDVIEW_H

#include "BaseView.h"
#include "Horn.h"

class ExplodedView : public BaseView{

    public:
        ExplodedView();

        void render() override;
        void refresh() override;

    private:
        Horn m_horn;
};

#endif
#ifndef XTURTLE_H_INCLUDED
#define XTURTLE_H_INCLUDED

#include <iostream>
#include "turtle.h"
#include "point.h"


namespace logo {

    class xTurtle : public turtle{
    public:
        explicit xTurtle(const geom::point& pos, int defaultStep=20);
        explicit xTurtle(int x, int y,  int defaultStep=20);

        void backward(int step);
        void uTurn();
        void returnHome();
        void SetDefaultStep(int defaultStep);

        using turtle::forward;
        void forward();

    private:
        geom::point d_home;
        int d_defaultStep;

    };
}



#endif // XTURTLE_H_INCLUDED

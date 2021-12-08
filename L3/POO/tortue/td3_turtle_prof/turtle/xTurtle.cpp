#include <iostream>
#include "xTurtle.h"
#include "turtle.h"

namespace logo {
    xTurtle::xTurtle(const geom::point& pos, int defaultStep): turtle{pos}, d_home{pos}, d_defaultStep{defaultStep}
    {}

    xTurtle::xTurtle(int x, int y, int defaultStep): turtle{x,y}, d_home{x,y}, d_defaultStep{defaultStep}
    {}

    void xTurtle::backward(int step){
        forward(-step);
    }

    void xTurtle::uTurn(){
        turnLeft(180);
    }

    void xTurtle::returnHome(){
        setPosition(d_home);
    }


    void xTurtle::forward(){
        forward(d_defaultStep);
    }
}

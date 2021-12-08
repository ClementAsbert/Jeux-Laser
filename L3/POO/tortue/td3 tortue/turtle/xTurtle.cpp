#include <iostream>
#include "xTurtle.h"


namespace lolo {
    xTurtle::xTurtle(const geom::point& pos, int defaultStep): turtle{pos}, d_home{pos}, d_DefaultStep{defaultStep}
    {}

    xTurtle::xTurtle(int x, int y): turtle{x,y}, d_home{x,y}
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

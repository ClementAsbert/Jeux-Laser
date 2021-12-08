#include <iostream>
#include "turtle.h"
#include "graphics.h"


using namespace logo;

void moveSquare(logo::turtle& t, int side)
{
    for(int i = 0; i<4; ++i)
    {
        t.forward(side);
        t.turnLeft(90);
    }
}

void test()
{
    opengraphsize(800,800);
    logo::turtle t{200,100};
    t.turnLeft(20);
    moveSquare(t,200);
    waituntilbuttonpressed();
    closegraph();
}


int main()
{
    test();
    return 0;
}

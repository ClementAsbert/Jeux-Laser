#include <iostream>
#include "turtle.h"
#include "graphics.h"
#include "xTurtle.h"
#include "progturtle.h"


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


void moveDiamond(logo::xTurtle t, int side){
    moveSquare(t,side);
    t.uTurn();
    moveSquare(t,side);
    t.uTurn();
}


void test2()
{
    opengraphsize(800,800);
    logo::xTurtle t{300,300};
    t.turnLeft(20);
    t.forward();
    t.turnRight(100);
    moveDiamond(t, 100);
    waituntilbuttonpressed();
    closegraph();
}

void test3()
{
    opengraphsize(800,800);
    logo::turtle t{300,300};
    logo::progturtle p{"FF+FfF+F", 100,60,80};
    p.run(t);
    waituntilbuttonpressed();
    closegraph();
}



int main()
{
    test3();
    return 0;
}

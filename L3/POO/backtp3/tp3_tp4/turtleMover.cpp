#include "turtleMover.h"
#include "turtle.h"

//Forward
namespace logo{
turtleForward::turtleForward(int step) : d_step {step} {}

void turtleForward::set_step(int step)
{
    d_step = step;
}

//turnLeft

void turtleForward::manipulate(logo::turtle &t)
{
    t.forward(d_step);
}


turtleLeft::turtleLeft(int angle) : d_angle{angle} {}

void turtleLeft::set_step(int angle)
{
    d_angle = angle;
}

void turtleLeft::manipulate(logo::turtle &t)
{
    t.turnLeft(d_angle);
}


//turn Right


turtleRight::turtleRight(int angle) : d_angle{angle} {}

void turtleRight::set_step(int angle)
{
    d_angle = angle;
}

void turtleRight::manipulate(logo::turtle &t)
{
    t.turnRight(d_angle);
}

}



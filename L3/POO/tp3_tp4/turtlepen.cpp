#include "turtlepen.h"
#include "turtle.h"

namespace logo{

void turtleRaisePen::manipulate(turtle &t)
{
    t.raisePen();
}


void turtleLowerPen::manipulate(turtle &t)
{
    t.lowerPen();
}
}

#include "turtlePaint.h"
#include "turtleManipulation.h"


namespace logo{
    void turtlePaint::applyManipulation(turtleManipulation &manip)
    {
        manip->manipulate()
        d_manipulations.push_back(manip);
    }
}

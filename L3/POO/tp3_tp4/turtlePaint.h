#ifndef TURTLEPAINT_H_INCLUDED
#define TURTLEPAINT_H_INCLUDED
#include "turtleManipulation.h"
#include <vector>
#include <memory>
class turtleManipulation;
class turtle;


namespace logo{
    class turtlePaint : public turtleManipulation
    {
        void applyManipulation(turtleManipulation &manip);
    private:
        std::vector<std::unique_ptr<turtleManipulation>> d_manipulations
    };
}

#endif // TURTLEPAINT_H_INCLUDED

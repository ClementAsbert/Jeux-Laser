#ifndef TURTLEPEN_H_INCLUDED
#define TURTLEPEN_H_INCLUDED
#include "turtleManipulation.h"
class turtleManipulation;
class turtle;

namespace logo{
    class turtlepen : turtleManipulation{
    public:
        virtual ~turtlepen() = default;
    };


    class turtleRaisePen : public turtlepen
    {
    public:
        virtual void manipulate(turtle &t) override;
    };


    class turtleLowerPen : public turtlepen
    {
    public:
        virtual void manipulate(turtle &t) override;
    };
}

#endif // TURTLEPEN_H_INCLUDED

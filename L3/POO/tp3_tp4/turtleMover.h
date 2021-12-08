#ifndef TURTLEMOVER_H_INCLUDED
#define TURTLEMOVER_H_INCLUDED
#include "turtleManipulation.h"
class turtleManipulation;
class turtle;

namespace logo{

    class turtleMover : public turtleManipulation {
    public:
        virtual ~turtleMover() = default;
    };


    class turtleForward : public turtleMover{
    public:
        turtleForward(int step);
        void set_step(int step);
        virtual void manipulate(turtle &t) override;
    private:
        int d_step;
    };

    class turtleLeft : public turtleMover{
    public:
        turtleLeft(int angle);
        void set_step(int angle);
        virtual void manipulate(turtle &t) override;
    private:
        int d_angle;

    };

    class turtleRight : public turtleMover{
    public:
        turtleRight(int angle);
        void set_step(int angle);
        virtual void manipulate(turtle &t) override;
    private:
        int d_angle;

    };

}


#endif // TURTLEMOVER_H_INCLUDED

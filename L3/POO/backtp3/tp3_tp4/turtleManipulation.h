#ifndef TURTLEMANIPULATION_H_INCLUDED
#define TURTLEMANIPULATION_H_INCLUDED

namespace logo {
class turtle;
class turtleManipulation{
public:
    virtual ~turtleManipulation() = default;
    virtual void manipulate(turtle &t) = 0;
};

}


#endif // TURTLEMANIPULATION_H_INCLUDED

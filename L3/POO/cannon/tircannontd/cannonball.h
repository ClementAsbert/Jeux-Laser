#ifndef CANNONBALL_H_INCLUDED
#define CANNONBALL_H_INCLUDED
#include "point.h"
#include "vector.h"
using geom::point;
using geom::vector;

namespace cannongame{



    class cannonball{
    public:
        cannonball();
        cannonball(point p);
        cannonball(point p, vector velocity);
        point position() const;
        vector velocity() const;
        void move(double dt);
        void print(std::ostream& ost) const;
        void read(std::istream& ist);
        inline static const double G{9.81};
        inline static const vector ACCEL{0,-G} ;
    private:
        point d_p;
        vector d_v;
    };
std::ostream& operator<<(std::ostream& ost, const cannonball& c);
std::istream& operator>>(std::istream& ist, cannonball& c);
}

#endif // CANNONBALL_H_INCLUDED

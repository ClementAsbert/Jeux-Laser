
#include<iostream>
#include<cmath>
#include "cannonball.h"
#include "point.h"
#include "vector.h"
using geom::point;
using geom::vector;



namespace cannongame{



    cannonball::cannonball(): d_p{0.0,0.0}, d_v{0.0,0.0} {}
    cannonball::cannonball(point p): d_p{p}, d_v{0.0, 0.0} {}
    cannonball::cannonball(point p, vector velocity): d_p{p}, d_v{velocity} {}
    point cannonball::position() const
    {
        return d_p;
    }
    vector cannonball::velocity() const
    {
        return d_v;
    }
    void cannonball::print(std::ostream& ost) const
    {
        ost<<"[ "<<d_p<<" , "<<d_v<< " ] ";

    }
    void cannonball::read(std::istream& ist)
    {
        char c;
        point p;
        vector v;
        ist>>c>>p>>c>>v>>c;
        if(ist.good())
        {
            d_p = p;
            d_v = v;
        }
    }


    void cannonball::move(double dt){
        vector v;
        point p;

        v = d_v + (ACCEL * dt);
        p = d_p + ( v * dt);
        d_v = v;
        d_p = p;
    }

    std::ostream& operator<<(std::ostream& ost, const cannonball& c)
    {
        c.print(ost);
        return ost;
    }
    std::istream& operator>>(std::istream& ist, cannonball& c)
    {
        c.read(ist);
        return ist;
    }
}

#include<iostream>
#include<cmath>
#include "cannon.h"
#include "point.h"
#include "vector.h"
using geom::point;
using geom::vector;


namespace cannongame{
    cannon::cannon(point p, double velocity,int min, int max) : d_p{p}, d_v{velocity}, d_inclinaison{min}, d_min{min}, d_max{max}
    {

    }
    cannon::cannon(double velocity , int min = 10, int max = 60): d_p{0.0,0.0}, d_v{velocity}, d_inclinaison{min}, d_min{min}, d_max{max}
    {

    }
    point cannon::position() const
    {
        return d_p;
    }
    int cannon::inclinaison() const
    {
        return d_inclinaison;
    }


    double cannon::speed() const
    {
        return d_v;
    }

    vector cannon::speedVector() const
    {
        double distance = d_v * 1;
        double d1 = sin(theta) * distance;
        double d2 = cos(theta) * distance;
        vector v{d_p.x() + d2, d_p.y() + d1};
        return v;
    }


    void cannon::changePosition(const point& p)
    {
        d_p = p;
    }


    void cannon::raise(int n)
    {
        if(n*5<=d_max)
        {
            d_inclinaison = n*5;
        }
        else{
            std::cout<<"l'inclinaison dépassse le maximum"<<std::endl;
        }
    }

    void cannon::lower(int n)
    {
        if(n*5>=d_min)
        {
            d_inclinaison = n*5;
        }
        else{
            std::cout<<"l'inclinaison est inferieur au minimum"<<std::endl;
        }

}

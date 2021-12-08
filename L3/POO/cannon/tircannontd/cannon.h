#ifndef CANNON_H_INCLUDED
#define CANNON_H_INCLUDED
#include<iostream>
#include<cmath>
#include "cannonball.h"
#include "point.h"
#include "vector.h"
using geom::point;
using geom::vector;


namespace cannongame{
    class cannon{
        public :
            cannon(point p, double velocity,int min = 10, int max = 60);
            cannon(double velocity , int min = 10, int max = 60);
            point position() const;
            int inclinaison() const;
            double speed() const;
            vector speedVector() const;
            void changePosition(const point& p);
            void raise(int n);
            void lower(int n);
            cannonball shoot();
        private:
            int d_inclinaison;
            int d_min = 10;
            int d_max = 60;
            point d_p;
            double d_v;
    };
}


#endif // CANNON_H_INCLUDED

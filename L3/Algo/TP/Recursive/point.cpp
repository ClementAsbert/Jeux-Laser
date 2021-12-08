#include "point.h"
#include <cmath>
#include <iostream>


//constructeur
point::point(double x, double y): d_x{x}, d_y{y}
{}

//par default
point::point(): d_x{0.0}, d_y{0.0}
{}



double point::x() const{
    return d_x;
}

double point::y() const
{
    return d_y;
}



double point::setx(double x){
    d_x = x;
}
double point::sety(double y){
    d_y = y;
}


double point::distance(const point &p) const
{
    double x = pow(p.x()-d_x,2);
    double y = pow(p.y()-d_y,2);
    return sqrt(x+y);
}

void point::moveTo(double x,double y)
{
    d_x = x;
    d_y = y;
}


void point::move(double dx,double dy)
{
    d_x +=dx;
    d_y +=dy;
}

void point::print(std::ostream& ost) const{
    ost<<'('<<d_x<<','<<d_y<<')';
}


void point::read(std::istream& ist){
    char p;
    double x,y;
    ist>>p>>x>>p>>y>>p;
    if(ist.good())
    {
        d_x=x;
        d_y=y;
    }
}


std::istream& operator>>(std::istream& ist,point& p)
{
    p.read(ist);
    return ist;
}
std::ostream& operator<<(std::ostream& ost, const point& p)
{
    p.print(ost);
    return ost;
}


point point::polar(double rho, double theta)
{
    return point{rho*cos(theta), rho*sin(theta)};
}



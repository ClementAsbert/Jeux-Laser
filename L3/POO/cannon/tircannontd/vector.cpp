#include<iostream>
#include<cmath>
#include"vector.h"
#include"point.h"

namespace geom
{

vector::vector() : vector {0.0,0.0}
{}

vector::vector(double x,double y) : d_x{x}, d_y{y}
{}

vector::vector(const point& p,const point& q) :
        d_x{q.x()-p.x()}, d_y{q.y()-p.y()}
{}

double vector::x() const
{
  return d_x;
}

double vector::y() const
{
  return d_y;
}

double vector::length() const
{
  return std::sqrt(d_x*d_x + d_y*d_y);
}

void vector::change(double x, double y)
{
  d_x = x;  d_y = y;
}

vector vector::operator-() const
{
  return {-d_x,-d_y};
}

vector& vector::operator+=(const vector& v)
{
  d_x += v.d_x;
  d_y += v.d_y;
  return *this;
}

vector vector::operator+(const vector& v) const
{
  vector res{*this};
  res += v;
  return res;
}

vector& vector::operator-=(const vector& v)
{
  d_x -= v.d_x;
  d_y -= v.d_y;
  return *this;
}

vector vector::operator-(const vector& v) const
{
  vector res{*this};
  res -= v;
  return res;
}

vector& vector::operator*=(double l)
{
  d_x *= l;
  d_y *= l;
  return *this;
}

vector vector::operator*(double l) const
{
  vector res{*this};
  res *= l;
  return res;
}

vector operator*(double l, const vector& v)
{
  return v*l;
}

vector& vector::operator/=(double l)
{
  d_x /= l;
  d_y /= l;
  return *this;
}

vector vector::operator/(double l) const
{
  vector res{*this};
  res /= l;
  return res;
}

void vector::print(std::ostream& ost) const
{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void vector::read(std::istream& ist)
{
  char c;
  ist>>c;
  if (c == '(')
  {
    double x;
    ist>>x>>c;
    if (c == ',')
    {
      double y;
      ist>>y>>c;
      if (c == ')') { d_x = x; d_y = y; }
    }
  }
}

std::ostream& operator<<(std::ostream& ost, const vector& v)
{
  v.print(ost);
  return ost;
}

std::istream& operator>>(std::istream& ist, vector& v)
{
  v.read(ist);
  return ist;
}

}


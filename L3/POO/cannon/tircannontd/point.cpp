#include<iostream>
#include<cmath>
#include"point.h"
#include"vector.h"

namespace geom
{

point::point() : point {0.0,0.0}
{}

point::point(double x, double y) : d_x{x}, d_y{y}
{}

point point::cartesian(double x, double y)
{
  return {x,y};
}

point point::polar(double rho, double theta)
{
  return {rho*std::cos(theta),rho*std::sin(theta)};
}

double point::x() const
{
  return d_x;
}

double point::y() const
{
  return d_y;
}

double point::distance(const point& p) const
{
  double dx = p.d_x-d_x, dy = p.d_y-d_y;
  return std::sqrt(dx*dx + dy*dy);
}

void point::moveTo(double x, double y)
{
  d_x = x; d_y = y;
}

void point::move(double dx, double dy)
{
  d_x += dx; d_y += dy;
}

void point::move(const vector& v)
{
  move(v.x(),v.y());
}

point& point::operator*=(double val)
{
  d_x *= val; d_y *= val;
  return *this;
}

point operator*(double val, const point& p)
{
  point res{p};
  res *= val;
  return res;
}

point& point::operator/=(double val)
{
  d_x /= val; d_y /= val;
  return *this;
}

point point::operator/(double val) const
{
  point res{*this};
  res /= val;
  return res;
}

point& point::operator+=(const point& p)
{
  d_x += p.d_x; d_y += p.d_y;
  return *this;
}

point point::operator+(const point& p) const
{
  point res{*this};
  res += p;
  return res;
}

point& point::operator+=(const vector& v)
{
  move(v);
  return *this;
}

point point::operator+(const vector& v) const
{
  point res{*this};
  res += v;
  return res;
}

vector point::operator-(const point& p) const
{
  return {p,*this};
}

bool point::operator==(const point& p) const
{
  return (d_x == p.d_x) && (d_y == p.d_y);
}

bool point::operator!=(const point& p) const
{
  return (d_x != p.d_x) || (d_y != p.d_y);
}

void point::print(std::ostream& ost) const
{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void point::read(std::istream& ist)
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

std::ostream& operator<<(std::ostream& ost, const point& p)
{
  p.print(ost);
  return ost;
}

std::istream& operator>>(std::istream& ist, point& p)
{
  p.read(ist);
  return ist;
}

}

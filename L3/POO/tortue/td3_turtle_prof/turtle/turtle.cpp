#include<cmath>

#include"graphics.h"
#include"turtle.h"

namespace logo
{

const double turtle::deg2rad = 3.14159265358979/180;


turtle::turtle() : turtle{geom::point{0,0}}
{}

turtle::turtle(const geom::point& pos) :
               d_pos{pos}, d_heading{0}, d_pendown{true}
{}

turtle::turtle(int x, int y) :
               d_pos{x,y}, d_heading{0}, d_pendown{true}
{
}

turtle::~turtle()
{}


int turtle::heading() const
{
  return d_heading;
}

geom::point turtle::position() const
{
  return d_pos;
}

bool turtle::isPenUp()   const
{
  return !d_pendown;
}

bool turtle::isPenDown()   const
{
  return d_pendown;
}


void turtle::forward(int step)
{
  double alpha = deg2rad*d_heading;
  geom::point  pdest{d_pos.x()+step*std::cos(alpha),
                     d_pos.y()+step*std::sin(alpha)};
  if (d_pendown)
  {
    line(static_cast<int>(d_pos.x()),static_cast<int>(d_pos.y()),
         static_cast<int>(pdest.x()),static_cast<int>(pdest.y()));
  }
  d_pos = pdest;
}

void turtle::setPosition(const geom::point& pos)
{
  d_pos = pos;
}


void turtle::turnLeft(int angle)
{
  d_heading += angle;
}

void turtle::turnRight(int angle)
{
  d_heading -= angle;
}

void turtle::setHeading(int head)
{
  d_heading = head;
}


void turtle::raisePen()
{
  d_pendown = false;
}

void turtle::lowerPen()
{
  d_pendown = true;
}

}

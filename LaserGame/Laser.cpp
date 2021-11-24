#include "Laser.h"

Laser::Laser(int x,int y) : d_x{x}, d{y}
{}

int Laser::getX() const
{
    return d_x;
}
int Laser::getY() const
{
    return d_y;
}
char Laser::getChar() const
{
    return d_c;
}
char Laser::setChar(char c) const
{
    d_c = c;
}

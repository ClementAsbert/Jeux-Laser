#include "Mirroir.h"

Mirroir::Mirroir(int x,int y) : d_x{x}, d_y{y}
{}

int Mirroir::getX() const
{
    return d_x;
}
virtual int Mirroir::getY() const
{
    return d_y;
}
virtual char Mirroir::getChar() const
{
    return d_c
}
virtual char Mirroir:setChar(char c) const
{
    d_c = c;
}

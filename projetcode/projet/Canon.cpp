#include "Canon.h"

Canon::Canon(int x,int y) : d_x{x}, d_y{y}, d_c{'#'}
{}
int Canon::getX() const
{
    return d_x;
}

int Canon::getY() const
{
    return d_y;
}


void Canon::setX(int x)
{
    d_x = x;
}

void Canon::setY(int y)
{
    d_y=y;
}

char Canon::getChar() const
{
    return d_c;
}

void Canon::setChar(char c)
{
    d_c = c;
}


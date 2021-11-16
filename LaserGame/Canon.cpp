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

char Canon::getChar() const
{
    return d_c;
}

char Canon::setChar(char c) const
{
    d_c = c;
}


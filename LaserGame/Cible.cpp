#include 'Cible.h'

Cible::Cible(int x, int y) : d_x{x}, d_y{y}
{
}

void Cible::getX() const
{
    return d_x;
}

void Cible::getY() const
{
    return d_y;
}
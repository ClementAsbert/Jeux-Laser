#include "Cible.h"

Cible::Cible(int x, int y) : d_x{x}, d_{y}
{}

int Cible::getX() const
{
    return d_x;
}
int Cible::getY() const
{
    return d_y;
}
char Cible::getChar() const
{
    return d_c;
}
char Cible::setChar(char c) const
{
    d_c = c ;
}

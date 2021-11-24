#include "Mur.h"

Mur::Mur(int x,int y) : d_x{x}; d_y{y}, d_c{'*'}
{}

char Mur::getChar() const
{
    return d_c;
}
char Mur:setChar(char c) const
{
    d_c = c;
}

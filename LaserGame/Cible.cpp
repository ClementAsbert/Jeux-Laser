#include "Cible.h"

Cible::Cible(int x, int y): d_x{x}, d_y{y}, d_c{'@'}
{}


int Cible::getX() const {return d_x;}
int Cible::getY() const {return d_y;}
char Cible::getChar() const {return d_c;}
void Cible::setChar(char c)  {d_c = c;}

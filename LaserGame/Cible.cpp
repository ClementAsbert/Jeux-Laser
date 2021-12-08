#include "Cible.h"

Cible::Cible(int x, int y): d_x{x}, d_y{y}, d_c{'@'}
{}
Cible::Cible(): d_x{0}, d_y{0}, d_c{'@'}
{}

int Cible::getX() const {return d_x;}
int Cible::getY() const {return d_y;}
void Cible::setX(int x){d_x=x;}
void Cible::setY(int y){d_y=y;}
char Cible::getChar() const {return d_c;}
void Cible::setChar(char c)  {d_c = c;}

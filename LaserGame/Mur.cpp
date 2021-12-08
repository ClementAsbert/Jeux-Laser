#include "Mur.h"

Mur::Mur() : d_x{0}, d_y{0}, d_c{'X'}
{}

Mur::Mur(int x,int y): d_x{x}, d_y{y}, d_c{'X'}
{}

int Mur::getX() const {return d_x;}
int Mur::getY() const {return d_y;}
void Mur::setX(int x){d_x=x;}
void Mur::setY(int y){d_y=y;}
char Mur::getChar() const {return d_c;}
void Mur::setChar(char c)  {d_c = c;}

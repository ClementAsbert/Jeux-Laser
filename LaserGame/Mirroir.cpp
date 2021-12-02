#include "Mirroir.h"

Mirroir::Mirroir(int x,int y, char c): d_x{x}, d_y{y}, d_c{c}
{}


int Mirroir::getX() const {return d_x;}
int Mirroir::getY() const {return d_y;}
void Mirroir::setX(int x){d_x=x;}
void Mirroir::setY(int y){d_y=y;}
char Mirroir::getChar() const {return d_c;}
void Mirroir::setChar(char c)  {d_c=c;}

#include "Laser.h"
#include <string>
Laser::Laser(int x,int y): d_x{x}, d_y{y}, d_c{'-'}
{}


int Laser::getX() const {return d_x;}
int Laser::getY() const {return d_y;}
char Laser::getChar() const {return d_c}
void Laser::setChar(char c)  {d_c=c;}
void Laser::setDirection(string direction) {d_direction = direction;}
string Laser::getDirection() const{return d_direction;}

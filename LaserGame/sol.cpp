#include "sol.h"

sol::sol(int x, int y): d_x{x}, d_y{y}, d_c{' '}
{}
sol::sol(): d_x{0}, d_y{0}, d_c{' '}
{}

int sol::getX() const {return d_x;}
int sol::getY() const {return d_y;}
void sol::setX(int x){d_x=x;}
void sol::setY(int y){d_y=y;}
char sol::getChar() const {return d_c;}
void sol::setChar(char c)  {d_c = c;}

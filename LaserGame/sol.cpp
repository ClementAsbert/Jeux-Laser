#include "sol.h"

/**
 * @brief Construct a new sol::sol object
 * 
 * @param x 
 * @param y 
 */
sol::sol(int x, int y): d_x{x}, d_y{y}, d_c{' '}
{}

/**
 * @brief Construct a new sol::sol object
 * 
 */
sol::sol(): d_x{0}, d_y{0}, d_c{' '}
{}

/**
 * @brief return coord x
 * 
 * @return int 
 */
int sol::getX() const {return d_x;}

/**
 * @brief return coord y
 * 
 * @return int 
 */
int sol::getY() const {return d_y;}

/**
 * @brief modif coord x
 * 
 * @param x 
 */
void sol::setX(int x){d_x=x;}

/**
 * @brief modif coord y
 * 
 * @param y 
 */
void sol::setY(int y){d_y=y;}

/**
 * @brief return char
 * 
 * @return char 
 */
char sol::getChar() const {return d_c;}

/**
 * @brief modif char
 * 
 * @param c 
 */
void sol::setChar(char c)  {d_c = c;}

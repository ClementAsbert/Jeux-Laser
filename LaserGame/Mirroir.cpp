#include "Mirroir.h"

/**
 * @brief Construct a new Mirroir:: Mirroir object
 * 
 * @param x 
 * @param y 
 * @param c 
 */
Mirroir::Mirroir(int x,int y, char c): d_x{x}, d_y{y}, d_c{c}
{}

/**
 * @brief return coord x
 * 
 * @return int 
 */
int Mirroir::getX() const {return d_x;}

/**
 * @brief return coord y
 * 
 * @return int 
 */
int Mirroir::getY() const {return d_y;}

/**
 * @brief modif coord x
 * 
 * @param x 
 */
void Mirroir::setX(int x){d_x=x;}

/**
 * @brief modif coord y
 * 
 * @param y 
 */
void Mirroir::setY(int y){d_y=y;}

/**
 * @brief return char
 * 
 * @return char 
 */
char Mirroir::getChar() const {return d_c;}

/**
 * @brief modif char
 * 
 * @param c 
 */
void Mirroir::setChar(char c)  {d_c=c;}

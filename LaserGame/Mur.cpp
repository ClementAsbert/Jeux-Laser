#include "Mur.h"

/**
 * @brief Construct a new Mur:: Mur object
 * 
 */
Mur::Mur() : d_x{0}, d_y{0}, d_c{'X'}
{}

/**
 * @brief Construct a new Mur:: Mur object
 * 
 * @param x 
 * @param y 
 */
Mur::Mur(int x,int y): d_x{x}, d_y{y}, d_c{'X'}
{}

/**
 * @brief return coord x
 * 
 * @return int 
 */
int Mur::getX() const {return d_x;}

/**
 * @brief return coord y
 * 
 * @return int 
 */
int Mur::getY() const {return d_y;}

/**
 * @brief modif coord x
 * 
 * @param x 
 */
void Mur::setX(int x){d_x=x;}

/**
 * @brief modif coord y
 * 
 * @param y 
 */
void Mur::setY(int y){d_y=y;}

/**
 * @brief return char 
 * 
 * @return char 
 */
char Mur::getChar() const {return d_c;}

/**
 * @brief modif char
 * 
 * @param c 
 */
void Mur::setChar(char c)  {d_c = c;}

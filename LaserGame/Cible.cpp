#include "Cible.h"

/**
 * @brief Construct a new Cible:: Cible object
 * 
 * @param x coord x
 * @param y coord y
 */
Cible::Cible(int x, int y) : d_x{x}, d_y{y}, d_c{'@'}
{
}
/**
 * @brief Construct a new Cible:: Cible object
 * 
 */
Cible::Cible() : d_x{0}, d_y{0}, d_c{'@'}
{
}

/**
 * @brief return x coord
 * 
 * @return int 
 */
int Cible::getX() const { return d_x; }

/**
 * @brief return coord y
 * 
 * @return int 
 */
int Cible::getY() const { return d_y; }

/**
 * @brief modif coord x
 * 
 * @param x 
 */
void Cible::setX(int x) { d_x = x; }

/**
 * @brief modif coord y
 * 
 * @param y 
 */
void Cible::setY(int y) { d_y = y; }

/**
 * @brief return char 
 * 
 * @return char 
 */
char Cible::getChar() const { return d_c; }

/**
 * @brief modif char
 * 
 * @param c 
 */
void Cible::setChar(char c) { d_c = c; }

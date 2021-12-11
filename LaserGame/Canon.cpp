#include "Canon.h"

/**
 * @brief Construct a new Canon:: Canon object
 * 
 * @param x coord x
 * @param y coord y
 */
Canon::Canon(int x, int y) : d_x{x}, d_y{y}, d_c{'#'}
{
}

/**
 * @brief Construct a new Canon:: Canon object
 * 
 */
Canon::Canon() : d_x{0}, d_y{0}, d_c{'#'}
{
}

/**
 * @brief return x coord
 * 
 * @return int 
 */
int Canon::getX() const
{
    return d_x;
}

/**
 * @brief return y coord
 * 
 * @return int 
 */
int Canon::getY() const
{
    return d_y;
}

/**
 * @brief modif coord x
 * 
 * @param x 
 */
void Canon::setX(int x)
{
    d_x = x;
}

/**
 * @brief modif coord y
 * 
 * @param y 
 */
void Canon::setY(int y)
{
    d_y = y;
}

/**
 * @brief return char c 
 * 
 * @return char 
 */
char Canon::getChar() const
{
    return d_c;
}

/**
 * @brief modif char 
 * 
 * @param c 
 */
void Canon::setChar(char c)
{
    d_c = c;
}

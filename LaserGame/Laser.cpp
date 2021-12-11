#include "Laser.h"
#include <string>
/**
 * @brief Construct a new Laser:: Laser object
 * 
 * @param x 
 * @param y 
 * @param direction 
 */
Laser::Laser(int x,int y, string direction): d_x{x}, d_y{y}, d_direction{direction}
{
    if(direction == "haut"|| direction == "bas")
    {
        d_c = '|';
    }else
    {
        d_c = '-';
    }
}

/**
 * @brief Construct a new Laser:: Laser object
 * 
 */
Laser::Laser(): d_x{0}, d_y{0}, d_c{'-'}
{}

/**
 * @brief return coord x
 * 
 * @return int 
 */
int Laser::getX() const {return d_x;}

/**
 * @brief return coord y
 * 
 * @return int 
 */
int Laser::getY() const {return d_y;}

/**
 * @brief return char
 * 
 * @return char 
 */
char Laser::getChar() const {return d_c;}

/**
 * @brief modif coord x
 * 
 * @param x 
 */
void Laser::setX(int x){d_x=x;}

/**
 * @brief modif coord y
 * 
 * @param y 
 */
void Laser::setY(int y){d_y=y;}

/**
 * @brief modif char
 * 
 * @param c 
 */
void Laser::setChar(char c)  {d_c=c;}

/**
 * @brief modif direction
 * 
 * @param direction 
 */

/**
 * @brief modif direction
 * 
 * @param direction 
 */
void Laser::setDirection(string direction) {d_direction = direction;}

/**
 * @brief return direction
 * 
 * @return string 
 */
string Laser::getDirection() const{return d_direction;}

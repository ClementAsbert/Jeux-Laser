#ifndef POINT_H
#define POINT_H
#include <iostream>


class point{
public:
/**
 * @brief Construct a new point object
 *
 * @param x abscisse du point
 * @param y ordonee du point
 */
point(double x, double y);

/**
 * @brief  Default construct a new point object
 * origine
 */
point();


/**
 * @brief renvoi le coord x
 *
 * @return double
 */
double x() const;

/**
 * @brief renvoi le coord y
 *
 * @return double
 */
double y() const;


double setx(double x);
double sety(double y);

/**
 * @brief distance entre deux point
 *
 * @param p
 * @return distance
 */
double distance(const point &p) const;

/**
 deplace le point en (x,y)
 */
void moveTo(double x,double y);
/**
 deplace le point en translation de (dx,dy)
 */
void move(double dx,double dy);
/**
 affiche la point sous la forme (x,y) sur le flot de sortie ost
 */
void print(std::ostream& ost) const;
/**
 lit la point sous la forme (x,y) sur le flot de d'entrée ist
 */
void read(std::istream& ist);
static point polar(double rho, double theta);
static point cartesian(double x, double y);

private:
double d_x, d_y;
};


std::ostream& operator<<(std::ostream& ost, const point& p);
std::istream& operator>>(std::istream& ist,point& p);








#endif /* POINT_H */

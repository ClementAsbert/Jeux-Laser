#ifndef POINT_H
#define POINT_H

#include<iosfwd>

namespace geom
{

class vector;

/**
  class representing a point in the plane
*/
class point {
public:
///Default constructor: point (0,0)
  point();
/**
  Constructor with cartesian coordinates
  @param x x-coordinate
  @param y y-coordinate
*/
  point(double x, double y);
/**
  pseudo-constructor with cartesian coordinates: static function
  returning a point
  @param x x-coordinate
  @param y y-coordinate
*/
  static point cartesian(double x, double y);
/**
  pseudo-constructor with polar coordinates: static function
  returning a point
  @param rho distance from origin
  @param theta angle from the x-axis
*/
  static point polar(double rho, double theta);

///@return the x-coordinate of the point
  double x()  const;
///@return the y-coordinate of the point
  double y()  const;
/**
  Distance between two points
  @param p point to which the distance is computed
  @return the distance between the point and p
*/
  double distance(const point& p) const;
/**
  Change the coordinates of the point
  @param x the new x-coordinate
  @param y the new y-coordinate
*/
  void moveTo(double x, double y);
/**
  Move the point with a translation
  @param dx the deplacement along the x-axis
  @param dx the deplacement along the x-axis
*/
  void move(double dx, double dy);
/**
  Move the point with a translation
  @param v the deplacement vector
*/
  void move(const vector& v);

/**
  Operator *=: the coordinates of the point are multiplicated by the real
  @param val the value by which the coordinates will be multiplicated
  @return the point itself
*/
  point& operator*=(double val);
/**
  Operator /=: the coordinates of the point are divided by the real
  @param val the value by which the coordinates will be divided
  @return the point itself
*/
  point& operator/=(double val);
/**
  Operator /: the coordinates of the result point are the coordinates of the
              point divided by the real
  @param val the value by which the coordinates will be divided
  @return a point whose coordinates are the coordinates of the point
          divided by the real
*/
  point  operator/(double val) const;
/**
  Operator +=: add the (coordinates of the) point to the current point
  @param p the added point
  @return the point itself
*/
  point& operator+=(const point& p);
/**
  Operator +: the coordinates of the result point are the sum of the
              coordinates of the two points
  @param p one of the two added points
  @return a point whose coordinates are the sum of the coordinates
            of the two points
*/
  point  operator+(const point& p) const;
/**
  Operator +=: move the point with a translation
  @param v the deplacement vector
  @return the point itself
*/
  point& operator+=(const vector& v);
/**
  Operator +: the point moved with a translation
  @param v the deplacement vector
  @return a copy of the point if it were translated by v
*/
  point  operator+(const vector& v) const;
/**
  Operator -: q-p is the vector pq
  @param p the origin point
  @return the vector from the origin point to the current point
*/
  vector operator-(const point& p)   const;
/**
  Operator ==: two points are equal if their coordinates are equal
  @param p the compared point
  @return true if the x- and y-coordinates are equal
*/
  bool operator==(const point& p)   const;
/**
  Operator !=: two points are different if one of their coordinates are different
  @param p the compared point
  @return true if either the x- or y-coordinates are different
*/
  bool operator!=(const point& p)   const;
/**
  Ouput of a point: (x,y)
  @param ost the stream on which the point is written
*/
  void print(std::ostream& ost) const;
/**
  Input of a point: (x,y)
  @param ist the stream from which the point is read
*/
  void read(std::istream& ist);
private:
///Cartesian coordinates
  double d_x,d_y;
};

/**
  Operator *: the coordinates of the result point are the coordinates of the
              point multiplicated by the real
  @param val the value by which the coordinates will be multiplicated
  @param p the point
  @return a point whose coordinates are the coordinates of the point
          multiplicated by the real
*/
point  operator*(double val, const point& p);

std::ostream& operator<<(std::ostream& , const point& );
std::istream& operator>>(std::istream& , point& );

}

#endif

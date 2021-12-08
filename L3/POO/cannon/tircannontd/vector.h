#ifndef VECTOR_H
#define VECTOR_H

#include<iosfwd>

namespace geom
{

class point;

class vector {
public:
///Default constructor: null vector (0,0)
  vector();
/**
  Constructor with cartesian coordinates
  @param x x-coordinate
  @param y y-coordinate
*/
  vector(double x,double y);
/**
  Constructor with point extremities: vector pq
  @param p point
  @param q point
*/
  vector(const point& p,const point& q);
///@return the x-coordinate of the vector
  double x()         const;
///@return the y-coordinate of the vector
  double y()         const;
///@return the length of the vector
  double length()    const;
/**
  Change the coordinates of the vector
  @param x the new x-coordinate
  @param y the new y-coordinate
*/
  void change(double x, double y);
/**
  Unary operator -: vector with opposite coordinates
*/
  vector  operator-()                   const;
/**
  Operator +=: add the (coordinates of the) vector to the current vector
  @param v the added vector
  @return the vector itself
*/
  vector& operator+=(const vector& v);
/**
  Operator +: the coordinates of the result vector are the sum of the
              coordinates of the two vectors
  @param v one of the two added vectors
  @return a vector whose coordinates are the sum of the coordinates
            of the two vectors
*/
  vector  operator+(const vector& v)    const;
/**
  Operator -: the coordinates of the result vector are the difference of the
              coordinates of the two vectors
  @param v the subtracted vector
  @return a vector whose coordinates are the difference of the coordinates
            of the two vectors
*/
  vector  operator-(const vector& v)    const;
/**
  Operator -=: subtract the (coordinates of the) vector to the current vector
  @param v the subtracted vector
  @return the vector itself
*/
  vector& operator-=(const vector& v);
/**
  Operator *=: multiply the (coordinates of the) vector by a number
  @param l the number
  @return the vector itself
*/
  vector& operator*=(double l);
  vector  operator*(double )            const;
/**
  Operator /=: divide the (coordinates of the) vector by a number
  @param l the number
  @return the vector itself
*/
  vector& operator/=(double );
  vector  operator/(double )            const;
/**
  Ouput of a vector: (x,y)
  @param ost the stream on which the vector is written
*/
  void print(std::ostream& ost) const;
/**
  Input of a vector: (x,y)
  @param ist the stream from which the vector is read
*/
  void read(std::istream& ist);
private:
  double d_x,d_y;
};

/**
  Operator *: the coordinates of the result vector are the coordinates of the
              vector multiplicated by the real
  @param val the value by which the coordinates will be multiplicated
  @param v the vector
  @return a vector whose coordinates are the coordinates of the vector
          multiplicated by the real
*/
vector operator*(double val, const vector& v);

std::ostream& operator<<(std::ostream& , const vector& );
std::istream& operator>>(std::istream&, vector& );

}

#endif

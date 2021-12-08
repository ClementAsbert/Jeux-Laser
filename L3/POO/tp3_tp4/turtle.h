#ifndef TURTLE_H
#define TURTLE_H

#include"point.h"

namespace logo
{

	/**
	@doc graphic turtle a la LOGO
	*/

class turtle
{
public :
/**
  Constructor with the window used for drawing.
  The turtle is at heading 0 and position (0,0), pencil down
*/
  turtle();
/**
  Constructor with the window used for drawing and the initial position
  of the turtle. The turtle is at heading 0, pencil down.
  @param pos the initial position of the turtle.
*/
  explicit turtle(const geom::point& pos);
	///destructor
  ~turtle();

///@return the heading of the turtle in degrees
  int          heading() const;
///@return the position of the turtle
  geom::point  position()  const;
///@return true is the pen is up
  bool         isPenUp()   const;
///@return true is the pen is down
  bool         isPenDown() const;

/**
  Moves the turtle forward, if the pen is down, draws a line segment.
  @param step the length of the step
  @return the turtle itself
*/
  turtle& forward(int step);
/**
  Sets the position of the turtle, does not draw.
  @param pos the new position of the turtle
  @return the turtle itself
*/
  turtle& setPosition(const geom::point& pos);
/**
  Turns the turtle to the left.
  @param angle angle of rotation in degrees
  @return the turtle itself
*/
  turtle& turnLeft(int angle);
/**
  Turns the turtle to the Right.
  @param angle angle of rotation in degrees
  @return the turtle itself
*/
  turtle& turnRight(int angle);
/**
  Set the new heading of the turtle
  @param head the new heading in degrees
  @return the turtle itself
*/
  turtle& setHeading(int head);
/**
  Lift the pen up (no drawing)
  @return the turtle itself
*/
  turtle& raisePen();
/**
  Lift the pen down (drawing)
  @return the turtle itself
*/
  turtle& lowerPen();
///cardinal direction
  enum { east=0, north=90, west=180, south=270 };

private :
	///position
  geom::point   d_pos;
	///heading in degrees
  int     d_heading;
	///true if pen down
  bool    d_pendown;
	//for converting degrees to radians
  static const double deg2rad;
};

}

#endif

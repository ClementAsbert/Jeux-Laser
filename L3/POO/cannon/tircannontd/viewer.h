#ifndef VIEWER_H
#define VIEWER_H

namespace geom { class point; }

namespace cannongame
{

/**
  Class for visualizing the different elements of a cannon game.
*/

class viewer {
public :
/**
  Constructor with the dimensions of the scene
  @param width width of the scene
  @param height height of the scene
  @param borderx horizontal border added
  @param bordery vertical border added
*/
  viewer(int width, int height, int borderx = 20, int bordery = 20);
/**
  Destructor: close the window if it has not been closed before.
*/
  ~viewer();

/**
  Open the window
*/
  void open();
/**
  Close the window
*/
  void close();
/**
  Wait until the user click on the window with the mouse
*/
  void repeatUntilButton();
/**
  Wait for some time
  @param ms the waiting time in milliseconds
*/
  void wait(int ms = 50);

  void flush();
/**
  Clear the window.
*/
  void clear();

private :
///size of the scene
  int  d_width, d_height;
///size of the added border
  int  d_borderx, d_bordery;
///indicate if the window is open
  bool d_winopen;
/**
  Return the pixel x-coordinate in the window corresponding to
  the x-coordinate in the scene
  @param x the x-coordinate in the scene
  @return the x-coordinate in the window
*/
  int pixelx(double x) const;
/**
  Return the pixel y-coordinate in the window corresponding to
  the y-coordinate in the scene
  @param y the y-coordinate in the scene
  @return the y-coordinate in the window
*/
  int pixely(double y) const;
/**
  Draw in the window the given line segment in the scene
  @param p1 one extremity of the line segment
  @param p2 the other extremity of the line segment
*/
  void drawLine(const geom::point& p1, const geom::point& p2);
/**
  Draw in the window the given circle in the scene
  @param c center of the circle
  @param radius radius of the circle
*/
  void drawCircle(const geom::point& c, int radius);
/**
  Draw in the window the given rectangle in the scene
  @param pbottomleft the bottom left vertex of the rectangle
  @param ptopright the top right vertex of the rectangle
*/
  void drawRectangle(const geom::point& pbottomleft, const geom::point& ptopright);
};

}

#endif

#ifndef TURTLEDRAWAPPLICATION_H
#define TURTLEDRAWAPPLICATION_H

#include"turtle.h"

namespace logo
{

class turtleDrawApplication {
public:
  turtleDrawApplication();
  void run();
private:
  int menu();
  
  void forwardTurtle();
  void turnTurtleLeft();
  void turnTurtleRight();
  void raiseTurtlePen();
  void lowerTurtlePen();

  turtle d_turtle;
};

}

#endif // TURTLEDRAWAPPLICATION_H

#ifndef TURTLEDRAWAPPLICATION_H
#define TURTLEDRAWAPPLICATION_H
#include <vector>
#include <memory>
#include"turtle.h"
#include "turtleManipulation.h"
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
    void applyManipulation(std::unique_ptr<turtleManipulation> manip);
  void lowerTurtlePen();
  void reinitializeTurtle();
  void undoLastManipulation();
  void reset();
  void redoLastManipulation();
    std::vector<std::unique_ptr<turtleManipulation>> d_manipulations;
  turtle d_turtle;
};

}

#endif // TURTLEDRAWAPPLICATION_H

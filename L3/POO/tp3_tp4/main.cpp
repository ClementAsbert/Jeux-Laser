#include"turtledrawapplication.h"
#include"graphics.h"

int main()
{
  logo::turtleDrawApplication app{};
  ::opengraphsize(800,800);
  app.run();
}

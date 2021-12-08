#include<cmath>
#include"viewer.h"
#include"graphics.h"
#include"point.h"

namespace cannongame
{

viewer::viewer(int width, int height, int borderx, int bordery):
               d_width{width}, d_height{height},
               d_borderx{borderx}, d_bordery{bordery},
               d_winopen{false}
{ }

viewer::~viewer()
{
  if (d_winopen) { close(); }
}

void viewer::open()
{
  if (!d_winopen)
  {
    ::opengraphsize(d_width+2*d_borderx,d_height+2*d_bordery);
    d_winopen = true;
  }
}

void viewer::close()
{
  if (d_winopen)
  {
    ::closegraph();
    d_winopen = false;
  }
}

void viewer::repeatUntilButton()
{
  ::waituntilbuttonpressed();
}

void viewer::flush()
{
  ::kbhit();
}

void viewer::clear()
{
  ::cleardevice();
}

int viewer::pixelx(double x) const
{
  return static_cast<int>(std::round(d_borderx+x));
  //return static_cast<int>(std::round(x));
}

int viewer::pixely(double y) const
{
  return static_cast<int>(std::round(d_height-(d_bordery+y)));
  //return static_cast<int>(std::round(y));
}

void viewer::drawCircle(const geom::point& c, int radius)
{
  ::circle(pixelx(c.x()),pixely(c.y()),radius);
}

void viewer::drawLine(const geom::point& p1, const geom::point& p2)
{
  ::line(pixelx(p1.x()), pixely(p1.y()), pixelx(p2.x()), pixely(p2.y()));
}

void viewer::drawRectangle(const geom::point& pbottomleft, const geom::point& ptopright)
{
  ::rectangle(pixelx(pbottomleft.x()),pixely(ptopright.y()),
              pixelx(ptopright.x()),pixely(pbottomleft.y()) );
}


void viewer::wait(int ms)
{
  ::delay(ms);
}

}

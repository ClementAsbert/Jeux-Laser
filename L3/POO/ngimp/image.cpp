#include"image.h"

image::image(char pixel) : d_pixel{pixel}
{}

char image::pixel() const
{
  return d_pixel;
}

void image::changePixel(char pixel)
{
  d_pixel = pixel;
}


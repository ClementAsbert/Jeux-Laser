#ifndef IMAGE_H
#define IMAGE_H

class image {
public:
  image(char pixel = 'V');
  char pixel() const;
  void changePixel(char pixel);
private:
  char d_pixel;
};
#endif // IMAGE_H

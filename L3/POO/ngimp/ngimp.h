#ifndef NGIMP_H
#define NGIMP_H
#include<memory>
#include"image.h"
class transformation;
class ngimp {
public :
  ngimp();
  ~ngimp();
  void run();
private :
  int menu();
  void afficheImage();
  void transformeImage(std::unique_ptr<transformation> tr);
  void transformeImageFlou();
  void transformeImageNegatif();
  void annuleDerniereTransformation();
  void reappliquerDerniereTransformation();
  image d_img;
  image d_imgSauvegarde;
  std::unique_ptr<transformation> d_derniereTransformation;
};

#endif // NGIMP_H

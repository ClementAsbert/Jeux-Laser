#include"transformation.h"
#include"image.h"
#include<memory>

void transformationFlou::transform(image& img) const
{
  img.changePixel(img.pixel()+1);
}


void transformationNegatif::transform(image &img) const
{
    img.changePixel(img.pixel()-1);
}



void transformationIdentite::transform(image& ) const
{
}



transformationComposee::transformationComposee() : d_transformation{}
{

}
void transformationComposeeajoute(std::unique_ptr<transformation> tr)
{
    d_transformation.push_back(std::move(tr));
}


void transformationComposeeajoute::transform(image& img)const
{
    for(int i = 0; i<d_transformation.size(); ++i)
    {
        d_transformation[i]->transforme(img);
    }
}

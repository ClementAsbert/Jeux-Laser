#include<iostream>
#include"ngimp.h"
#include<memory>

#include"image.h"
#include"transformation.h"
using std::cout;
using std::cin;
using std::endl;

ngimp::ngimp() : d_img{'G'}, d_imgSauvegarde{d_img}, d_derniereTransformation{std::make_unique<transformationIdentite>()}
{}

ngimp::~ngimp()
{}

void ngimp::run()
{
  int choix = menu();
  while (choix != 6)
  {
    switch(choix)
    {
        case 1: afficheImage();
          break;
        case 2: transformeImageFlou();
          break;
        case 3: transformeImageNegatif();
          break;
        case 4: annuleDerniereTransformation();
          break;
        case 5: reappliquerDerniereTransformation();
          break;
    }
    choix = menu();
  }
}

int ngimp::menu()
{
  int choix;
  do
  {
    cout<<"voulez-vous : \n";
    cout<<" 1 afficher l'image\n";
    cout<<" 2 transformer l'image en flou\n";
    cout<<" 3 transformer l'image en negatif\n";
    cout<<" 4 Annuler la derniere transformation\n";
    cout<<" 5 re-appliquer la derniere transformation\n";
    cout<<" 6 Quiter\n";
    cout<<" votre choix : ";
    cin>>choix;
  } while (choix<1 || choix>6);
  return choix;
}

void ngimp::afficheImage()
{
  cout<<"Image : "<<d_img.pixel()<<endl;
}

void ngimp::transformeImage(std::unique_ptr<transformation> tr)
{
    d_imgSauvegarde = d_img;
    tr->transform(d_img);
    d_derniereTransformation = std::move(tr);
    afficheImage();
}

void ngimp::reappliquerDerniereTransformation()
{
    transformeImage(std::move(d_derniereTransformation));
}



void ngimp::transformeImageFlou()
{
    //transformationFlou trF{};
    auto trF{std::make_unique<transformationFlou>()};
    transformeImage(std::move(trF));//transfert le pointeur
}

void ngimp::transformeImageNegatif()
{
    //transformationNegatif trN{};
    transformeImage(std::make_unique<transformationNegatif>());
}



void ngimp::annuleDerniereTransformation()
{
    d_img = d_imgSauvegarde;
    afficheImage();
}



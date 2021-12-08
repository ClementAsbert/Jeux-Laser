#include "colisexpress.h"
#include <iostream>

colisexpress::colisexpress(double poids, double prix, int priorite):colis{poids, prix}, d_priorite{priorite}
{}

colisexpress::colisexpress(double poids,int priorite): colis{poids,prix()}, d_priorite{priorite}
{}


int colisexpress::priorite() const
{
    return d_priorite;
}
double colisexpress::prix() const
{
    return colis::prix() * d_priorite;
}

//colis ... kg ... euro priorite ... prix final ... euros
void colisexpress::affiche(std::ostream& ost) const
{
    colis::affiche(ost);
    ost<<"    ";
    ost<<"priorite  "<<d_priorite<<" prix final "<<prix()<<" euros";
}

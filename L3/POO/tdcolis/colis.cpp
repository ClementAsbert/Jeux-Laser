#include "colis.h"
#include <iostream>

colis::colis(double poids, double prix): d_poids{poids}, d_prix{prix} {}
colis::colis(double poids):d_poids{poids}, d_prix{prixBaremePoids(d_poids)} {}
double colis::poids() const { return d_poids;}
double colis::prix() const {return d_prix;}

//colis ... kg ... EUR
void colis::affiche(std::ostream &ost) const
{
    ost<<"colis "<<d_poids<<" KG "<<d_prix<<"  euros";
}
//methode de classe fonction static ne sappel pas sur un colis un sappel directement


double colis::prixBaremePoids(double poids) {
    return 10 * poids;
}

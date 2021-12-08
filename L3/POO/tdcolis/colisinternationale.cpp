#include "colisinternationale.h"
#include <string>
#include <iostream>


colisinternationale::colisinternationale(double poids, double prix, std::string pays): colis{poids, prix}, d_pays{pays}
{}


colisinternationale::colisinternationale(double poids, std::string pays): colis{poids}, d_pays{pays}
{}

std::string colisinternationale::pays()const
{
    return d_pays;
}

double colisinternationale::prix() const
{
    if(d_pays=="France")
    {
        return colis::prix() + 5;
    }else{
        return colis::prix() + 50;
    }
}


void colisinternationale::affiche(std::ostream& ost) const{
    colis::affiche(ost);
    ost<<"   pays "<<d_pays << " prix total "<<prix()<<"  euros";
}

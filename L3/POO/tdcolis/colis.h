#ifndef COLIS_H_INCLUDED
#define COLIS_H_INCLUDED
#include <iostream>
class colis{
public:
    colis(double poids, double prix);
    colis(double poids);
    virtual ~colis() = default;
    double poids() const;
    virtual double prix() const;
    //colis ... kg ... EUR
    virtual void affiche(std::ostream &ost) const;
    //methode de classe fonction static ne sappel pas sur un colis un sappel directement

    static double prixBaremePoids(double poids);
private:
    double d_poids;
    double d_prix;
};

#endif // COLIS_H_INCLUDED

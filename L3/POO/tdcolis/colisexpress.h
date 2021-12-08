#ifndef COLISEXPRESS_H_INCLUDED
#define COLISEXPRESS_H_INCLUDED

#include <iostream>
#include "colis.h"
//heriter cest utiliser donc on appel le colis.h
class colisexpress : public colis {
public:
    colisexpress(double poids, double prix, int priorite);
    colisexpress(double poids, int priorite);
    int priorite() const;
    virtual double prix() const override;

    //colis ... kg ... euro priorite ... prix final ... euros
    virtual void affiche(std::ostream& ost) const override;
private:
    int d_priorite;

};

#endif // COLISEXPRESS_H_INCLUDED

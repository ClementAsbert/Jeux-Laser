#ifndef COLISINTERNATIONALE_H_INCLUDED
#define COLISINTERNATIONALE_H_INCLUDED
#include <string>
#include <iostream>
#include "colis.h"
class colisinternationale: public colis{
    public:
        colisinternationale(double poids, double prix, std::string pays);
        colisinternationale(double poids, std::string pays);
        virtual double prix() const override;
        std::string pays() const;
        virtual void affiche(std::ostream& ost) const override;
    private:
        std::string d_pays;
};


#endif // COLISINTERNATIONALE_H_INCLUDED

#ifndef RAPPORTTEXTE_H_INCLUDED
#define RAPPORTTEXTE_H_INCLUDED

#include <iostream>
#include "rapport.h"
#include <string>

class rapportTexte: public rapport{
public:
    rapportTexte(std::string titre);
    virtual void imprimeTitre(std::ostream& ost) const override;
    virtual void imprimeEmploye(const employe& e, std::ostream& ost) const override;
private:
    std::string d_titre;
};

#endif // RAPPORTTEXTE_H_INCLUDED

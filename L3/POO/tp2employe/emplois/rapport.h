#ifndef RAPPORT_H_INCLUDED
#define RAPPORT_H_INCLUDED

#include <iostream>
class employe;
class rapport{
public:
    virtual ~rapport();
    virtual void imprimeTitre(std::ostream& ost) const = 0;
    virtual void imprimeEmploye(const employe& e, std::ostream& ost) const = 0;
};

#endif // RAPPORT_H_INCLUDED

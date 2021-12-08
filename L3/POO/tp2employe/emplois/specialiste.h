#ifndef SPECIALISTE_H_INCLUDED
#define SPECIALISTE_H_INCLUDED
#include <iostream>
#include "employe.h"
class specialiste : public employe
{
public:
    specialiste(std::string nom, double salaireMensuel, std::string specialite);
    virtual double salaireMensuel() const override;
    virtual void affiche(std::ostream& ost) const override;
private:
    std::string d_specialite;
};

#endif // SPECIALISTE_H_INCLUDED

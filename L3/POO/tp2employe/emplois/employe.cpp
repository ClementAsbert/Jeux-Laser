#include "employe.h"

employe::employe(const std::string& nom, double salaireMensuel):
                d_nom{nom}, d_salaireMensuel{salaireMensuel}
{}

std::string employe::nom() const
{
  return d_nom;
}

double employe::salaireMensuel() const
{
  return d_salaireMensuel;
}

void employe::affiche(std::ostream& ost) const
{
  ost<<"employe "<<d_nom<<' '<<d_salaireMensuel<<" mensuel";
}


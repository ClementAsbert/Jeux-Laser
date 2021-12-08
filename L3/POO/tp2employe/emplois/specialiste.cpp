#include "specialiste.h"
#include "employe.h"

specialiste::specialiste(std::string nom, double salairemensuel, std::string specialite): employe{nom,salairemensuel}, d_specialite{specialite}
{}

double specialiste::salaireMensuel() const
{
    return employe::salaireMensuel()+(employe::salaireMensuel()*0.2);
}

void specialiste::affiche(std::ostream& ost) const
{
    ost<<"specialiste "<<employe::nom()<<' '<<salaireMensuel()<<" mensuel specialite "<<d_specialite;
}

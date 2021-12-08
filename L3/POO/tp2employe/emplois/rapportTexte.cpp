#include "rapportTexte.h"
#include <iostream>
#include "employe.h"
rapportTexte::rapportTexte(std::string titre): d_titre{titre}
{}

void rapportTexte::imprimeTitre(std::ostream& ost) const
{
    ost<<d_titre<<std::endl;
}
void rapportTexte::imprimeEmploye(const employe& e, std::ostream& ost) const{
    ost<<"Employe : nom "<<e.nom()<<" employé salaire "<<e.salaireMensuel()<<" mensuel "<<std::endl;
}

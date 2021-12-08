#ifndef GESTIONNAIREEMPLOYES_H
#define GESTIONNAIREEMPLOYES_H

#include<vector>
#include <memory>
#include "employe.h"
#include "rapport.h"
#include "rapportTexte.h"
class gestionnaireEmployes {
public:
  void execute();
private:
  int choixMenu();
  void ajouteEmploye();
  void afficheEmployes() const;
  void afficheChargeMensuelleEmployes() const;
  double chargeMensuelleEmployes() const;
  void afficheRapportEmployes(const rapport& r,std::ostream& ost)const;
  //A COMPLETER
  //std::vector<std::unique_ptr<employe>> d_employes;
    std::vector<std::unique_ptr<employe>> d_employes;
    rapportTexte d_r{"super entreprise"};
};


#endif // GESTIONNAIREEMPLOYES_H

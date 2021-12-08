#ifndef GESTIONNAIREEMPLOYES_H
#define GESTIONNAIREEMPLOYES_H

#include<vector>
#include <memory>
#include "employe.h"
class gestionnaireEmployes {
public:
  void execute();
private:
  int choixMenu();
  void ajouteEmploye();
  void afficheEmployes() const;
  void afficheChargeMensuelleEmployes() const;
  double chargeMensuelleEmployes() const;
  //A COMPLETER
  //std::vector<std::unique_ptr<employe>> d_employes;
    std::vector<employe> d_employes;
};


#endif // GESTIONNAIREEMPLOYES_H

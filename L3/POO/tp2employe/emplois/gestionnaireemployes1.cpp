#include<iostream>
#include<string>
#include"gestionnaireemployes.h"

using std::cout;
using std::cin;
using std::endl;

void gestionnaireEmployes::execute()
{
  auto choix = choixMenu();
  while (choix != 4)
  {
    switch (choix)
    {
      case 1 : ajouteEmploye(); break;
      case 2 : afficheEmployes(); break;
      case 3 : afficheChargeMensuelleEmployes(); break;
    }
    choix = choixMenu();
  }
}

int gestionnaireEmployes::choixMenu()
{
  int choix {-1};
  do
  {
    cout<<"Voulez-vous :\n";
    cout<<"(1) Ajouter un employe\n";
    cout<<"(2) Afficher les employes\n";
    cout<<"(3) Afficher la charge mensuelle des employes\n";
    cout<<"(4) Quitter le programme\n";
    cout<<"Votre choix : ";
    cin>>choix;
  }
  while (choix<0 || choix >4);
  return choix;
}

void gestionnaireEmployes::ajouteEmploye()
{
  std::string nom;
  double salaire;
  cout<<"nom de l'employe : ";
  cin>>nom;
  cout<<"salaire mensuel : ";
  cin>>salaire;
  employe e{nom,salaire};
  d_employes.push_back(e);
  //CREER ET AJOUTER L'EMPLOYE CORRESPONDANT
}

void gestionnaireEmployes::afficheEmployes() const
{
  //AFFICHER pas d'employe
  //OU employes SUIVIS D'UN EMPLOYE PAR LIGNE
  if(d_employes.size() ==0)
  {
      cout<<"pas d'employe"<<endl;
  }else{
    for(int i = 0;i<d_employes.size(); i++)
    {
        d_employes[i].affiche(cout);
        cout<<endl;
    }
  }
}

void gestionnaireEmployes::afficheChargeMensuelleEmployes() const
{
  //AFFICHER LA CHARGE MENSUELLE DES EMPLOYES
  cout<< chargeMensuelleEmployes() << "  ";
}

double gestionnaireEmployes::chargeMensuelleEmployes() const
{
  //CALCULER ET RENVOYER LA SOMME DES SALAIRES MENSUELS DES EMPLOYES
  double sum=0;
  for(int i = 0; i<d_employes.size(); ++i)
  {
      sum += d_employes[i].salaireMensuel();
  }
  return sum;
}


#include "plat.h"
#include "afficheur.h"
platALaCarte::platALaCarte(std::string nom, double prix, std::string type) : d_nom{nom}, d_prix{prix}, d_type{type} {}
std::string platALaCarte::nom() const
{
    return d_nom;
}
std::string platALaCarte::type() const
{
    return d_type;
}
double platALaCarte::prix() const
{
    return d_prix;
}

void platALaCarte::afficheAvec(const afficheur& aff) const
{
    //affiche moi en tant que plat a la carte
    aff.affichePlatALaCarte(*this);
}


entree::entree(std::string nom, double prix): platALaCarte{nom,prix,"entree"}
{

}

platPrincipal::platPrincipal(std::string nom, double prix): platALaCarte{nom,prix,"platPrincipal"}
{

}


menu::menu(const entree& e, const platPrincipal& pp) : d_entree{e}, d_platPrincipal{pp} {}
menu::menu(const std::string& nomEntree, double prixEntree, const std::string& nomplatPrincipal, double prixplatPrincipal):
d_entree{nomEntree, prixEntree}, d_platPrincipal{nomplatPrincipal, prixplatPrincipal}
{}

double menu::prix() const
{
    return (d_entree.prix() + d_platPrincipal.prix()) * 0.8;
}


entree menu::entreeMenu() const
{
    return d_entree;
}
platPrincipal menu::platPrincipalMenu() const
{
    return d_platPrincipal;
}

void menu::afficheAvec(const afficheur& aff) const
{
    //affiche moi en tant que menu
    aff.afficheMenu(*this);
}


repas::repas(): d_plats{}
{

}
int repas::nombrePlats() const
{
    return d_plats.size();
}
const plat* repas::platNumero(int i) const
{
    return d_plats[i].get(); //acces à l'objet pointé
    //return *d_plats[i]
}

void repas::ajoute(std::unique_ptr<plat> p)
{
    d_plats.push_back(std::move(p));
}
double repas::prix() const
{
    double pr {0.0};
    for(const auto& p : d_plats)
    {
        pr+= p->prix();
    }
    return pr;
}

void repas::afficheAvec(const afficheur& aff) const
{
    //affiche moi en tant que repas
    aff.afficheRepas(*this);
}





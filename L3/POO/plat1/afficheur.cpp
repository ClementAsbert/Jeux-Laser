#include "afficheur.h"
#include "iostream"
#include "plat.h"
using std::cout;
using std::endl;

void afficheur::affichePlat(const plat& p) const
{
    //je demande au plat de s'afficher avec moi
    p.afficheAvec(*this);
}



void afficheurTicket::affichePlatALaCarte(const platALaCarte& p) const
{
    cout<<p.type()<<p.nom()<<p.prix()<<endl;
}
void afficheurTicket::afficheMenu(const menu& m) const
{
    cout<<"menu : "<<endl;
    affichePlatALaCarte(m.entreeMenu());
    affichePlatALaCarte(m.platPrincipalMenu());
    cout<<"prix : "<<m.prix()<<endl;

}
void afficheurTicket::afficheRepas(const repas& r) const
{
    cout<<"repas : "<<endl;
    for(int i{0}; i<r.nombrePlats(); i++)
    {
        affichePlat(*r.platNumero(i));
    }
    cout<<"prix total : "<<r.prix() <<endl;
}

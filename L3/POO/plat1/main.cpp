#include <iostream>
#include "plat.h"
#include "afficheur.h"
void test1()
{
    repas r{};
    r.ajoute(std::make_unique<entree>("salade", 5));
    r.ajoute(std::make_unique<menu>(entree{"fois gras", 10}, platPrincipal{"confis de canard", 15}));

    std::cout<<"prix du repas : " <<r.prix() <<std::endl;

}

void test2()
{
    menu m{{"fois gras", 10}, {"confis de canard", 15}};
    afficheurTicket affTicket{};
    affTicket.afficheMenu(m);
    std::cout<<std::endl;


    repas r{};
    r.ajoute(std::make_unique<entree>("salade", 5));
    r.ajoute(std::make_unique<menu>(entree{"fois gras", 10}, platPrincipal{"confis de canard", 15}));

    affTicket.afficheRepas(r);
    std::cout<<std::endl;
}


int main()
{
    test2();
}

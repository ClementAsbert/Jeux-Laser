#include <iostream>
#include "colis.h"
#include "colisexpress.h"
#include <vector>
#include <memory>
#include "colisinternationale.h"
#include "generateuretiquette.h"
#include "generateuretiquettetexte.h"
//affiche a lecran les colis du tableau de colis donc de colis et colies epxress donc on prend un pointeurs de reference
void afficheColis(const std::vector<std::unique_ptr<colis>>& tc)
{

    for(int i =0; i<tc.size(); ++i)
    {
        tc[i]->affiche(std::cout);
        std::cout<<std::endl;
    }
}

void test1()
{
    std::vector<std::unique_ptr<colis>> tc{};
    tc.push_back(std::make_unique<colis>(10,20));
    tc.push_back(std::make_unique<colisexpress>(10,20,2));
    tc.push_back(std::make_unique<colis>(50));
    afficheColis(tc);
}


void test2()
{
    std::vector<std::unique_ptr<colis>> tc{};
    tc.push_back(std::make_unique<colis>(10,20));
    tc.push_back(std::make_unique<colisexpress>(10,20,2));
    tc.push_back(std::make_unique<colis>(50));
    tc.push_back(std::make_unique<colisinternationale>(50,20,"France"));
    afficheColis(tc);
}

void genere(const colisexpress& c, const generateuretiquette& gen)
{
    gen.genereetiquettecolisexpress(c,std::cout);
}

void test3()
{
    colisexpress ce{10,20,2};
    generateuretiquettetexte gen();
    genere(ce,gen);
}

int main()
{
    test3();
}

#include <iostream>
#include "gestionnaireemployes.h"
#include "employe.h"
#include <vector>
#include <memory>

//fonctionne
void test1()
{
    gestionnaireEmployes f{};
    f.execute();
}

//fonctionne
void test2()
{
    gestionnaireEmployes f{};
    f.execute();
}

//avec modification de gestionnaire en unique ptr
//fonctionne
void test3()
{
    gestionnaireEmployes f{};
    f.execute();
}

//test 4 sur la saisie d'un employer puis d'un specialiste, l'affichage et salaire mensuel fonctionne
//fin du TP tout fonctionne

int main()
{
    test3();
}

#include "calculateur.h"



calculateur::calculateur(): d_pile{}
{

}

void calculateur::entre(double x)
{
    d_pile.push_back(x);
}

double calculateur::resultat() const
{
    return d_pile.back();
}

void calculateur::changeSigne()
{
    double x  = d_pile.back();
    d_pile.pop_back();
    d_pile.push_back(-x);
}

void calculateur::addtionne()
{
    double x  = d_pile.back();
    d_pile.pop_back();

    double y  = d_pile.back();
    d_pile.pop_back();

    d_pile.push_back(y+x);
}


void calculateur::soustrait()
{
    double x  = d_pile.back();
    d_pile.pop_back();

    double y  = d_pile.back();
    d_pile.pop_back();

    d_pile.push_back(y-x);
}

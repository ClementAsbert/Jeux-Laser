#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Terrain.h"
#include <vector>
#include "Mirroir.h"
#include <memory>
#include "Laser.h"
#include "Canon.h"
#include "Mur.h"
#include <vector>
using namespace std;

class joueur{
public:
    joueur();
    void menu();
    int start(); //lance partie
    void generate_terrain();
    void place_mirror();
    void erase_mirror();
    void reset();
    void shoot();
    char nextcharCase(Laser l) ;
    void score() const;
    void afficher() const;
    void defaite() const;
private:
    int d_score;
    Terrain d_terrain;
    Canon d_cannon;
    vector<Mirroir> d_mirroir;
    vector<Laser> d_laser;

};

#endif // JOUEUR_H_INCLUDED

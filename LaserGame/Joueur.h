#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Terrain.h"
#include <vector>
#include "Mirroir.h"
#include <memory>
#include "Laser.h"
#include "Canon.h"
using namespace std;

class joueur{
public:
    joueur();
    void menu();
    void start(); //lance partie
    void generate_terrain();
    void place_mirror();
    void erase_mirror();
    void reset();
    void shoot();
    void score() const;
    void afficher() const;
private:
    int d_score;
    Terrain d_terrain;
    Cannon d_cannon;
    Laser d_laser;
    vector<unique_ptr<Mirroir>> d_mirroir;
    vector<unique_ptr<Laser>> d_laser;

};

#endif // JOUEUR_H_INCLUDED

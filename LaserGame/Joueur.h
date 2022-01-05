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
#include <string>
using namespace std;

class joueur{
public:
    joueur();
    void menu();
    int start(); //lance partie
    void generate_terrain();
    void terrain_aleatoire();
    void place_mirror();
    void erase_mirror();
    void reset_mirror();
    void reset_terrain();
    void shoot();
    char nextcharCase(Laser l) ;
    void score() const;
    void afficher() const;
    void defaite() const;
    int number_direction(string direction) const;
    void AppliqueLaser(int x, int y, string position);
    void placeCanon(int x, int y, string position);
    void place_Laser_sl(string direction, int nb_direction);
    void place_Laser_asl(string direction, int nb_direction);
    void place_Laser_vide(string direction, int nb_direction);
    void nb_line_and_column(string filename, int &nbline, int &nbcolumn);
    Terrain read(const string& filename);
    bool save_write();
private:
    int d_score;
    Terrain d_terrain;
    Canon d_cannon;
    vector<Mirroir> d_mirroir;
    vector<Laser> d_laser;

};

#endif // JOUEUR_H_INCLUDED

#ifndef VUE_H_INCLUDED
#define VUE_H_INCLUDED
#include "Terrain.h"
class vue{
public:
    vue();
    void affichage(Terrain &terrain);
    void openOrClose(Terrain &terrain);
    void mur(int x,int y);
    void depart(int x,int y);
    void arrive(int x,int y);
    void laserVertical(int x,int y);
    void laserHorizontal(int x,int y);
    void mirroirSlash(int x,int y);
    void mirroirAntiSlash(int x,int y);

private:
    bool d_fenetreOuvert;
    int d_tailleX;
    int d_tailleY;
};

#endif // VUE_H_INCLUDED

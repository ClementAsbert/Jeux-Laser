#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include "Case.h"

class Terrain {
public :
    Terrain(int rows, int columns);
    Terrain();
    int getRows() const;
    int getColumn() const;
    void affiche() const;
    Case getCase(int row,int column) const;
    //save()
    //
private:
    int d_rows, d_columns;
    //std::unique_ptr<Case> d_cases[][];
};


#endif // TERRAIN_H_INCLUDED

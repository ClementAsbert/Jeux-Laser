#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include "Case.h"
#include <memory>
#include <vector>

class Terrain {
public :
    Terrain(int rows, int columns);
    Terrain();
    int getRows() const;
    int getColumn() const;
    int setRows(int rows) ;
    int setColumn(int columns) ;
    Case getCase(int row,int column) const;
    //Case setCase() const;
    //save()
    //
private:
    int d_rows, d_columns;
    //mettre un tableau de pointeur a deux dimensions  de case contenant tous les case du tableau
};


#endif // TERRAIN_H_INCLUDED

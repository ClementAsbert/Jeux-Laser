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
    Case getCase(int row,int column) const;
    Case setCase() const;
    //save()
    //
private:
    int d_rows, d_columns;
    std::vector<Laser> d_laser;
};


#endif // TERRAIN_H_INCLUDED

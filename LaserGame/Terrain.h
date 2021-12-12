#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include "Case.h"
#include <memory>
#include <vector>

class Terrain {
public :
    Terrain(int rows, int columns);
    Terrain();
    ~Terrain();
    int getRows() const;
    int getColumn() const;
    int setRows(int rows) ;
    int setColumn(int columns) ;
    std::unique_ptr<Case> getCase(int row,int column) ;
    char getCharCase(int row, int column) const;
    void setCase(int row,int column,std::unique_ptr<Case> d);
    void affichageTexte() const;
    void removeMirror(int x, int y);


private:
    int d_rows, d_columns;
    std::unique_ptr<Case>** tab2D;
};


#endif // TERRAIN_H_INCLUDED

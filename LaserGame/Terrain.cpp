#include "Terrain.h"
#include "Case.h"

Terrain::Terrain(int rows, int columns): d_rows{rows}, d_columns{columns}, d_laser{}
{

}


Terrain::Terrain():d_rows{0}, d_columns{0}, d_laser{}
{

}


int Terrain::getRows() const {return d_rows;}
int Terrain::getColumn() const {return d_columns;}

int Terrain::setRows(int rows) {d_rows = rows;}
int Terrain::setColumn(int columns) {d_columns = columns;}

Case Terrain::getCase(int row,int column) const { Case r{row,column}; return r; }
//Case Terrain::setCase() const;

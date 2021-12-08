#include "Terrain.h"
#include "Case.h"
#include <iostream>

Terrain::Terrain(int rows, int columns): d_rows{rows}, d_columns{columns}
{
    tab2D = new std::unique_ptr<Case>*[rows];
    for (int i = 0; i < rows; i++)
        tab2D[i] = new std::unique_ptr<Case>[columns];
}


Terrain::Terrain():d_rows{0}, d_columns{0}
{

}

Terrain::~Terrain(){
}


int Terrain::getRows() const {return d_rows;}
int Terrain::getColumn() const {return d_columns;}

int Terrain::setRows(int rows) {d_rows = rows;}
int Terrain::setColumn(int columns) {d_columns = columns;}

std::unique_ptr<Case> Terrain::getCase(int row,int column) const { return std::move(tab2D[row][column]); }

void Terrain::setCase(int row,int column,std::unique_ptr<Case> d){
    tab2D[row][column]=std::move(d);
}

void Terrain::affichageTexte() const{
    for(int i=0;i<d_rows;i++){
        for(int a=0;a<d_columns;a++){
            if(tab2D[i][a]!=nullptr)
                std::cout<<tab2D[i][a]->getChar()<<" ";
            else
                std::cout<<"  ";
        }
        std::cout<<i<<std::endl;
    }
    for(int i = 0; i < d_columns; ++i)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

void Terrain::removeMirror(int x, int y)
{
    tab2D[x][y] = nullptr;
}


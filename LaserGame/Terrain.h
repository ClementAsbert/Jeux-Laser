#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

class Terrain {
public :
    Terrain(int rows, int columns);
private: 
    int d_rows, d_columns;
    Cases d_cases;
}


#endif // TERRAIN_H_INCLUDED

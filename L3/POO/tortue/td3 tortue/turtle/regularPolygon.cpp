#include <iostream>
#include "regularPolygon.h"
#include "turtle.h"
namespace logo {

    regularPolygon::regularPolygon(int nb, int l): d_nb{nb}, d_long{l}
    {}


    int regularPolygon::nbcote() const
    {
        return d_nb;
    }
    int regularPolygon::longeur() const
    {
        return d_long;
    }

    void regularPolygon::run(turle& t)
    {
        t.lowerPen();
        int l, nb;
        regularPolygon r{l,nb};
        for(int i=0; i<r.nbcote(); ++i)
        {
            t.forward(r.longeur());
            t.turnLeft(360/r.nbcote());
        }

        t.turnLeft(360%r.nbcote());
    }

}

#ifndef REGULARPOLYGON_H_INCLUDED
#define REGULARPOLYGON_H_INCLUDED

#include <iostream>

namespace logo{
    class turtle;
    class regularPolygon{
        public :
            regularPolygon(int nb, int l);
            void run (turtle& t);
            int nbcote() const;
            int longeur() const;
        private:
            int d_nb;
            int d_long;
    };
}


#endif // REGULARPOLYGON_H_INCLUDED

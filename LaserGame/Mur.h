#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED

#include "Case.h"

class Mur : public Case{
public:
    Mur(int x,int y);
    virtual char getChar() const override;
    virtual char setChar() const override;
private:
    int d_x, d_y;
    char d_c;
};

#endif // MUR_H_INCLUDED

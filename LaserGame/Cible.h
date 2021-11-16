#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED
#include "Case.h"

class Cible : public Case{
public:
    Cible(int x, int y);
    virtual int getX() const override;
    virtual int getY() const override;
    virtual char getChar() const override;
    virtual char setChar() const override;
private:
    int d_x, d_y;
    char d_c;

};

#endif // CIBLE_H_INCLUDED

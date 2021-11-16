#ifndef MIRROIR_H_INCLUDED
#define MIRROIR_H_INCLUDED
#include "Case.h"

class Mirroir : public Case{
public:
    Mirroir(int x,int y);
    virtual int getX() const override;
    virtual int getY() const override;
    virtual char getChar() const override;
    virtual char setChar() const override;
private:
    int d_x, d_y;
    char d_c;

};

#endif // MIRROIR_H_INCLUDED

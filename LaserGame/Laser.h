#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#include "Case.h"

class Laser : public Case{
public:
    Laser(int x,int y);
    virtual int getX() const override;
    virtual int getY() const override;
    virtual char getChar() const override;
    virtual char setChar(char c) const override;
private:
    int d_x, d_y;
    char d_c;
};

#endif // LASER_H_INCLUDED

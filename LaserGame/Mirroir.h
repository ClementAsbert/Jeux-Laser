#ifndef MIRROIR_H_INCLUDED
#define MIRROIR_H_INCLUDED
#include "Case.h"

class Mirroir : public Case{
public:
    Mirroir(int x,int y, char c);
    virtual int getX() const override;
    virtual int getY() const override;
    virtual void setX(int x) override;
    virtual void setY(int y) override;
    virtual char getChar() const override;
    virtual void setChar(char c) override;
private:
    int d_x, d_y;
    char d_c;

};

#endif // MIRROIR_H_INCLUDED

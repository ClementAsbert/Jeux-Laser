#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED

#include "Case.h"

class Mur : public Case{
public:
    Mur();
    Mur(int x,int y);
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

#endif // MUR_H_INCLUDED

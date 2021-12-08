#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED
#include "Case.h"

class Cible : public Case{
public:
    Cible(int x, int y);
    Cible();
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

#endif // CIBLE_H_INCLUDED

#ifndef SOL_H_INCLUDED
#define SOL_H_INCLUDED
#include "Case.h"

class sol : public Case{
public:
    sol(int x, int y);
    sol();
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

#endif // SOL_H_INCLUDED

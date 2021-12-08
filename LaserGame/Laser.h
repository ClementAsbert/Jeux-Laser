#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#include "Case.h"
#include <string>
using namespace std;
class Laser : public Case{
public:
    Laser(int x,int y, string direction);
    virtual int getX() const override;
    virtual int getY() const override;
    virtual void setX(int x) override;
    virtual void setY(int y) override;
    virtual char getChar() const override;
    virtual void setChar(char c) override;
    void setDirection(string direction);
    string getDirection() const;
private:
    int d_x, d_y;
    char d_c;
    string d_direction;
};

#endif // LASER_H_INCLUDED

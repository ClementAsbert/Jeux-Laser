#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

class Case{
public:
    virtual ~Case();
    virtual int getX() const =0;
    virtual int getY() const =0;
    virtual void setX(int x)  =0;
    virtual void setY(int y)  =0;
    virtual char getChar() const =0;
    virtual void setChar(char c) =0;
};

#endif // CASE_H_INCLUDED

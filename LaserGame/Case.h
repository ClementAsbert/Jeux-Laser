#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

class Case{
public:
    virtual ~Case();
    virtual int getX() const =0;
    virtual int getY() const =0;
    virtual char getChar() const =0;
    virtual char setChar() const =0;
};

#endif // CASE_H_INCLUDED

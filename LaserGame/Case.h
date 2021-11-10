#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

class Case{
public:
    virtual ~Case();
    virtual int getX() const;
    virtual int getY() const;
    virtual char getChar() const;
private:
    int d_x, d_y;
    char d_c;
};

#endif // CASE_H_INCLUDED

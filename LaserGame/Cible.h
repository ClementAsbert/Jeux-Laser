#ifndef CIBLE_H_INCLUDED
#define CIBLE_H_INCLUDED

class Cible
{
public:
    Cible(int x, int y);
    void getX() const;
    void getY() const;

private:
    int d_x, d_y;
}

#endif // CIBLE_H_INCLUDED

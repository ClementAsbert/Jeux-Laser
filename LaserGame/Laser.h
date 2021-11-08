#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED

class Laser
{
public:
    void getX() const;
    void getY() const;

private:
    int d_x, d_y;
}

#endif // LASER_H_INCLUDED

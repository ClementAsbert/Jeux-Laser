#include <iostream>
#include <cmath>
#include "graphics.h"
#include "point.h"

using namespace std;

void koch(point p1, point p2, int n)
{
    if(n == 0){
        line(p1.x(),p1.y(),p2.x(),p2.y());
    }else{
        point p3, p4, p5;
        int x,y;
        x = (2*p1.x() + p2.x())/3;
        y = (2*p1.y() + p2.y())/3;
        p3.setx(x);
        p3.sety(y);

        x = ((p1.x() + p2.x())/2)-(1/(2*sqrt(3))) * (p2.y() - p1.y());
        y = ((p1.y() + p2.y())/2)+(1/(2*sqrt(3)))* (p2.x() - p1.x());

        p4.setx(x);
        p4.sety(y);

        x = (p1.x() + 2*p2.x())/3;
        y = (p1.y() + 2*p2.y())/3;

        p5.setx(x);
        p5.sety(y);

        koch(p1, p3, n-1);
        koch(p3, p4, n-1);
        koch(p4, p5, n-1);
        koch(p5, p2, n-1);
    }
}


void triangle()//fonctionne
{
    cout << "Hello world!" <<endl;
    opengraphsize(1800,900);
    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);
    point A{250,250};
    point B{350,250};
    point C{250,350};
    int n = 2;
    koch(A,B,n);
    koch(A,C,n);
    koch(B,C,n);
    getch();
    closegraph();
}



void arbre(point p1, point p2, int n, int k , double theta)
{
    if(n == 0){
        line(p1.x(),p1.y(),p2.x(),p2.y());
    }else{
        line(p1.x(),p1.y(),p2.x(),p2.y());
        point p3, p4;
        int x,y;
        x = p2.x()+(p2.x()-p1.x())*(cos(theta)/k)-(p2.y() -p1.y())*(sin(theta)/k);
        y = p2.y()+(p2.y()-p1.y())*(cos(theta)/k)+(p2.x() -p1.x())*(sin(theta)/k);
        p3.setx(x);
        p3.sety(y);

        x = p2.x()+(p2.x()-p1.x())*(cos(theta)/k)+(p2.y()-p1.y())*(sin(theta)/k);
        y = p2.y()+(p2.y()-p1.y())*(cos(theta)/k)-(p2.x()-p1.x())*(sin(theta)/k);

        p4.setx(x);
        p4.sety(y);

        arbre(p2,p3,n-1, k, theta);
        arbre(p2,p4,n-1, k, theta);
    }
}


void arbretest()
{
    opengraphsize(1800,900);
    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);
    point A{400,400};
    point B{400,300};
    int n = 2;
    arbre(A,B,n,3,0.69);
    getch();
    closegraph();
}


int main()
{
    arbretest();
}

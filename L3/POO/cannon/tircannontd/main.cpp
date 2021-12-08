#include <iostream>
#include <cmath>
#include "point.h"
#include "vector.h"
#include "cannonball.h"

using cannongame::cannonball;

//fonctionne
void TestBouletConstructeur(){
    geom::vector v;
    geom::point p;
    std::cout<<"donner la position " <<std::endl;
    std::cin>>p;
    std::cout<<"donner le vecteur vitesse " <<std::endl;
    std::cin>>v;
    cannonball c{p,v};
    std::cout<<"voici la position: "<<c.position()<<" voici le vecteur vitesse :  "<< c.velocity()<<std::endl;
}



void test()
{
    cannonball c{};
    std::cout<<c<<std::endl;
}

//fonctionne
void testBouletES()
{
    std::cout<<"donner le cannonball : "<<std::endl;
    cannonball c;
    std::cin>>c;
    std::cout<<"voici le cannon game : "<<c<<std::endl;
}

//fonctionne
void testmove(){
    std::cout<<"donner le cannonball : "<<std::endl;
    cannonball c;
    std::cin>>c;
    std::cout<<"voici le cannon game : "<<c<<std::endl;

    c.move(17.0);

    std::cout<<"voici le cannon game apres : "<<c<<std::endl;
}

//fonctionnes
void testFall()
{
    std::cout<<"donner une hauteur de chute "<<std::endl;
    double h;
    std::cin>>h;
    double hbis = h;

    std::cout<<"donner un pas de simulation " <<std::endl;
    double dt;
    std::cin>>dt;

    point p{1,h};
    vector v{0.0,0.0};
    int compteur = 0;
    cannonball c{p,v};

    while(c.position().y()>0)
    {
        std::cout<<"current hight : "<<h<<std::endl;
        c.move(dt);
        compteur++;
    }


    std::cout<<"le temps mis est  : "<< compteur * dt <<std::endl;
    std::cout<<"le temps precis est   : "<< std::sqrt((2*hbis)/cannonball::G)  <<std::endl;
}

int main()
{
    std::cout << "Hello world!" << std::endl;
    TestBouletConstructeur();
    return 0;
}

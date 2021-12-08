#include "joueur.h"
#include "Terrain.h"
#include "Mirroir.h"
#include "Canon.h"
#include "Cible.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

joueur::joueur():d_score{0},d_terrain{},d_cannon{},d_mirroir{},d_laser{}
{}

void joueur::menu()
{
    bool goOn = true;
    while (goOn)
    {
        int choice {start()};
        switch(choice)
        {
            case 1 : generate_terrain(); break;
            case 2 : shoot(); break;
            case 3 : afficher(); break;
            case 4 : place_mirror(); break;
            case 5 : erase_mirror(); break;
            case 6 : reset(); break;
            default: goOn = false;
        }
    }
}

int joueur::start() //lance partie
{
    int choice;
    do
    {
        cout<<"LASER GAME"<<'\n'<<'\n';
        cout<<"(1) Generer un terrain"<<'\n';
        cout<<"(2) Lancer une partie"<<'\n';
        cout<<"(3) Afficher une partie"<<'\n';
        cout<<"(4) Placer mirroir"<<'\n';
        cout<<"(5) Effacer mirroir (dernier mirroir)"<<'\n';
        cout<<"(6) Reset"<<endl;
        cout<<"(7) Quitter la partie"<<endl;
        cout<<endl<<"votre choix : ";
        cin>>choice;
    }
    while (choice<1 || choice>7);
    return choice;
}

void joueur::generate_terrain()
{
    int x,y;
    cout<<"donner la taille du terrain en premier x et y : "<<endl;
    cin>>x>>y;

    d_terrain=Terrain(x,y);
    srand(time(0));
    int rx=rand()%x;
    int ry;
    if(rx!=0 && rx!=x-1)
        ry=rand()%2*(y-1);
    else
        ry=rand()%(y-2)+1;
    d_cannon.setX(rx);
    d_cannon.setY(ry);
    for(int i=0;i<x;i++){
        d_terrain.setCase(i,0,make_unique<Mur>());
        d_terrain.setCase(i,y-1,make_unique<Mur>());
    }

    for(int i=0;i<y;i++){
        d_terrain.setCase(0,i,make_unique<Mur>());
        d_terrain.setCase(x-1,i,make_unique<Mur>());
    }
    d_terrain.setCase(rx,ry,make_unique<Canon>());

    if(ry==0){
        rx=rand()%(x-2)+1;
        d_terrain.setCase(rx,y-1,make_unique<Cible>());
    }
    else if(ry==y-1){
        rx=rand()%(x-2)+1;
        d_terrain.setCase(rx,0,make_unique<Cible>());
    }
    else if(rx==0){
        ry=rand()%(y-2)+1;
        d_terrain.setCase(x-1,ry,make_unique<Cible>());
    }
    else{
        ry=rand()%(y-2)+1;
        d_terrain.setCase(0,ry,make_unique<Cible>());
    }
}


void joueur::place_mirror()
{
    int x,y;
    int num;
    char c;
    //NIVEAU MOYEN 4 MIRROIR
    for(int i = 0; i<4; i++)
    {
        cout<<"donner les coords du mirroir numero : "<<i+1<<" avec x et y  puis le type de mirroir (/(0) ou \\(1) ): ";
        cin>>x>>y;
        cin>>num;
        while(num != 0 && num !=1)
        {
            cout<<"donner un mirroir du type (/(0) ou \\(1) ): ";
            cin>>num;
        }

        while(d_terrain.getCase(x,y) != nullptr)
        {
            cout<<"redonner correctement le placement du mirroir : ";
            cin>>x>>y;
        }

        if(num == 0)
        {
            c='/';
            d_terrain.setCase(x,y,make_unique<Mirroir>(x,y,c));
            Mirroir m{x,y,c};
            d_mirroir.push_back(m);
        }
        else
        {
            c='\\';
            d_terrain.setCase(x,y,make_unique<Mirroir>(x,y,c));
            Mirroir m{x,y,c};
            d_mirroir.push_back(m);
        }
    }
}

//erase last mirror
void joueur::erase_mirror()
{
    cout<<"efface le dernier mirroir ... :"<<endl;
    int x = d_mirroir.back().getX();
    int y = d_mirroir.back().getY();
    d_terrain.removeMirror(x,y);
    d_mirroir.pop_back();
}

void joueur::reset()
{
    for(int i = 0;i<d_mirroir.size(); i++)
    {
        int x = d_mirroir[i].getX();
        int y = d_mirroir[i].getY();
        d_terrain.removeMirror(x,y);
    }

}


//je donne les coord du laser renvoi
char joueur::nextcharCase() const
{
    auto l=d_laser.back();
    if(l.getDirection() == "droite")
    {
        return d_terrain.getCase(l.getX(),l.getY()+1)->getChar();
    }

    if(l.getDirection() == "gauche")
    {
        return d_terrain.getCase(l.getX(),l.getY()-1)->getChar();
    }

    if(l.getDirection() == "haut")
    {
        return d_terrain.getCase(l.getX()+1,l.getY())->getChar();
    }

    if(l.getDirection() == "bas")
    {
        return d_terrain.getCase(l.getX()-1,l.getY())->getChar();
    }
}


void joueur::shoot()
{
    //direction debut
    if(d_cannon.getY() == 1)
    {
        d_laser.push_back({d_cannon.getX(),d_cannon.getY()+1, "droite"});
    }

    if(d_cannon.getY() == d_terrain.getColumn())
    {
        d_laser.push_back({d_cannon.getX(),d_cannon.getY()-1, "gauche"});
    }

    if(d_cannon.getX() == 1)
    {
        d_laser.push_back({d_cannon.getX()+1,d_cannon.getY(), "bas"});
    }

    if(d_cannon.getX() == d_terrain.getRows())
    {
        d_laser.push_back({d_cannon.getX()-1,d_cannon.getY(), "haut"});
    }

    //mettre les lasers dans le tableau
    //tant que il ne rencontre pas un mur et le cible
    //mur = X
    bool test = true;
    while(test)
    {
        if(nextcharCase() == 'X')
        {
            //faire fonctione defaite
            cout<<"defaite"<<endl;
            test=false;
        }
        //mirroir /

        //correct
        if(nextcharCase() == '/' && d_laser.back().getDirection() == "haut")
        {
            //si direction == haut alors viens du bas
            //envoi vers droite
            d_laser.push_back({d_laser.back().getX()-1, d_laser.back().getY()+1, "droite"});
        }

        //correct
        if(nextcharCase() == '/' && d_laser.back().getDirection() == "droite")
        {
            //si direction == droite  alors viens de gauche
            //envoi vers bas
            d_laser.push_back({d_laser.back().getX()-1, d_laser.back().getY()+1, "haut"});
        }

        //corrrect
        if(nextcharCase() == '/' && d_laser.back().getDirection() == "gauche")
        {
            //si direction == gauche il vient de droite
            //envoi vers gauche
            d_laser.push_back({d_laser.back().getX()+1, d_laser.back().getY()-1, "bas"});
        }

        //correct
        if(nextcharCase() == '/' && d_laser.back().getDirection() == "bas")
        {
            //si direction == haut viens de bas
            //envoi vers gauche
            d_laser.push_back({d_laser.back().getX()+1, d_laser.back().getY()-1, "gauche"});
        }


        //mirroir \

        //correct
        if(nextcharCase() == '\\' && d_laser.back().getDirection() == "haut")
        {
            //si direction == haut alors viens du bas
            //envoi vers gauche
            d_laser.push_back({d_laser.back().getX()-1, d_laser.back().getY()-1, "gauche"});
        }

        //correct
        if(nextcharCase() == '\\' && d_laser.back().getDirection() == "droite")
        {
            //si direction == droite  alors viens de gauche
            //envoi vers bas
            d_laser.push_back({d_laser.back().getX()+1, d_laser.back().getY()+1, "bas"});
        }

        //correct
        if(nextcharCase() == '\\' && d_laser.back().getDirection() == "gauche")
        {
            //si direction == gauche il vient de droite
            //envoi vers gauche
            d_laser.push_back({d_laser.back().getX()-1, d_laser.back().getY()+1, "haut"});
        }

        //correct
        if(nextcharCase() == '\\' && d_laser.back().getDirection() == "bas")
        {
            //si direction == haut viens de bas
            //envoi vers gauche
            d_laser.push_back({d_laser.back().getX()+1, d_laser.back().getY()+1, "droite"});
        }

        //cible = @
        if(nextcharCase() == '@')
        {
            //faire fonctione victoire
            cout<<"victoire"<<endl;
            d_score += 10;
            test=false;
        }

        //normal case vide
        if(nextcharCase() == ' ')
        {
            if(d_laser.back().getDirection() == "haut")
            {
                d_laser.push_back({d_laser.back().getX()-1, d_laser.back().getY(), "haut"});
            }

            if(d_laser.back().getDirection() == "bas")
            {
                d_laser.push_back({d_laser.back().getX()+1, d_laser.back().getY(), "bas"});
            }

            if(d_laser.back().getDirection() == "droite")
            {
                d_laser.push_back({d_laser.back().getX(), d_laser.back().getY()+1, "droite"});
            }

            if(d_laser.back().getDirection() == "gauche")
            {
                d_laser.push_back({d_laser.back().getX(), d_laser.back().getY()-1, "gauche"});
            }

        }


    }
    //le dire de changer de direction quand la case suivante est different de ""

}
void joueur::score() const
{

}

void joueur::afficher() const
{
    d_terrain.affichageTexte();
}

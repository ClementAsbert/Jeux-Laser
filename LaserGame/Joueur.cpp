#include "joueur.h"
#include "Terrain.h"
#include "Mirroir.h"
#include "Canon.h"
using namespace std;

joueur::joueur() {}

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
        cout<<"(1) Générer un terrain"<<'\n';
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
    d_terrain.setRows(x);
    d_terrain.setColumn(y);
    d_cannon.setX(10);
    d_cannon.setY(1);
    menu();
}


void joueur::place_mirror()
{
    int x,y;
    char c;
    //NIVEAU MOYEN 4 MIRROIR
    for(int i = 0; i<4; i++)
    {
        cout<<"donner les coords du mirroir n°"<<i+1<<" avec x et y  puis le type de mirroir (/ ou \ ): ";
        cin>>x>>y;
        cin>>c;
        while(c != "/" || c!="\")
        {
            cout<<"donner un mirroir du type (/ ou \ ): ";
            cin>>c;
        }

        while(d_terrain.getCase(x,y) != "")
        {
            cout<<"redonner correctement le placement du mirroir : ";
            cin>>x>>y;
        }

        d_mirroir.push_back(make_unique<Mirroir> (x,y,c))
    }
    menu();
}

//erase last mirror
void joueur::erase_mirror()
{
    cout<<"efface le dernier mirroir ... :"<<endl;
    d_mirroir.pop_back();
    menu();
}

void joueur::reset()
{
    d_mirroir.clear();
}
void joueur::shoot()
{
    //direction debut
    if(d_cannon.getY() == 1)
    {
        d_laser.setDirection("droite");
    }

    if(d_cannon.getY() == d_terrain.getColumn())
    {
        d_laser.setDirection("gauche");
    }

    if(d_cannon.getX() == 1)
    {
        d_laser.setDirection("bas");
    }

    if(d_cannon.getX() == d_terrain.getRows())
    {
        d_laser.setDirection("haut");
    }

    //mettre les lasers dans le tableau
    while()
    //le dire de changer de direction quand la case suivante est different de ""

}
void joueur::score() const
{

}

void joueur::afficher()
{

}

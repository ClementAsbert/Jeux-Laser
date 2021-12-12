#include "joueur.h"
#include "Terrain.h"
#include "Mirroir.h"
#include "Canon.h"
#include "Cible.h"
#include "sol.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

/**
 * @brief Construct a new joueur::joueur object
 *
 */
joueur::joueur() : d_score{0}, d_terrain{}, d_cannon{}, d_mirroir{}, d_laser{}
{
}

/**
 * @brief menu du jeux
 *
 */
void joueur::menu()
{
    bool goOn = true;
    while (goOn)
    {
        int choice{start()};
        switch (choice)
        {
        case 1:
            generate_terrain();
            break;
        case 2:
            shoot();
            break;
        case 3:
            afficher();
            break;
        case 4:
            place_mirror();
            break;
        case 5:
            erase_mirror();
            break;
        case 6:
            reset();
            break;
        case 7:
            read();
            break;
        case 8:
            save_write();
            break;
        default:
            goOn = false;
        }
    }
}

/**
 * @brief start game
 *
 * @return int
 */
int joueur::start() //lance partie
{
    cout << endl;
    int choice;
    do
    {
        cout << "LASER GAME" << '\n'
             << '\n';
        cout << "(1) Generer un terrain" << '\n';
        cout << "(2) Lancer une partie" << '\n';
        cout << "(3) Afficher une partie" << '\n';
        cout << "(4) Placer mirroir" << '\n';
        cout << "(5) Effacer mirroir (dernier mirroir)" << '\n';
        cout << "(6) Reset" << endl;
        cout << "(7) Charger un Terrain a partir d un fichier" << endl;
        cout << "(8) Sauvegarder un terrain" << endl;
        cout << "(9) Quitter la partie" << endl;
        cout << endl
             << "votre choix : ";
        cin >> choice;
    } while (choice < 1 || choice > 9);
    return choice;
}

/**
 * @brief generate terrain
 *
 */
void joueur::generate_terrain()
{
    int x, y;
    cout << "donner la taille du terrain en premier x et y : " << endl;
    cin >> x >> y;

    d_terrain = Terrain(x, y);

    //placement aleatoire de cible et cannon
    srand(time(0));
    int rx = rand() % x;
    int ry;
    if (rx != 0 && rx != x - 1)
        ry = rand() % 2 * (y - 1);
    else
        ry = rand() % (y - 2) + 1;
    d_cannon.setX(rx);
    d_cannon.setY(ry);

    //ajouts des murs
    for (int i = 0; i < x; i++)
    {
        d_terrain.setCase(i, 0, make_unique<Mur>(i, 0));
        d_terrain.setCase(i, y - 1, make_unique<Mur>(i, y - 1));
    }

    //ajout des murs
    for (int i = 0; i < y; i++)
    {
        d_terrain.setCase(0, i, make_unique<Mur>(0, i));
        d_terrain.setCase(x - 1, i, make_unique<Mur>(x - 1, i));
    }

    d_terrain.setCase(rx, ry, make_unique<Canon>(rx, ry));

    if (ry == 0)
    {
        rx = rand() % (x - 2) + 1;
        d_terrain.setCase(rx, y - 1, make_unique<Cible>(rx, y - 1));
    }
    else if (ry == y - 1)
    {
        rx = rand() % (x - 2) + 1;
        d_terrain.setCase(rx, 0, make_unique<Cible>(rx, 0));
    }
    else if (rx == 0)
    {
        ry = rand() % (y - 2) + 1;
        d_terrain.setCase(x - 1, ry, make_unique<Cible>(x - 1, ry));
    }
    else
    {
        ry = rand() % (y - 2) + 1;
        d_terrain.setCase(0, ry, make_unique<Cible>(0, ry));
    }

    //ajout du sol
    for (int i = 1; i < x - 1; ++i)
    {
        for (int j = 1; j < y - 1; ++j)
        {
            d_terrain.setCase(i, j, make_unique<sol>(i, y));
        }
    }
}

/**
 * @brief place mirror
 *
 */
void joueur::place_mirror()
{
    int x, y;
    int num, nb;
    char c;

    afficher();

    cout << endl
         << endl;

    cout << "Donner le nombre de miroir a placer  : " << endl;
    cin >> nb;

    for (int i = 0; i < nb; i++)
    {
        cout << "donner les coords du mirroir numero : " << i + 1 << " avec x et y  puis le type de mirroir (/(0) ou \\(1) ): ";
        cin >> x >> y;
        cin >> num;
        while (num != 0 && num != 1)
        {
            cout << "donner un mirroir du type (/(0) ou \\(1) ): ";
            cin >> num;
        }

        while (d_terrain.getCase(x, y)->getChar() != ' ')
        {
            cout << "redonner correctement le placement du mirroir : ";
            cin >> x >> y;
        }

        if (num == 0)
        {
            c = '/';
            d_terrain.setCase(x, y, make_unique<Mirroir>(x, y, c));
            Mirroir m{x, y, c};
            d_mirroir.push_back(m);
        }
        else
        {
            c = '\\';
            d_terrain.setCase(x, y, make_unique<Mirroir>(x, y, c));
            Mirroir m{x, y, c};
            d_mirroir.push_back(m);
        }
    }
}

/**
 * @brief affichage defaite
 *
 */
void joueur::defaite() const
{
    cout << R"(
 /$$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$  /$$$$$$ /$$$$$$$$ /$$$$$$$$
| $$__  $$| $$_____/| $$_____//$$__  $$|_  $$_/|__  $$__/| $$_____/
| $$  \ $$| $$      | $$     | $$  \ $$  | $$     | $$   | $$
| $$  | $$| $$$$$   | $$$$$  | $$$$$$$$  | $$     | $$   | $$$$$
| $$  | $$| $$__/   | $$__/  | $$__  $$  | $$     | $$   | $$__/
| $$  | $$| $$      | $$     | $$  | $$  | $$     | $$   | $$
| $$$$$$$/| $$$$$$$$| $$     | $$  | $$ /$$$$$$   | $$   | $$$$$$$$
|_______/ |________/|__/     |__/  |__/|______/   |__/   |________/



)" << endl;
}

/**
 * @brief efface derniere mirroir
 *
 */
void joueur::erase_mirror()
{
    cout << "efface le dernier mirroir ... :" << endl;
    int x = d_mirroir.back().getX();
    int y = d_mirroir.back().getY();
    d_terrain.removeMirror(x, y);
    d_mirroir.pop_back();
}

/**
 * @brief efface tous les mirroir
 *
 */
void joueur::reset()
{
    for (int i = 0; i < d_mirroir.size(); i++)
    {
        int x = d_mirroir[i].getX();
        int y = d_mirroir[i].getY();
        d_terrain.removeMirror(x, y);
    }
}

/**
 * @brief renvoi le char de la prochaine case
 *
 * @param l
 * @return char
 */
char joueur::nextcharCase(Laser l)
{
    //donne laser
    if (l.getDirection() == "droite")
    {
        return d_terrain.getCharCase(l.getX(), l.getY() + 1);
    }

    if (l.getDirection() == "gauche")
    {
        return d_terrain.getCharCase(l.getX(), l.getY() - 1);
    }

    if (l.getDirection() == "haut")
    {
        return d_terrain.getCharCase(l.getX() - 1, l.getY());
    }

    if (l.getDirection() == "bas")
    {
        return d_terrain.getCharCase(l.getX() + 1, l.getY());
    }
}

/**
 * @brief tire
 *
 */
void joueur::shoot()
{
    //direction debut
    int xcannon = d_cannon.getX();
    int ycannon = d_cannon.getY();

    //placement du premier laser
    if (d_cannon.getY() == 0)
    {
        d_laser.push_back({xcannon, ycannon + 1, "droite"});
        d_terrain.removeMirror(xcannon, ycannon + 1);
        d_terrain.setCase(xcannon, ycannon + 1, make_unique<Laser>(xcannon, ycannon + 1, "droite"));
    }

    if (d_cannon.getY() == d_terrain.getColumn() - 1)
    {
        d_laser.push_back({xcannon, ycannon - 1, "gauche"});
        d_terrain.removeMirror(xcannon, ycannon - 1);
        d_terrain.setCase(xcannon, ycannon - 1, make_unique<Laser>(xcannon, ycannon - 1, "gauche"));
    }

    if (d_cannon.getX() == 0)
    {
        d_laser.push_back({xcannon + 1, ycannon, "bas"});
        d_terrain.removeMirror(xcannon + 1, ycannon);
        d_terrain.setCase(xcannon + 1, ycannon, make_unique<Laser>(xcannon + 1, ycannon, "bas"));
    }

    if (d_cannon.getX() == d_terrain.getRows() - 1)
    {
        d_laser.push_back({xcannon - 1, ycannon, "haut"});
        d_terrain.removeMirror(xcannon - 1, ycannon);
        d_terrain.setCase(xcannon - 1, ycannon, make_unique<Laser>(xcannon - 1, ycannon, "haut"));
    }

    //mettre les lasers dans le tableau
    //tant que il ne rencontre pas un mur et le cible
    //mur = X

    bool verif = true;
    while (verif)
    {
        //correct
        //si sa vient d'en bas (direction haut) va a droite
        if (nextcharCase(d_laser.back()) == '/' && d_laser.back().getDirection() == "haut")
        {
            //si direction == haut alors viens du bas
            //envoi vers droite

            int xl = d_laser.back().getX() - 1;
            int yl = d_laser.back().getY() + 1;

            d_laser.push_back({xl, yl, "droite"});
            d_terrain.removeMirror(xl, yl);
            d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "droite"));
        }
        //correct
        if (nextcharCase(d_laser.back()) == '/' && d_laser.back().getDirection() == "droite")
        {
            //si direction == droite  alors viens de gauche
            //envoi vers bas
            int xl = d_laser.back().getX() - 1;
            int yl = d_laser.back().getY() + 1;

            d_laser.push_back({xl, yl, "haut"});
            d_terrain.removeMirror(xl, yl);
            d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "haut"));
        }

        //corrrect
        if (nextcharCase(d_laser.back()) == '/' && d_laser.back().getDirection() == "gauche")
        {
            //si direction == gauche il vient de droite
            //envoi vers gauche
            int xl = d_laser.back().getX() + 1;
            int yl = d_laser.back().getY() - 1;

            d_laser.push_back({xl, yl, "bas"});
            d_terrain.removeMirror(xl, yl);
            d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "bas"));
        }

        //correct
        if (nextcharCase(d_laser.back()) == '/' && d_laser.back().getDirection() == "bas")
        {
            //si direction == haut viens de bas
            //envoi vers gauche
            int xl = d_laser.back().getX() + 1;
            int yl = d_laser.back().getY() - 1;

            d_laser.push_back({xl, yl, "gauche"});
            d_terrain.removeMirror(xl, yl);
            d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "gauche"));
        }

        //mirroir \

        //correct
        if (nextcharCase(d_laser.back()) == '\\' && d_laser.back().getDirection() == "haut")
        {
            //si direction == haut alors viens du bas
            //envoi vers gauche
            int xl = d_laser.back().getX() - 1;
            int yl = d_laser.back().getY() - 1;

            d_laser.push_back({xl, yl, "gauche"});
            d_terrain.removeMirror(xl, yl);
            d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "gauche"));
        }

        //correct
        if (nextcharCase(d_laser.back()) == '\\' && d_laser.back().getDirection() == "droite")
        {
            //si direction == droite  alors viens de gauche
            //envoi vers bas
            int xl = d_laser.back().getX() + 1;
            int yl = d_laser.back().getY() + 1;

            d_laser.push_back({xl, yl, "bas"});
            d_terrain.removeMirror(xl, yl);
            d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "bas"));
        }

        //correct
        if (nextcharCase(d_laser.back()) == '\\' && d_laser.back().getDirection() == "gauche")
        {
            //si direction == gauche il vient de droite
            //envoi vers gauche
            int xl = d_laser.back().getX() - 1;
            int yl = d_laser.back().getY() + 1;

            d_laser.push_back({xl, yl, "haut"});
            d_terrain.removeMirror(xl, yl);
            d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "haut"));
        }

        //correct
        if (nextcharCase(d_laser.back()) == '\\' && d_laser.back().getDirection() == "bas")
        {
            //si direction == haut viens de bas
            //envoi vers gauche
            int xl = d_laser.back().getX() + 1;
            int yl = d_laser.back().getY() + 1;

            d_laser.push_back({xl, yl, "droite"});
            d_terrain.removeMirror(xl, yl);
            d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "droite"));
        }

        if (nextcharCase(d_laser.back()) == 'X')
        {
            cout << endl;
            defaite();
            verif = false;
        }

        //cible = @
        if (nextcharCase(d_laser.back()) == '@')
        {
            //faire fonctione victoire
            //cout<<"test1"<<endl;
            cout << "victoire" << endl;
            d_score += 10;
            score();
            verif = false;
        }

        if (nextcharCase(d_laser.back()) == ' ')
        {
            if (d_laser.back().getDirection() == "haut")
            {
                int xl = d_laser.back().getX() - 1;
                int yl = d_laser.back().getY();

                d_laser.push_back({xl, yl, "haut"});
                d_terrain.removeMirror(xl, yl);
                d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "haut"));
            }

            if (d_laser.back().getDirection() == "bas")
            {
                int xl = d_laser.back().getX() + 1;
                int yl = d_laser.back().getY();

                d_laser.push_back({xl, yl, "bas"});
                d_terrain.removeMirror(xl, yl);
                d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "bas"));
            }

            if (d_laser.back().getDirection() == "droite")
            {
                int xl = d_laser.back().getX();
                int yl = d_laser.back().getY() + 1;

                d_laser.push_back({xl, yl, "droite"});
                d_terrain.removeMirror(xl, yl);
                d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "droite"));
            }

            if (d_laser.back().getDirection() == "gauche")
            {
                int xl = d_laser.back().getX();
                int yl = d_laser.back().getY() - 1;

                d_laser.push_back({xl, yl, "gauche"});
                d_terrain.removeMirror(xl, yl);
                d_terrain.setCase(xl, yl, make_unique<Laser>(xl, yl, "gauche"));
            }
        }
    }
}

/**
 * @brief stocke le score de l'utilisateur et l'affiche
 *
 */
void joueur::score() const
{
    cout << endl
         << "votre score est : " << d_score << endl;
}

/**
 * @brief affiche le terrain
 *
 */
void joueur::afficher() const
{
    d_terrain.affichageTexte();
}


/**
 * @brief return with argument count of line and column in file filename
 *
 * @param filename
 * @param nbline
 * @param nbcolumn
 */
void joueur::nb_line_and_column(string filename, int &nbline, int &nbcolumn)
{
    ifstream fichier(filename);
    string ligne;
    nbline = 0;
    while (getline(fichier, ligne))
    {
        nbline++;
        nbcolumn = ligne.size();
    }
    fichier.close();
}

/**
 * @brief Lis le fichier et stock le terrain
 *
 */
Terrain joueur::read()
{

    cout<<"donner le nom du fichier avec extension :";
    string filename;
    cin>>filename;


    //récupere la taille du terrain et creer le terrain qui est vide pour l'instant
    int nblignne = 0;
    int nb_col = 0;
    nb_line_and_column(filename, nblignne, nb_col);
    d_terrain = Terrain(nblignne, nb_col);


    ifstream fichier(filename);
    if (fichier)
    {
        //L'ouverture s'est bien passée, on peut donc lire

        string ligne; //Une variable pour stocker les lignes lues
        int j = 0;
        while (getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            for (int i = 0; i < ligne.size(); i++)
            {
                if(ligne[i]=='X')
                {
                    d_terrain.setCase(j,i,make_unique<Mur>(j, i));
                }

                if(ligne[i] == '@')
                {
                    d_terrain.setCase(j,i,make_unique<Cible>(j, i));
                }

                if(ligne[i] == ' ')
                {
                    d_terrain.setCase(j,i,make_unique<sol>(j, i));
                }

                if(ligne[i] == '#')
                {
                    d_terrain.setCase(j,i,make_unique<Canon>(j, i));
                    d_cannon.setX(j);
                    d_cannon.setY(i);
                }
            }
            j++;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return d_terrain;
}



/**
 * @brief Sauvegarde le fichier
 *
 */
bool joueur::save_write()
{
    cout<<"donner le nom du fichier avec extension :";
    string filename;
    cin>>filename;
    string const nomFichier(filename);
    ofstream File(nomFichier.c_str());

    if (File)
    {
        for (int i = 0; i < d_terrain.getRows(); i++)
        {
            for (int j = 0; j < d_terrain.getColumn(); j++)
            {
                File << d_terrain.getCharCase(i,j);
            }
            File << endl;
        }
    }
    else
    {
        cout << "ERROR: Impossible d'ouvrir le fichier." << endl;
        return false;
    }
    return true;
}

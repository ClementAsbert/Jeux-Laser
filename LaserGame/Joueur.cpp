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
#include <ctype.h>

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
            terrain_aleatoire();
            break;
        case 3:
            shoot();
            break;
        case 4:
            afficher();
            break;
        case 5:
            openOrCloseGraphique();
            break;
        case 6:
            place_mirror();
            break;
        case 7:
            erase_mirror();
            break;
        case 8:
            reset_mirror();
            break;
        case 9 :
            reset_terrain();
            break;
        case 10:
            {
                cout<<"donner le nom du fichier avec extension :  ";
                string filename ="";
                cin>>filename;
                read(filename);
                break;
            }

        case 11:
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
        cout << "(2) Terrain aleatoire " << '\n';
        cout << "(3) Lancer une partie" << '\n';
        cout << "(4) Affiche la partie textuelle" << '\n';
        cout << "(5) Ouvre/Ferme fenetre graphique" << '\n';
        cout << "(6) Placer mirroir" << '\n';
        cout << "(7) Effacer mirroir (dernier mirroir)" << '\n';
        cout << "(8) Reset tous les mirroirs" << endl;
        cout << "(9) Reset tout le terrain" << endl;
        cout << "(10) Charger un Terrain a partir d un fichier" << endl;
        cout << "(11) Sauvegarder un terrain" << endl;
        cout << "(12) Quitter la partie" << endl;
        cout << endl
             << "votre choix : ";
        cin >> choice;
    } while (choice < 1 || choice > 12);
    return choice;
}

/**
 * @brief generate terrain
 *
 */
void joueur::generate_terrain()
{
    int x, y;
    d_laser.clear();
    d_mirroir.clear();

    do
    {
        cout << "donner la taille du terrain en premier x et y : " << endl;
        cin >> x >> y;
    } while (x < 3 || y < 3);

    d_terrain = Terrain(x, y);

    //placement aleatoire de cible et cannon
    srand(time(NULL));
    int rx = rand() % x;
    srand(time(NULL));
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
 * @brief  terrain aleatoire
 *
 */
void joueur::terrain_aleatoire()
{
    d_laser.clear();
    d_mirroir.clear();
    cout<<"Terrain choisis au hasard "<<endl;
    srand(time(nullptr));
    int nombreDeTerrain = 5;
    int randomTerrain = rand() % nombreDeTerrain;
    string filename = "randomTerrain" + to_string(randomTerrain) +".txt";
    d_terrain = read(filename);
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
    d_fenetre.affichage(d_terrain);
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

void joueur::victoire() const
{
    cout << R"(
____    ____  __    ______ .___________.  ______    __  .______       _______
\   \  /   / |  |  /      ||           | /  __  \  |  | |   _  \     |   ____|
 \   \/   /  |  | |  ,----'`---|  |----`|  |  |  | |  | |  |_)  |    |  |__
  \      /   |  | |  |         |  |     |  |  |  | |  | |      /     |   __|
   \    /    |  | |  `----.    |  |     |  `--'  | |  | |  |\  \----.|  |____
    \__/     |__|  \______|    |__|      \______/  |__| | _| `._____||_______|

)"<<endl;

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
    d_terrain.removeCase(x, y);
    d_mirroir.pop_back();
}

/**
 * @brief efface tous les mirroir
 *
 */
void joueur::reset_mirror()
{
    for (int i = 0; i < d_mirroir.size(); i++)
    {
        int x = d_mirroir[i].getX();
        int y = d_mirroir[i].getY();
        d_terrain.removeCase(x, y);
    }
}

/**
 * @brief efface tous les mirroirs et les lasers
 *
 */
void joueur::reset_terrain()
{
    reset_mirror();
    for (int i = 0; i < d_laser.size(); i++)
    {
        int x = d_laser[i].getX();
        int y = d_laser[i].getY();
        d_terrain.removeCase(x, y);
    }
    cout << endl;
    cout << "Votre terrain a bien etait reinitialise." << endl;
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
    //on peut pas mettre sous forme de switch car nous obtenons une erreur du type "s"
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
 * @brief renvoie le numero de la direction
 * @param direction
 */
int joueur::number_direction(string direction) const
{
    if(direction == "haut")
    {
        return 1;
    }
    else if(direction == "bas")
    {
        return 2;
    }
    else if(direction == "gauche")
    {
        return 3;
    }
    else{
        //direction droite
        return 4;
    }
}

void joueur::AppliqueLaser(int x, int y, string position)
{
    d_laser.push_back({x, y, position});
    d_terrain.removeCase(x, y);
    d_terrain.setCase(x, y, make_unique<Laser>(x, y, position));

}


/**
 * @brief place le prochain laser lorsqu'il rencontre un slash
 * @param direction
 * @param nb_direction
 */
void joueur::place_Laser_sl(string direction, int nb_direction)
{
    //int nb = number_direction(direction);
    switch(nb_direction)
    {
    case 1:
        {
        //si direction == haut alors viens du bas
        //envoi vers droite

        int xl =  d_laser.back().getX() - 1;
        int yl =  d_laser.back().getY() + 1;
        AppliqueLaser(xl,yl, "droite");

        break;
        }
    case 2:
        {
        //si direction == haut viens de bas
        //envoi vers gauche
        int xl = d_laser.back().getX() + 1;
        int yl = d_laser.back().getY() - 1;

        AppliqueLaser(xl,yl, "gauche");
        break;
        }
    case 3:
        {
        //si direction == gauche il vient de droite
        //envoi vers gauche
        int xl = d_laser.back().getX() + 1;
        int yl = d_laser.back().getY() - 1;

        AppliqueLaser(xl,yl, "bas");
        break;
        }
    case 4:
        {
        //si direction == droite  alors viens de gauche
        //envoi vers bas
        int xl = d_laser.back().getX() - 1;
        int yl = d_laser.back().getY() + 1;

        AppliqueLaser(xl,yl, "haut");
        break;
        }
    }
}

/**
 * @brief place le prochain laser lorsqu'il rencontre un antislash
 * @param direction
 * @param nb_direction
 */
void joueur::place_Laser_asl(string direction, int nb_direction)
{
    //int nb = number_direction(direction);
    switch(nb_direction)
    {
    //haut
    case 1:
        {
            //si direction == haut alors viens du bas
            //envoi vers gauche
            int xl = d_laser.back().getX() - 1;
            int yl = d_laser.back().getY() - 1;
            AppliqueLaser(xl,yl, "gauche");
            break;
        }
    //bas
    case 2:
        {
            //si direction == haut viens de bas
            //envoi vers gauche
            int xl = d_laser.back().getX() + 1;
            int yl = d_laser.back().getY() + 1;
            AppliqueLaser(xl,yl, "droite");
            break;
        }
    //gauche
    case 3:
        {
            //si direction == gauche il vient de droite
            //envoi vers gauche
            int xl = d_laser.back().getX() - 1;
            int yl = d_laser.back().getY() - 1;
            AppliqueLaser(xl,yl, "haut");
            break;
        }
    //droite
    case 4:
        {
            //si direction == droite  alors viens de gauche
            //envoi vers bas
            int xl = d_laser.back().getX() + 1;
            int yl = d_laser.back().getY() + 1;
            AppliqueLaser(xl,yl, "bas");
            break;
        }
    }
}



/**
 * @brief place le prochain laser quand il y a rien devant
 * @param direction
 * @param nb_direction
 */
void joueur::place_Laser_vide(string direction, int nb_direction)
{
    //int nb = number_direction(direction);
    switch(nb_direction)
    {
    //haut
    case 1:
        {
            int xl = d_laser.back().getX() - 1;
            int yl = d_laser.back().getY();
            AppliqueLaser(xl,yl, "haut");
            break;
        }
    //bas
    case 2:
        {
            int xl = d_laser.back().getX() + 1;
            int yl = d_laser.back().getY();
            AppliqueLaser(xl,yl, "bas");
            break;
        }
    //gauche
    case 3:
        {
            int xl = d_laser.back().getX();
            int yl = d_laser.back().getY() - 1;
            AppliqueLaser(xl,yl, "gauche");
            break;
        }
    //droite
    case 4:
        {
            int xl = d_laser.back().getX();
            int yl = d_laser.back().getY() + 1;
            AppliqueLaser(xl,yl, "droite");
            break;
        }
    }
}


void joueur::placeCanon(int x, int y, string position)
{
    d_laser.push_back({x, y, position});
    d_terrain.removeCase(x, y);
    d_terrain.setCase(x, y, make_unique<Laser>(x, y, position));
}

/**
 * @brief tire
 *
 */
void joueur::shoot()
{
    //Si deja laser dedans cout << veuillez generer un nouveau terrain if d_laser.size() != 0 return
    if (d_laser.size() != 0)
    {
        cout << endl;
        cout << "Veuillez generer un nouveau terrain ou reset le terrain avec le bouton numero (8)." << endl;
        return;
    }
    //si on lance la partie sans g�n�rer un terrain choisis un terrain au hasard dans les fichiers txt
    if(d_terrain.getRows() == 0 && d_terrain.getColumn() == 0)
    {
      cout<<"veuillez generer un terrain ou choisir l'option terrain aleatoire pour pouvoir jouer "<<endl;
      start();
    }


    //direction debut
    int xcannon = d_cannon.getX();
    int ycannon = d_cannon.getY();

    //placement du premier laser
    //inutile de faire un switch pour deux if a chaque fois
    if (d_cannon.getY() == 0)
    {
        placeCanon(xcannon, ycannon+1 , "droite");
    }

    if (d_cannon.getY() == d_terrain.getColumn() - 1)
    {
        placeCanon(xcannon, ycannon-1 , "gauche");
    }

    if (d_cannon.getX() == 0)
    {
        placeCanon(xcannon+1, ycannon , "bas");
    }

    if (d_cannon.getX() == d_terrain.getRows() - 1)
    {
        placeCanon(xcannon-1, ycannon , "haut");
    }

    //mettre les lasers dans le tableau
    //tant que il ne rencontre pas un mur et le cible
    //mur = X

    bool verif = true;
    while (verif)
    {
        //je recupere le numero de la direction pour pouvoir effectuer un switch sur le num�ro apr�s
        int nb_direction = number_direction(d_laser.back().getDirection());

        //correct
        //remaniement du code
        if(nextcharCase(d_laser.back()) == '/')//hbgd
        {
            switch(nb_direction){
            case 1:
                place_Laser_sl("haut", 1);
                nb_direction = 4;
                break;
            case 2:
                place_Laser_sl("bas",2);
                nb_direction = 3;
                break;
            case 3:
                place_Laser_sl("gauche",3);
                nb_direction = 2;
                break;
            case 4:
                place_Laser_sl("droite",4);
                nb_direction=1;
                break;
            }
        }

        //mirroir \
        //correct
        //remaniement du code
        if(nextcharCase(d_laser.back()) == '\\')
        {
            switch(nb_direction){
            case 1:
                place_Laser_asl("haut", 1);
                nb_direction = 3;
                break;
            case 2:
                place_Laser_asl("bas",2);
                nb_direction = 4;
                break;
            case 3:
                place_Laser_asl("gauche",3);
                nb_direction = 1;
                break;
            case 4:
                place_Laser_asl("droite",4);
                nb_direction = 2;
                break;
            }
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
            victoire();
            d_score += 10;
            score();
            verif = false;
        }

        if (nextcharCase(d_laser.back()) == ' ')
        {   switch(nb_direction){
            case 1:
                place_Laser_vide("haut", 1);
                nb_direction = 1;
                break;
            case 2:
                place_Laser_vide("bas",2);
                nb_direction = 2;
                break;
            case 3:
                place_Laser_vide("gauche",3);
                nb_direction = 3;
                break;
            case 4:
                place_Laser_vide("droite",4);
                nb_direction = 4;
                break;
            }
        }
    }
    d_fenetre.affichage(d_terrain);
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
 * @brief affiche le terrain
 *
 */
void joueur::openOrCloseGraphique()
{
    //si on lance la partie sans g�n�rer un terrain choisis un terrain au hasard dans les fichiers txt
    if(d_terrain.getRows() == 0 && d_terrain.getColumn() == 0)
    {
      cout<<"Veuillez generer un terrain ou choisir l'option terrain aleatoire pour pouvoir jouer "<<endl;
      start();
    }
    else
        d_fenetre.openOrClose(d_terrain);
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
Terrain joueur::read(const string& filename)
{

    //r�cupere la taille du terrain et creer le terrain qui est vide pour l'instant
    int nblignne = 0;
    int nb_col = 0;
    nb_line_and_column(filename, nblignne, nb_col);
    d_terrain = Terrain(nblignne, nb_col);

    ifstream fichier(filename);
    if (fichier)
    {
        //L'ouverture s'est bien pass�e, on peut donc lire

        string ligne; //Une variable pour stocker les lignes lues
        int j = 0;
        while (getline(fichier, ligne)) //Tant qu'on n'est pas � la fin, on lit
        {
            for (int i = 0; i < ligne.size(); i++)
            {
                switch(ligne[i]) {
                    case 'X' :
                        d_terrain.setCase(j,i,make_unique<Mur>(j, i));
                        break;
                    case '@' :
                        d_terrain.setCase(j,i,make_unique<Cible>(j, i));
                        break;
                    case '#' :
                        d_terrain.setCase(j,i,make_unique<Canon>(j, i));
                        d_cannon.setX(j);
                        d_cannon.setY(i);
                        break;
                    case ' ' :
                        d_terrain.setCase(j,i,make_unique<sol>(j, i));
                        break;

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

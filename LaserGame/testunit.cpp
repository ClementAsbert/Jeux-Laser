/*
#include "doctest.h"
#include "Canon.h"
#include "Cible.h"
#include "Laser.h"
#include "Mirroir.h"
#include "sol.h"
#include "Terrain.h"
#include "Joueur.h"

TEST_CASE("les test unitaires du canon")
{
    int x  = 10;
    int y = 11;
    Canon c{x,y};
    SUBCASE("les valeurs ont bien été ajouter")
    {
        int resultat{c.getX()};
        int resultat2{c.getY()};


        REQUIRE_EQ(resultat,x);
        REQUIRE_EQ(resultat2,y);
    }

    SUBCASE("On creer un canon, change valeurs , verif")
    {
        int newx = 2;
        c.setX(newx);
        int resultat{c.getX()};

        REQUIRE_EQ(resultat,newx);
    }

    SUBCASE("modif Char")
    {
        char newc = 'L';
        c.setChar(newc);
        char resultat{c.getChar()};

        REQUIRE_EQ(resultat,newc);
    }
}

TEST_CASE("les test unitaires du cible")
{
    int x  = 10;
    int y = 11;
    Cible c{x,y};
    SUBCASE("les valeurs ont bien été ajouter")
    {
        int resultat{c.getX()};
        int resultat2{c.getY()};


        REQUIRE_EQ(resultat,x);
        REQUIRE_EQ(resultat2,y);
    }

    SUBCASE("On creer une cible, change valeurs , verif")
    {
        int newx = 2;
        c.setX(newx);
        int resultat{c.getX()};

        REQUIRE_EQ(resultat,newx);
    }

    SUBCASE("modif Char")
    {
        char newc = 'L';
        c.setChar(newc);
        char resultat{c.getChar()};

        REQUIRE_EQ(resultat,newc);
    }
}

TEST_CASE("les test unitaires du Laser")
{
    int x  = 10;
    int y = 11;
    Laser c{x,y, "haut"};
    SUBCASE("les valeurs ont bien été ajouter")
    {
        int resultat{c.getX()};
        int resultat2{c.getY()};


        REQUIRE_EQ(resultat,x);
        REQUIRE_EQ(resultat2,y);
    }

    SUBCASE("On creer un laser, change valeurs , verif")
    {
        int newx = 2;
        c.setX(newx);
        int resultat{c.getX()};

        REQUIRE_EQ(resultat,newx);
    }

    SUBCASE("modif Char")
    {
        char newc = 'L';
        c.setChar(newc);
        char resultat{c.getChar()};

        REQUIRE_EQ(resultat,newc);
    }

    SUBCASE("on creer un laser de direction haut et on verifie si on a I")
    {
        REQUIRE_EQ('|', c.getChar());
    }
}

TEST_CASE("les test unitaires du mirroir")
{
    int x  = 10;
    int y = 11;
    Mirroir c{x,y, '/'};
    SUBCASE("les valeurs ont bien été ajouter")
    {
        int resultat{c.getX()};
        int resultat2{c.getY()};


        REQUIRE_EQ(resultat,x);
        REQUIRE_EQ(resultat2,y);
    }

    SUBCASE("On creer un mirroir, change valeurs , verif")
    {
        int newx = 2;
        c.setX(newx);
        int resultat{c.getX()};

        REQUIRE_EQ(resultat,newx);
    }

    SUBCASE("modif Char")
    {
        char newc = 'L';
        c.setChar(newc);
        char resultat{c.getChar()};

        REQUIRE_EQ(resultat,newc);
    }
}

TEST_CASE("les test unitaires du mur")
{
    int x  = 10;
    int y = 11;
    Cible c{x,y};
    SUBCASE("les valeurs ont bien été ajouter")
    {
        int resultat{c.getX()};
        int resultat2{c.getY()};


        REQUIRE_EQ(resultat,x);
        REQUIRE_EQ(resultat2,y);
    }

    SUBCASE("On creer un mur, change valeurs , verif")
    {
        int newx = 2;
        c.setX(newx);
        int resultat{c.getX()};

        REQUIRE_EQ(resultat,newx);
    }

    SUBCASE("modif Char")
    {
        char newc = 'L';
        c.setChar(newc);
        char resultat{c.getChar()};

        REQUIRE_EQ(resultat,newc);
    }
}

TEST_CASE("les test unitaires pour le sol")
{
    int x  = 10;
    int y = 11;
    sol c{x,y};
    SUBCASE("les valeurs ont bien été ajouter")
    {
        int resultat{c.getX()};
        int resultat2{c.getY()};


        REQUIRE_EQ(resultat,x);
        REQUIRE_EQ(resultat2,y);
    }

    SUBCASE("On creer un sol, change valeurs , verif")
    {
        int newx = 2;
        c.setX(newx);
        int resultat{c.getX()};

        REQUIRE_EQ(resultat,newx);
    }

    SUBCASE("modif Char")
    {
        char newc = 'L';
        c.setChar(newc);
        char resultat{c.getChar()};

        REQUIRE_EQ(resultat,newc);
    }
}

TEST_CASE("les test unitaires pour le sol")
{
    int x  = 10;
    int y = 11;
    Terrain c{x,y};
    SUBCASE("les valeurs ont bien été ajouter")
    {
        int resultat{c.getRows()};
        int resultat2{c.getColumn()};


        REQUIRE_EQ(resultat,x);
        REQUIRE_EQ(resultat2,y);
    }
}


/*
faire test joueur
TEST_CASE("les test unitaires pour le joueur")
{
    joueur c{};
}


*/



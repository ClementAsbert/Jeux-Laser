#include "doctest.h"
#include "calculateur.h"

TEST_CASE("Les valeurs sont bien entrées") {
    double x {12.3};
    calculateur calc{};
    calc.entre(x);
    double resultat {calc.resultat()};
    REQUIRE_EQ(resultat , x);

    double x2 {-10};
    calc.entre(x2);
    double resultat2{calc.resultat()};
    REQUIRE_EQ(resultat2, x2);
}


TEST_CASE("Les opérations unaires sont correctes") {
calculateur calc{};
    SUBCASE("le changement de signe est correct")
    {
        double x {12.3};
        calc.entre(x);
        calc.changeSigne();
        REQUIRE_EQ(calc.resultat(),-x);
        calc.changeSigne();
        REQUIRE_EQ(calc.resultat(),x);
    }
}



TEST_CASE("Les opérations binaires sont correctes") {
    calculateur calc{};
    double y {12.3};
    double x {-98.3};
    calc.entre(y);
    calc.entre(x);
    SUBCASE("L'addition est correcte")
    {
        calc.addtionne();
        REQUIRE_EQ(calc.resultat(),y+x);
    }


    SUBCASE("La soustraction est correcte")
    {
        calc.soustrait();
        REQUIRE_EQ(calc.resultat(),y-x);
    }
}

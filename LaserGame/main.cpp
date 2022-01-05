#include <iostream>
#include <string>
#include "graphics.h"
/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
*/
#include "Joueur.h"

using namespace std;

void ascii()
{
    cout<<R"(_        _______  _______  _______  _______
( \      (  ___  )(  ____ \(  ____ \(  ____ )
| (      | (   ) || (    \/| (    \/| (    )|
| |      | (___) || (_____ | (__    | (____)|
| |      |  ___  |(_____  )|  __)   |     __)
| |      | (   ) |      ) || (      | (\ (
| (____/\| )   ( |/\____) || (____/\| ) \ \__
(_______/|/     \|\_______)(_______/|/   \__/

 _______  _______  _______  _______                      _______
(  ____ \(  ___  )(       )(  ____ \  |\     /||\     /|(  ___  )
| (    \/| (   ) || () () || (    \/  | )   ( || )   ( || (   ) |
| |      | (___) || || || || (__      | |   | || (___) || (___) |
| | ____ |  ___  || |(_)| ||  __)     | |   | ||  ___  ||  ___  |
| | \_  )| (   ) || |   | || (        | |   | || (   ) || (   ) |
| (___) || )   ( || )   ( || (____/\  | (___) || )   ( || )   ( |
(_______)|/     \||/     \|(_______/  (_______)|/     \||/     \|
                                                                 )"<<endl;
}



int main()
{
    //ascii();
    //joueur j{};
    //j.menu();
   int gd = DETECT, gm, x, y, color, angle = 0;
   struct arccoordstype a, b;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   getch();
   closegraph();


}



#include"turtledrawapplication.h"
#include"turtleMover.h"
#include"turtlepen.h"
#include "turtleManipulation.h"
#include"graphics.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

namespace logo
{

turtleDrawApplication::turtleDrawApplication() : d_turtle{}
{}

void turtleDrawApplication::run()
{
  bool goOn = true;
  while (goOn)
  {
    int choice {menu()};
    switch(choice)
    {
      case 1 : raiseTurtlePen(); break;
      case 2 : lowerTurtlePen(); break;
      case 3 : forwardTurtle(); break;
      case 4 : turnTurtleLeft(); break;
      case 5 : turnTurtleRight(); break;
      default: goOn = false;
    }
  }
}

int turtleDrawApplication::menu()
{
  int choice;
  do
  {
    cout<<"Dessin avec une tortue"<<'\n'<<'\n';
    cout<<"(1) lever le pinceau"<<'\n';
    cout<<"(2) baisser le pinceau"<<'\n';
    cout<<"(3) avancer la tortue"<<'\n';
    cout<<"(4) tourner la tortue a gauche"<<'\n';
    cout<<"(5) tourner la tortue a droite"<<'\n';
    cout<<"(6) quitter le menu"<<endl;
    cout<<endl<<"votre choix : ";
    cin>>choice;
  }
  while (choice<1 || choice>6);
  return choice;
}

void turtleDrawApplication::raiseTurtlePen()
{
  turtleRaisePen trp{};
  trp.manipulate(d_turtle);
  ::waituntilbuttonpressed();
}

void turtleDrawApplication::lowerTurtlePen()
{
  turtleLowerPen trp{};
  trp.manipulate(d_turtle);
  ::waituntilbuttonpressed();
}

void turtleDrawApplication::forwardTurtle()
{
  cout<<"Faire avancer la tortue : pas d'avancement : ";
  int step;
  cin>>step;
  turtleForward tf{step};
  tf.manipulate(d_turtle);
  ::waituntilbuttonpressed();
}

void turtleDrawApplication::turnTurtleLeft()
{
  cout<<"Faire tourner la tortue a gauche : angle : ";
  int angle;
  cin>>angle;
  turtleLeft tl{angle};
  tl.manipulate(d_turtle);
  ::waituntilbuttonpressed();
}

void turtleDrawApplication::turnTurtleRight()
{
  cout<<"Faire tourner la tortue a droite : angle : ";
  int angle;
  cin>>angle;
  turtleRight tr{angle};
  tr.manipulate(d_turtle);
  ::waituntilbuttonpressed();
}

}

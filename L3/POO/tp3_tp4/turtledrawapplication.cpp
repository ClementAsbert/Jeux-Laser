#include"turtledrawapplication.h"
#include"turtleMover.h"
#include"turtlepen.h"
#include "turtle.h"
#include "turtleManipulation.h"
#include"graphics.h"
#include<iostream>
#include <memory>
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
        case 6 : undoLastManipulation(); break;
        case 7 : undoLastManipulation(); break;
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
    cout<<"(6) Annuler la derniere manipualtion"<<endl;
    cout<<"(7) renitialiser le dessin"<<endl;
    cout<<"(8) quitter le menu"<<endl;
    cout<<endl<<"votre choix : ";
    cin>>choice;
  }
  while (choice<1 || choice>7);
  return choice;
}

void turtleDrawApplication::raiseTurtlePen()
{
  applyManipulation(std::make_unique<turtleRaisePen> ());
}

void turtleDrawApplication::lowerTurtlePen()
{
    applyManipulation(std::make_unique<turtleLowerPen> ());
}

void turtleDrawApplication::forwardTurtle()
{
  cout<<"Faire avancer la tortue : pas d'avancement : ";
  int step;
  cin>>step;
      applyManipulation(std::make_unique<turtleForward> (step));

}

void turtleDrawApplication::turnTurtleLeft()
{
  cout<<"Faire tourner la tortue a gauche : angle : ";
  int angle;
  cin>>angle;
    applyManipulation(std::make_unique<turtleLeft> (angle));

}

void turtleDrawApplication::turnTurtleRight()
{
  cout<<"Faire tourner la tortue a droite : angle : ";
  int angle;
  cin>>angle;
    applyManipulation(std::make_unique<turtleRight> (angle));

}

void turtleDrawApplication::applyManipulation(std::unique_ptr<turtleManipulation> manip)
{
    manip->manipulate(d_turtle);
    d_manipulations.push_back(std::move(manip));
    ::waituntilbuttonpressed();
}

void turtleDrawApplication::reinitializeTurtle()
{
    d_turtle.setPosition({0.0,0.0});
    d_turtle.setHeading(0);
}

void turtleDrawApplication::undoLastManipulation()
{
    if(!d_manipulations.empty())
    {
        d_manipulations.pop_back();
        reinitializeTurtle();
        cleardevice();
        for(auto& var : d_manipulations)
        {
            var->manipulate(d_turtle);
        }
        ::waituntilbuttonpressed();
    }
}

void turtleDrawApplication::reset()
{
    d_manipulations.clear();
    reinitializeTurtle();
    cleardevice();
    ::waituntilbuttonpressed();
}


void turtleDrawApplication::redoLastManipulation()
{

}


}

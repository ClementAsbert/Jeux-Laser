#include<iostream>
#include<cctype>
#include<vector>
#include"calculatrice0.h"
using std::endl;

void calculatrice(std::istream& ist, std::ostream& ost)
{
  std::vector<double> pile;
  bool encore=true;
  char op;
  double x,y,res;
  while (encore)
  {
    ost<<'>';
    ist>>op;
    ist.putback(op);
    if (isdigit(op))
    {
      ist>>res;
      pile.push_back(res);
    }
    else
    {
      ist>>op;
      switch(op)
      {
        case '#' : x = pile.back(); pile.pop_back();
                   res = -x;
                   pile.push_back(res);
                   ost<<res<<endl;
                   break;
        case '+' : x = pile.back(); pile.pop_back();
                   y = pile.back(); pile.pop_back();
                   res = y+x;
                   pile.push_back(res);
                   ost<<res<<endl;
                   break;
        case '-' : x = pile.back(); pile.pop_back();
                   y = pile.back(); pile.pop_back();
                   res = y-x;
                   pile.push_back(res);
                   ost<<res<<endl;
                   break;
        case '*' : x = pile.back(); pile.pop_back();
                   y = pile.back(); pile.pop_back();
                   res = y*x;
                   pile.push_back(res);
                   ost<<res<<endl;
                   break;
        case '/' : x = pile.back(); pile.pop_back();
                   y = pile.back(); pile.pop_back();
                   res = y/x;
                   pile.push_back(res);
                   ost<<res<<endl;
                   break;
        case 'q' : encore=false;break;
        default : ost<<"erreur"<<endl;
      }
    }
  }
}


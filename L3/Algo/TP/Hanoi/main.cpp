#include <iostream>
#include "graphics.h"
#include <vector>
#include <unistd.h>
using namespace std;


struct disque{
    int longueur,epaisseur,couleur;
};

struct plateau{
    int x,y,longueur;
    vector<disque> pile;
};

void initPlateau(plateau& p,int x,int y,int l,int n){
    p.x=x;
    p.y=y;
    p.longueur=l;
    for(int i=n;i>=1;--i){
        p.pile.push_back({i*40,20,rand() % 7});
    }
}

void affichePlateau(plateau& dep,plateau& init,plateau& arr){
    for(plateau p : {dep,init,arr}){
        setcolor(WHITE);
        line(p.x-p.longueur,p.y,p.x+p.longueur,p.y);

        int h=p.y;
        for(disque d : p.pile){
            setcolor(d.couleur);
            rectangle(p.x-d.longueur/2, h, p.x+d.longueur/2, h-d.epaisseur);
            h-=d.epaisseur;
        }
    }
}

void hanoi(int n,plateau& dep,plateau& init,plateau& arr){
    if(n>0){
        hanoi(n-1,dep,arr,init);
        arr.pile.push_back(dep.pile.back());
        dep.pile.pop_back();
        cleardevice();
        affichePlateau(dep,init,arr);
        hanoi(n-1,init,dep,arr);
    }
}

int main()
{
    int n=3;
    plateau pDep,pInit,pArr;
    initPlateau(pDep,100,400,200,n);
    initPlateau(pInit,600,400,200,0);
    initPlateau(pArr,1100,400,200,0);

    opengraphsize(1920,900);

    hanoi(n,pDep,pInit,pArr);

    getch();
    closegraph();
    return 0;
}

#include "vue.h"
#include "Terrain.h"
#include "graphics.h"
#include <iostream>

vue::vue():d_fenetreOuvert{false},d_tailleX{80},d_tailleY{80}
{}

void vue::affichage(Terrain &terrain){
    if(d_fenetreOuvert){
        cleardevice();
        for (int i = 0; i < terrain.getRows(); i++)
        {
            for (int a = 0; a < terrain.getColumn(); a++)
            {
                switch(terrain.getCharCase(i,a)){//bug: demander au prof
                    case 'X':mur(a,i);break;
                    case '#':depart(a,i);break;
                    case '@':arrive(a,i);break;
                    case '|':laserVertical(a,i);break;
                    case '-':laserHorizontal(a,i);break;
                    case '/':mirroirSlash(a,i);break;
                    case '\\':mirroirAntiSlash(a,i);break;
                }
            }
        }
    }
}

void vue::openOrClose(Terrain &terrain)
{
    if(d_fenetreOuvert){
        cleardevice();
        ::closegraph();
        d_fenetreOuvert=false;
    }
    else{
        ::opengraphsize(d_tailleX*terrain.getColumn()+10,d_tailleY*terrain.getRows()+20);
        d_fenetreOuvert=true;
        affichage(terrain);
    }
}

void vue::close(){
    if(d_fenetreOuvert){
        cleardevice();
        ::closegraph();
        d_fenetreOuvert=false;
    }
}

void vue::mur(int x,int y){
    setcolor(15);
    rectangle(x*d_tailleX+1,y*d_tailleY+1,(x+1)*d_tailleX-1,(y+1)*d_tailleY-1);
}

void vue::depart(int x,int y){
    setcolor(5);
    rectangle(x*d_tailleX, y*d_tailleY+d_tailleY/3, (x+1)*d_tailleX-1, y*d_tailleY+(2*d_tailleY)/3);
    rectangle(x*d_tailleX+d_tailleX/3, y*d_tailleY+1, x*d_tailleX+(2*d_tailleX)/3, (y+1)*d_tailleY-1);
}

void vue::arrive(int x,int y){
    setcolor(11);
    circle(x*d_tailleX+d_tailleX/2, y*d_tailleY+d_tailleY/2, d_tailleY/2);
}

void vue::laserVertical(int x,int y){
    setcolor(15);
    line(x*d_tailleX+d_tailleX/2,y*d_tailleY,x*d_tailleX+d_tailleX/2,(y+1)*d_tailleY);
}

void vue::laserHorizontal(int x,int y){
    setcolor(15);
    line(x*d_tailleX,y*d_tailleY+d_tailleY/2,(x+1)*d_tailleX,y*d_tailleY+d_tailleY/2);
}

void vue::mirroirSlash(int x,int y){
    setcolor(15);
    line((x+1)*d_tailleX,y*d_tailleY,x*d_tailleX,(y+1)*d_tailleY);
}

void vue::mirroirAntiSlash(int x,int y){
    setcolor(15);
    line(x*d_tailleX,y*d_tailleY,(x+1)*d_tailleX,(y+1)*d_tailleY);
}

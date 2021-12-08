#include <iostream>
#include "dirent.h"
#include <string>
using namespace std;


void ls(const string &nomRep)
{
    DIR *rep;
    rep = opendir(nomRep.c_str());
    if(rep==nullptr){
        cout<<"file not found"<<endl;
        return;
    }
    dirent *elem;
    elem = readdir(rep);
    while(elem != nullptr)
    {
        cout<<elem->d_name<<endl;
        elem = readdir(rep);
    }
    closedir(rep);
}


void lsr(const string &nomrep, int p =0)
{
    DIR *rep = opendir(nomrep.c_str());
    if(rep == nullptr)
    {
        cout<<"file not founds "<<endl;
        return;
    }
    dirent *elem;
    while(elem=readdir(rep))
    {
        if(string(elem->d_name) != "." && string(elem->d_name) != "..")
        {
            for (int i = 0; i < p; i++) {
                cout<<"|    ";
            }
            cout<<elem->d_name<<endl;
            if(elem->d_type == DT_DIR)
            {
                lsr(nomrep+"/"+string(elem->d_name), p+1);
            }
        }
    }
    closedir(rep);
}



int find(const string &ch,const string& nomRep,int nbFichiers =0)
{
    DIR *rep;
    rep = opendir(nomRep.c_str());
    if (rep == nullptr) {
        cout<<"Impossible d'ouvrir le répertoire "<<nomRep<<endl;
    }
    dirent *elem;
    while ((elem = readdir(rep)) != nullptr) {
        if (string(elem->d_name) != "." && string(elem->d_name) != "..") {
            if (string(elem->d_name).find(ch) != string::npos)
            {
                cout<<nomRep<<"/"<<elem->d_name<<endl;
                nbFichiers += 1;
            }
            if (elem->d_type == DT_DIR)
            {
                nbFichiers = find(ch, nomRep + '/' + elem->d_name,nbFichiers);
            }
        }
    }
    closedir(rep);
    return nbFichiers;
}


//decomposition :
/*

wingbgi  = Perso/Algo/winbgi.doc


*/


void diff(const string& nomrep1, const string& nomrep2)
{
    DIR *rep1;
    DIR *rep2
    rep1 = opendir(nomrep1.c_str());
    rep2 = opendir(nomrep2.c_str());

    if (rep == nullptr) {
        cout<<"Impossible d'ouvrir le répertoire "<<nomRep<<endl;
    }

}


int main()
{
   int resultat = find("o", "Perso");
   cout<<resultat<<endl;
}

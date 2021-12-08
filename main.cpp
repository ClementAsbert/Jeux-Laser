

void lsr(const string& nomRep, int profondeur = 0) {
    while ((elem = readdir(rep)) != nullptr) {
        if (string(elem->d_name) != "." && string(elem->d_name) != "..") {
            for (int i = 0; i < profondeur; i++) {
                cout<<"|    ";
            }
            cout<<elem->d_name<<endl;
            if (elem->d_type == DT_DIR) {
                lsr(nomRep + '/' + elem->d_name, profondeur +1);
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

void diff(const string& nomRep1, const string& nomRep2)
{

}

int main()
{
    lsr("Perso");
    cout<<endl;
    cout<<"Exercice 3"<<endl;
    int nbFichiers = 0;
    nbFichiers = find("L","Perso");
    cout<<"Nombre total d'elements trouves : "<<nbFichiers<<endl;
    return 0;
}

#ifndef AFFICHEUR_H_INCLUDED
#define AFFICHEUR_H_INCLUDED

class platALaCarte;
class menu;
class repas;
class plat;
class platALaCarte;

//afficheur est une classe abstraite mais aussi une interface
class afficheur {
public:
    virtual ~afficheur() = default;
    virtual void affichePlat(const plat& p) const;
    virtual void affichePlatALaCarte(const platALaCarte& p) const = 0;
    virtual void afficheMenu(const menu& m) const = 0;
    virtual void afficheRepas(const repas& r) const = 0;
};

class afficheurTicket : public afficheur{
public:
    virtual void affichePlatALaCarte(const platALaCarte& p) const override;
    virtual void afficheMenu(const menu& m) const override;
    virtual void afficheRepas(const repas& r) const override;
};






#endif // AFFICHEUR_H_INCLUDED

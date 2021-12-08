#ifndef PLAT_H_INCLUDED
#define PLAT_H_INCLUDED
#include <string>
#include <vector>
#include <memory>

class afficheur;

class plat{
public:
    virtual ~plat() = default;
    virtual double prix() const = 0;
    //lien entre les classes afficheur et plat
    virtual void afficheAvec(const afficheur& aff) const = 0;
};

class platALaCarte: public plat{
public:
    platALaCarte(std::string nom, double prix, std::string type);
    std::string nom() const;
    std::string type() const;
    virtual double prix() const override;
    virtual void afficheAvec(const afficheur& aff) const override;
private:
    std::string d_nom;
    double d_prix;
    std::string d_type;
};


class entree : public platALaCarte
{
public:
    entree(std::string nom,double prix);
};

class platPrincipal : public platALaCarte
{
public:
    platPrincipal(std::string nom, double prix);
};


class menu : public plat
{
public:
    menu(const entree& e, const platPrincipal& pp);
    menu(const std::string& nomEntree, double prixEntree, const std::string& nomplatPrincipal, double prixplatPrincipal);
    virtual double prix() const override;
    entree entreeMenu() const;
    platPrincipal platPrincipalMenu() const;
    virtual void afficheAvec(const afficheur& aff) const override;
private:
    entree d_entree;
    platPrincipal d_platPrincipal;

};


class repas : public plat {
public:
    repas();
    int nombrePlats() const;
    const plat* platNumero(int i) const;
    void ajoute(std::unique_ptr<plat> p);
    virtual double prix() const override;
    virtual void afficheAvec(const afficheur& aff) const override;

private:
    std::vector<std::unique_ptr<plat>> d_plats;
};

#endif // PLAT_H_INCLUDED

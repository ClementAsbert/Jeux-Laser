#ifndef EMPLOYE_H
#define EMPLOYE_H

#include<string>
#include<iostream>

class employe {
public:
    virtual ~employe() = default;
  employe(const std::string& nom, double salaireMensuel);
  std::string nom() const;
  virtual double salaireMensuel() const;
  virtual void affiche(std::ostream& ost) const;
private:
    std::string d_nom;
    double d_salaireMensuel;

};

#endif // EMPLOYE_H

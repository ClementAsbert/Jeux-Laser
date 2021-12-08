#ifndef CALCULATEUR_H_INCLUDED
#define CALCULATEUR_H_INCLUDED
#include <vector>

class calculateur{
public:
    calculateur();
    void entre(double x);
    double resultat() const;
    void changeSigne();
    void addtionne();
    void soustrait();
private:
    std::vector<double> d_pile;
};

#endif // CALCULATEUR_H_INCLUDED

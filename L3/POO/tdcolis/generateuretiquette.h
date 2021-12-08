#ifndef GENERATEURETIQUETTE_H_INCLUDED
#define GENERATEURETIQUETTE_H_INCLUDED

#include <iostream>

class colis;
class colisexpress;
class generateuretiquette {
public:
    //virtual car on va les redefinir apres
    virtual void genereetiquettecolis(const colis& c, std::ostream& ost) const =0 ;// = 0 pcq je sais pas comment l'ecrire
    virtual void genereetiquettecolisexpress(const colisexpress& c, std::ostream& ost) const = 0;
    virtual ~generateuretiquette() = default;
};


#endif // GENERATEURETIQUETTE_H_INCLUDED

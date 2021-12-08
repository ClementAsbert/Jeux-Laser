#ifndef GENERATEURETIQUETTETEXTE_H_INCLUDED
#define GENERATEURETIQUETTETEXTE_H_INCLUDED

#include "generateuretiquette.h"
#include <iostream>
class generateuretiquettetexte : public generateuretiquette {
public:
    virtual void genereetiquettecolis(const colis& c, std::ostream& ost) const override;
    virtual void genereetiquettecolisexpress(const colisexpress& c, std::ostream& ost) const override;
};

#endif // GENERATEURETIQUETTETEXTE_H_INCLUDED

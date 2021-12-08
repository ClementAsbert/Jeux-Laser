#include "generateuretiquettetexte.h"
#include "colis.h"
#include "colisexpress.h"


void generateuretiquettetexte::genereetiquettecolis(const colis& c, std::ostream& ost) const
{
    ost<<"poids "<<c.poids()<<" prix" <<c.prix();
}

void generateuretiquettetexte::genereetiquettecolisexpress(const colisexpress& c, std::ostream& ost) const
{
    genereetiquettecolis(c, ost);
    ost<<"priorite "<<c.priorite();
}

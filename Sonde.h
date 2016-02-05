#ifndef SONDE_H
#define SONDE_H

#include "Astre.h"
#include "Matrice.h"

class Sonde
{
    public:
        Sonde(Astre* a, int nbA);
        virtual ~Sonde();
        int GetnbAstres() { return nbAstres; }
        void SetnbAstres(int val) { nbAstres = val; }
        Astre* Getastre() { return astre; }
        double Gett() { return t; }
        void Update(double h);
    protected:
    private:
        int nbAstres;
        Astre* astre;
        double t;
        Matrice d = Matrice(nbAstres,1);
        Matrice X = Matrice(2,1);
        Matrice Y = Matrice(2,1);
};

#endif // SONDE_H


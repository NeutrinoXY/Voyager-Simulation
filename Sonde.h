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
        Matrice** Getd() {return &d;}
        void Update(double h);
        double GetX(int i,int j) {return X.GetValue(i,j);};
        double GetY(int i,int j) {return Y.GetValue(i,j);};
    protected:
    private:
        int nbAstres;
        Astre* astre;
        double t;
        Matrice* d;
        Matrice X = Matrice(2,1);//On utilise X[0] pour la position et X[1] pour la vitesse selon Ox
        Matrice Y = Matrice(2,1);
};
#endif // SONDE_H

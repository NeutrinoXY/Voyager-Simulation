#ifndef SONDE_H
#define SONDE_H

#include "Astre.h"
#include "Matrice.h"

class Sonde
{
    public:
        Sonde(Astre* a, int nbA);
        virtual ~Sonde();
        int GetnbAstres() const {return nbAstres;}
        void SetnbAstres(int val) {nbAstres = val;}
        Astre* Getastre() const {return astre;}
        double Gett() const {return t;}
        Matrice Getd() const {return d;}
        void Update(double h);
        double GetX(int i,int j) const {return X.GetValue(i,j);};
        double GetY(int i,int j) const {return Y.GetValue(i,j);};
    protected:
    private:
        int nbAstres;
        Astre* astre;
        double t;
        Matrice d;
        Matrice X;//On utilise X[0] pour la position et X[1] pour la vitesse selon Ox
        Matrice Y;
};
#endif // SONDE_H

#ifndef ASTRE_H
#define ASTRE_H

#include <math.h>
#include "Matrice.h"
#include <iostream>

using namespace std;

class Astre
{
    public:
        Astre();
        virtual ~Astre();
        double Getmass() { return mass; }
        void Setmass(double val) { mass = val; }
        double Getradius() { return radius; }
        void Setradius(double val) { radius = val; }
        double Gettheta0() { return theta0; }
        void Settheta0(double val) { theta0 = val; }
        Matrice* GetX() {return &X;}
        double GetX(int a) {return X.GetValue(a, 0);}
        Matrice* GetY() {return &Y;}
        double GetY(int a) {return Y.GetValue(a, 0);}

        void Update(double t);
        void Definir(int numero);

    protected:
    private:
        double mass;
        double radius;
        Matrice X = Matrice(2,1);//On utilise X[0] pour la position et X[1] pour la vitesse selon Ox
        Matrice Y = Matrice(2,1);//On utilise Y[0] pour la position et Y[1] pour la vitesse selon Oy
        double theta0;
        double speed;
};

#endif // ASTRE_H

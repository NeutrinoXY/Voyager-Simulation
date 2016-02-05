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
        Matrice* GetX() {return &X;};
        Matrice* GetY() {return &Y;};
        void Update(double t);

    protected:
    private:
        double mass;
        double radius;
        Matrice X = Matrice(2,1);
        Matrice Y = Matrice(2,1);
        double theta0;
        double speed;
};

#endif // ASTRE_H

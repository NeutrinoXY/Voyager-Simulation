#include "Sonde.h"
#include "Astre.h"
#include <math.h>
#define G 1

Sonde::Sonde(Astre *a, int nbA)
{
    X.SetValue(0,0,100);
    t=0;
}

Sonde::~Sonde()
{
    //dtor
}

void Sonde::Update(double h)
{
    Matrice Xnew(2,1);
    Matrice C(2,2);
    Matrice* Xi;
    Matrice D(2,2);
    D.SetValue(0,0,1);
    D.SetValue(0,1,h);
    D.SetValue(1,0,1);

    for(int i=0; i<GetnbAstres(); i++)
    {
        astre[i].Update(t);
        Xi = astre[i].GetX();
        d.SetValue(i,0,sqrt(pow((*Xi).GetValue(0,0)-X.GetValue(0,0),2) + pow((*Xi).GetValue(0,1)-X.GetValue(0,1),2)));
    }

    for(int i=0; i<GetnbAstres(); i++)
    {
        C.SetValue(2,1,h*G*(astre[i].Getmass())/(pow(d.GetValue(i,0),3)));
        Xi = astre[i].GetX();
        Xnew = Xnew + C*(*Xi-X);
    }
    Xnew = Xnew + D*X;
    X=Xnew;
    t=t+h;
}

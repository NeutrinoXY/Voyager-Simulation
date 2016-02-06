#include "Sonde.h"
#include "Astre.h"
#include <iostream>
#include <math.h>
#define G 0.1

using namespace std;

Sonde::Sonde(Astre *a, int nbA)
{
    astre=a;
    X.SetValue(0,0,10);
    Y.SetValue(0,0,0);
    X.SetValue(1,0,0);
    Y.SetValue(1,0,55);
    t=0;
    nbAstres=nbA;
    d = new Matrice(nbA,1);
}

Sonde::~Sonde()
{
    //dtor
}

void Sonde::Update(double h)
{
    Matrice Xnew(2,1);
    Matrice Ynew(2,1);
    Matrice C(2,2);
    Matrice* Xi;
    Matrice* Yi;
    Matrice D(2,2);
    D.SetValue(0,0,1);
    D.SetValue(0,1,h);
    D.SetValue(1,1,1);

    for(int i=0; i<GetnbAstres(); i++)
    {
        astre[i].Update(t);
        Xi = astre[i].GetX();
        Yi = astre[i].GetY();
        (*d).SetValue(i,0,sqrt(pow((*Xi).GetValue(0,0)-X.GetValue(0,0),2) + pow((*Yi).GetValue(0,0)-Y.GetValue(0,0),2)));
        //cout<<"d="<<sqrt(pow((*Xi).GetValue(0,0)-X.GetValue(0,0),2) + pow((*Yi).GetValue(0,0)-Y.GetValue(0,0),2))<<endl;
        //cout<<"x="<<X.GetValue(0,0)<<endl;
        //cout<<"y="<<Y.GetValue(0,0)<<endl;
    }

    for(int i=0; i<GetnbAstres(); i++)
    {
        C.SetValue(1,0,h*G*(astre[i].Getmass())/(pow((*d).GetValue(i,0),3)));
        //cout<<"AHAHAH"<<(*Xi-X).GetValue(0,0)<<endl;
        //cout<<"OHOHOH"<<(*Xi-X).GetValue(0,1)<<endl;
        //cout<<"HIHBIH"<<h*G*(astre[i].Getmass())/(pow((*d).GetValue(i,0),3))<<endl;
        //cout<<"C="<<C.GetValue(1,0)<<endl;
        Xi = astre[i].GetX();
        Yi = astre[i].GetY();

        Xnew = Xnew + (C*(*Xi-X));
        Ynew = Ynew + (C*(*Yi-Y));

        //cout<<"AZAZSQZSAZA"<<(C*Y).GetValue(0,1)<<endl;
    }
    Xnew = Xnew + D*X;
    Ynew = Ynew + D*Y;
    //cout<<"Xnew="<<Xnew.GetValue(1,0)<<endl;
    //cout<<"Ynew="<<Ynew.GetValue(1,0)<<endl;
    X=Xnew;
    Y=Ynew;
    t=t+h;
}



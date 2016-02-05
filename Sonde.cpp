#include "Sonde.h"
#include "Astre.h"
#include <iostream>
#include <math.h>
#define G 1

using namespace std;

Sonde::Sonde(Astre *a, int nbA)
{
    astre=a;
    X.SetValue(0,0,100);
    t=0;
    nbAstres=nbA;
    Matrice x(nbA, 1);
    d = new Matrice(nbA,1);
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
    Matrice Y(2,1);
    D.SetValue(0,0,1);
    D.SetValue(0,1,h);
    D.SetValue(1,1,1);

    for(int i=0; i<GetnbAstres(); i++)
    {
        astre[i].Update(t);
        Xi = astre[i].GetX();
        (*d).SetValue(i,0,sqrt(pow((*Xi).GetValue(0,0)-X.GetValue(0,0),2) + pow((*Xi).GetValue(0,1)-X.GetValue(0,1),2)));
        cout<<"d="<<sqrt(pow((*Xi).GetValue(0,0)-X.GetValue(0,0),2) + pow((*Xi).GetValue(0,1)-X.GetValue(0,1),2))<<endl;
        cout<<"x="<<X.GetValue(0,0)<<endl;
    }

    for(int i=0; i<GetnbAstres(); i++)
    {
        C.SetValue(1,0,h*G*(astre[i].Getmass())/(pow((*d).GetValue(i,0),3)));
        //cout<<"AHAHAH"<<(*Xi-X).GetValue(0,0)<<endl;
        //cout<<"OHOHOH"<<(*Xi-X).GetValue(0,1)<<endl;
        //cout<<"HIHBIH"<<h*G*(astre[i].Getmass())/(pow((*d).GetValue(i,0),3))<<endl;
        //cout<<"C="<<C.GetValue(1,0)<<endl;
        Xi = astre[i].GetX();
        Y = *Xi-X;
        Xnew = Xnew + (C*Y);

        //cout<<"AZAZSQZSAZA"<<(C*Y).GetValue(0,1)<<endl;
    }
    Xnew = Xnew + D*X;
    cout<<"Xnew="<<Xnew.GetValue(1,0)<<endl;
    X=Xnew;
    t=t+h;
}

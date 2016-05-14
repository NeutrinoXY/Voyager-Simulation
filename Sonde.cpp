#include "Sonde.h"
#include "Astre.h"
#include <iostream>
#include <math.h>
#define Masse 5.9736×1000000000000000000000000
#define Distance 149600000000      //distance Terre Soleil
#define Temps 60*60*24*365.25      //année
#define G  0.00011858656632 //



using namespace std;

Sonde::Sonde(Astre *a, int nbA) : X(Matrice(2,1)), Y(Matrice(2,1)), d(Matrice(nbA,1))
{
    astre=a;
    X.SetValue(0,0,1);
    Y.SetValue(0,0,0);
    X.SetValue(1,0,0);
    Y.SetValue(1,0,9);
    t=0;
    nbAstres=nbA;
}

Sonde::~Sonde()
{

}

void Sonde::Update(double h)
{

    Matrice Xnew(2,1);
    Matrice Ynew(2,1);
    Matrice Temp(2,1);
    Matrice C(2,2);
    Matrice* Xi;
    Matrice* Yi;
    Matrice D(2,2);
    D.SetValue(0,0,1);
    D.SetValue(0,1,h);
    D.SetValue(1,1,1);


	//On calcule les distances entre la sonde et chaque astre
    for(int i=0; i<GetnbAstres(); i++)
    {
        astre[i].Update(t);
        Xi = astre[i].GetX();
        Yi = astre[i].GetY();


        //Distance entre la sonde et l'astre i
        d.SetValue(i,0,sqrt(pow((*Xi).GetValue(0,0)-X.GetValue(0,0),2) + pow((*Yi).GetValue(0,0)-Y.GetValue(0,0),2)));
    }


    for(int i=0; i<GetnbAstres(); i++)
    {
    	//Ceci est l'influence de l'astre i sur la sonde avec l'approximation de la methode d'Euler
        C.SetValue(1,0,h*G*(astre[i].Getmass())/(pow(d.GetValue(i,0),3))); // (C = pas*G*M/(R^3) )
        Xi = astre[i].GetX();
        Yi = astre[i].GetY();


		//On l'ajoute à la position actuelle et à l'influence des autres astres

        Temp = C*(*Xi);
        Xnew.SetValue(0,0,Xnew.GetValue(0,0)+Temp.GetValue(0,0)-X.GetValue(0,0));
        Xnew.SetValue(0,1,Xnew.GetValue(0,1)+Temp.GetValue(0,1)-X.GetValue(0,1));
        Temp = C*(*Yi);
        Ynew.SetValue(0,0,Ynew.GetValue(0,0)+Temp.GetValue(0,0)-Y.GetValue(0,0));
        Ynew.SetValue(0,1,Ynew.GetValue(0,1)+Temp.GetValue(0,1)-Y.GetValue(0,1));


        //Temp = Xnew + ((C*(*Xi)-X));
        //Xnew = Temp;
        //Temp = Ynew + ((C*(*Yi)-Y));
        //Ynew = Temp;

    }
    Temp = D*X;
    X.SetValue(0,0,Xnew.GetValue(0,0)+Temp.GetValue(0,0));
    X.SetValue(0,1,Xnew.GetValue(0,1)+Temp.GetValue(0,1));
    Temp = D*Y;
    Y.SetValue(0,0,Ynew.GetValue(0,0)+Temp.GetValue(0,0));
    Y.SetValue(0,1,Ynew.GetValue(0,1)+Temp.GetValue(0,1));
    cout<<"Bug?"<<endl;
    t=t+h;
    cout<<"Bug?"<<endl;

}

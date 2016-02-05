#include <iostream>
#include "Sonde.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Matrice A(2,2), B(2,1), C(2,1);
    Astre* astres = new Astre[1];
    cout<<"lol"<<endl;
    Sonde sonde(astres, 1);
    cout<<sonde.Gett()<<endl;
    cout<<sonde.GetnbAstres()<<endl;

    A.SetValue(0,0,1);    A.SetValue(0,1,4);
    A.SetValue(1,0,1);    A.SetValue(1,1,1);

    B.SetValue(0,0,4);    /*B.SetValue(0,1,1);*/
    B.SetValue(1,0,1);   /* B.SetValue(1,1,0);*/

    C = A*B;

    cout << "A : " << endl << A.GetValue(0,0) << " " << A.GetValue(0,1) << endl;
    cout << A.GetValue(1,0) << " " << A.GetValue(1,1) << endl << endl;
    cout << "B : " << endl << B.GetValue(0,0) << endl << B.GetValue(1,0) << endl << endl;
    cout << "C : " << endl << C.GetValue(0,0) << " " << C.GetValue(1,0) << endl << endl;

    for(int j=0; j<2500; j++)
    {

        cout << "O"<<endl;
        Matrice** d;
        d = sonde.Getd();
        for (int i=0; i<2*(**d).GetValue(0,0); i++)
            cout << " ";

        cout << "(°;...;°)Maxim(sans e)GAY" << endl;
        sonde.Update(0.001);
    }

    return 0;
}

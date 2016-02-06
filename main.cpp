#include <iostream>
#include <stdlib.h>

#include "Sonde.h"

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Matrice A(2,2), B(2,1), C(2,1);
    Astre* astres = new Astre[1];
    //cout<<"lol"<<endl;
    Sonde sonde(astres, 1);
    //cout<<sonde.Gett()<<endl;
    //cout<<sonde.GetnbAstres()<<endl;

    A.SetValue(0,0,1);    A.SetValue(0,1,4);
    A.SetValue(1,0,1);    A.SetValue(1,1,1);

    B.SetValue(0,0,4);    /*B.SetValue(0,1,1);*/
    B.SetValue(1,0,1);   /* B.SetValue(1,1,0);*/

    C = A*B;

    //cout << "A : " << endl << A.GetValue(0,0) << " " << A.GetValue(0,1) << endl;
    //cout << A.GetValue(1,0) << " " << A.GetValue(1,1) << endl << endl;
    //cout << "B : " << endl << B.GetValue(0,0) << endl << B.GetValue(1,0) << endl << endl;
    //cout << "C : " << endl << C.GetValue(0,0) << " " << C.GetValue(1,0) << endl << endl;

    /*/for(int t=0; t<2500; t++)
    {
        //system("cls");
        cout << "O"<<endl;
        Matrice** d;
        d = sonde.Getd();
        for (int i=0; i<(**d).GetValue(0,0)/2; i++)
            cout << " ";

        cout << "(°;...;°)" << endl;
        sonde.Update(0.001);
    }/*/
    for(int t=0; t<2500000; t++)
    {
        system("cls");
        cout << sonde.GetX(0,0) << "   " << sonde.GetX(1,0) << endl << sonde.GetY(0,0) << "   " << sonde.GetY(1,0) << endl;
        for(int i=0; i<60; i++)
        {
            if (i==32)
            {
                if(i==32+(int)sonde.GetY(0,0)/10)
                {
                    for(int j=0; j<237; j++)
                    {
                        if (j==113+(int)sonde.GetX(0,0))
                            cout << "X";
                        else if (j==113)
                            cout << "O";
                        else
                            cout << " ";
                    }
                }
                else
                    for(int j=0; j<236; j++)
                    {
                        if (j==113)
                            cout << "O";
                        else
                            cout << " ";
                    }
            }
            else if (i==32+(int)sonde.GetY(0,0)/10)
            {
                cout << endl;
                for(int j=0; j<236; j++)
                {
                    if (j==113+(int)sonde.GetX(0,0))
                        cout << "X";
                    else
                        cout << " ";
                }
            }
            else
            {
                cout << endl;
                /*/for(int j=0; j<236; j++)
                    cout << " ";
                /*/
            }
        }
    sonde.Update(0.01);
    if (!(t%1000))
        cin.ignore(); // Pause
    }

    return 0;
}

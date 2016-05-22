#include <iostream>
#include <stdlib.h>

#include "Sonde.h"

using namespace std;

/***************************************/
/*                                     */
/*                                     */
/*                                     */
/*   METTRE LA CONSOLE EN PLEIN ECRAN  */
/*       PUIS APPUYER SUR ENTREE       */
/*                                     */
/*                                     */
/*                                     */
/***************************************/

int main()
{
	//création du Soleil
    Astre* astres = new Astre[1]; 



    Sonde sonde(astres, 1);

	//Affichage des positions
    //cout<<sonde.Gett()<<endl;
    //cout<<sonde.GetnbAstres()<<endl;



	//Interface graphique 2D
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
    for(int t=0; t<250000000; t++)
    {
        if (!(t%1000))
        {
            system("cls");
            cout << sonde.GetX(0,0) << "   " << sonde.GetX(1,0) << endl << sonde.GetY(0,0) << "   " << sonde.GetY(1,0) << endl;
            for(int i=0; i<60; i++)
            {
                if (i==32)
                {
                    if(i==32+(int)sonde.GetY(0,0)/2)
                    {
                        for(int j=0; j<237; j++)
                        {
                            if (j==118+(int)sonde.GetX(0,0))
                                cout << "X";
                            else if (j==118)
                                cout << "O";
                            else if (j > 118 && j > 118+(int)sonde.GetX(0,0))
                            {
                                cout << endl;
                                j = 237;
                            }
                            else
                                cout << " ";
                        }
                    }
                    else
                        for(int j=0; j<236; j++)
                        {
                            if (j==118)
                            {
                                cout << "O" << endl;
                            }
                            else
                                cout << " ";
                        }
                }
                else if (i==32+(int)sonde.GetY(0,0)/2)
                {
                    cout << endl;
                    for(int j=0; j<236; j++)
                    {
                        if (j==118+(int)sonde.GetX(0,0))
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
        }
    sonde.Update(0.00001); //Mise à jour de la sonde
    if (!(t%1000000000000))
        cin.ignore(); // Pause
    }

    return 0;
}

#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <iostream>
#include "Astre.h"
#include "Sonde.h"

#define ZOOM 25


/***************************************/
/*                                     */
/*                                     */
/*                                     */
/*   PLANETES ACTIVES :                */
/*       0 ,3, 5, 6, 7                 */
/*                                     */
/*                                     */
/*                                     */
/***************************************/

int main ( int argc, char** argv )
{

    while(1){

    double a=0;
    double t=0, pas=0.00001, distance = 0, dmin = 100;

    Astre* astres = new Astre[5];
    astres[0].Definir(0);
    astres[1].Definir(3);
    astres[2].Definir(5);
    astres[3].Definir(6);
    astres[4].Definir(7);


    Sonde sonde(astres, 5);

    cout<<"New Theta0 "<<endl;
    cin >> a;
    astres[2].Settheta0(a);



    // program main loop
    bool done = false;
    while (distance < 20){
        t+=pas;
        for (int i=0; i<5; i++){
            astres[i].Update(t);
        }
        sonde.Update(pas);

        distance = sqrt(pow(sonde.GetX(0,0)-astres[2].GetX(0),2) + pow(sonde.GetY(0,0)-astres[2].GetY(0),2));
        if(distance<dmin){
            dmin=distance;
        }

    } // end main loop

    cout<<dmin<<endl;

    }

    return 0;
}

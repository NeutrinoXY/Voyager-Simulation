#include "Astre.h"

Astre::Astre() : X(Matrice(2,1)), Y(Matrice(2,1))
{
    mass = 333054.253182; // Par rapport a la Terre

	// Le Soleil ne se déplace pas
	radius = 0;
    theta0 = 0;
    speed = 0;
}


void Astre::Definir(int numero)
{
    switch (numero)
      {
         case 0: // SOLEIL
            mass = 333054.253182; // Par rapport a la Terre
            // Le Soleil ne se déplace pas
            radius = 0;
            theta0 = 0;
            speed = 0;
            break;


         case 3: //TERRE
            mass = 0;
            radius = 1;
            theta0 = 0;
            speed = 1*(2*M_PI);
            break;


         case 5: //JUPITER
            mass = 317.8;
            radius = 5.20336301;
            theta0 = 1.6265;
            speed = radius*(2*M_PI)/11.862;
            break;

        case 6: //SATURNE
            mass = 95.152;
            radius = 9.554909;
            theta0 = 3.14;
            speed = radius*(2*M_PI)/29.453077344;
            break;


        case 7: //URANUS
            mass = 14.536;
            radius = 19.189165;
            theta0 = 2.142;
            speed = radius*(2*M_PI)/84.016846;
            break;


         default:
            mass = 333054.253182; // Par rapport a la Terre
            // Le Soleil ne se déplace pas
            radius = 0;
            theta0 = 0;
            speed = 0;
            break;
      }


}


Astre::~Astre()
{
    //dtor
}

void Astre::Update(double t)
{
    if (radius)//Pour se proteger du cas du soleil
    {
        X.SetValue(0,0, radius*cos(theta0+t*speed/radius));
        Y.SetValue(0,0, radius*sin(theta0+t*speed/radius));
        X.SetValue(0,1, speed*sin(theta0+t*speed/radius));
        Y.SetValue(0,1, -speed*cos(theta0+t*speed/radius));
    }
}

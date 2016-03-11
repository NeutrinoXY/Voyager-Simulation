#include "Astre.h"

Astre::Astre()
{
    mass = 333054.253182; // Par rapport a la Terre
    
	// Le Soleil ne se déplace pas
	radius = 0;
    theta0 = 0;
    speed = 0;
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

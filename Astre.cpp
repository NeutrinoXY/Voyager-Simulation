#include "Astre.h"

Astre::Astre()
{
    mass = 333054.253182; // par rapport a la Terre
    radius = 0; // distance Terre Soleil
    double* p = new double[2];
    p[0]=0;
    p[1]=0;
    theta0 = 0;
}

Astre::~Astre()
{
    //dtor
}

void Astre::Update(double t)
{
    if (radius)
    {
        X.SetValue(0,0, radius*cos(theta0+t*speed/radius));
        Y.SetValue(0,0, radius*sin(theta0+t*speed/radius));
        X.SetValue(0,1, speed*cos(theta0+t*speed/radius));
        Y.SetValue(0,1, speed*sin(theta0+t*speed/radius));
    }
}


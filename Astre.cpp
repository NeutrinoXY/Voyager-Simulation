#include "Astre.h"

Astre::Astre()
{
    mass = 333054.253182; // par rapport a la Terre
    radius = 0.00465475825; // distance Terre Soleil
    pos[0] = 0;
    pos[1] = 0;
    theta0 = 0;
    speed = 0;
}

Astre::~Astre()
{
    //dtor
}


#include "MoveObj.h"


CMoveObj::CMoveObj()
{
    mass = 1;
    pos = 0;
    vel = 0;
    TS = 0.0001;
    TS2 = TS * TS * 0.5;
}

CMoveObj::~CMoveObj()
{

}

void CMoveObj::SetInitState(double p,double v)
{
    pos = p;
    vel = v;
}

double CMoveObj::OnStep(double f)
{
    double a = f / mass;
    vel += TS * a;
    pos +=  a * TS + TS2 * a;
    return pos;
}


double CMoveObj::GetPos()
{
    return pos;
}
double CMoveObj::GetVel()
{
    return vel;
}

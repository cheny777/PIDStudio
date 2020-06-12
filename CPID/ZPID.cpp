
#include "ZPID.h"


CZPID::CZPID()
{

}

CZPID::~CZPID()
{

}

double CZPID::OnPid(double e)
{
    return zt.OnSerial(e);
}

bool CZPID::InitPid(double KP,double Ts,double Td,double Ti)
{
    if(KP <= 0.0 + 1.0E-2)
    {
        return false;
    }
    if(Ts <1.0E-8)
    {
        return false;
    }
    if(Td <1.0E-8)
    {
        return false;
    }
    if(Ti <1.0E-8)
    {
        return false;
    }
    double ki = KP * Ts / Ti;
    double kd = KP * Td / Ts;
    double a[3];
    double p1,p2,p0;
    p2 = kd;
    p1 = -KP - 2 * p2;
    p0 = KP + ki + kd;
    a[0] = p0;
    a[1] = p1;
    a[2] = p2;
    double b[2];
    b[0] = 1;
    b[1] = -1;
    return zt.InitZT(a,3,b,2);
}

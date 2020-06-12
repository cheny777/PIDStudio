
#include "PID.h"


CPID::CPID()
{
    init(1,1,1);
}

CPID::~CPID()
{

}

void CPID::init(double p,double i,double d)
{
    frist_tag = true;
    i_base = 0;
    d_err = 0;
    old_err = 0;
    ts = 0.0025;
    kp = p;
    ki = i;
    kd = d;
}

double CPID::onErr(double e)
{
    if(frist_tag)
    {
        frist_tag = true;
        old_err = e;
    }
    d_err = (e - old_err ) / ts;
    old_err = e;
    i_base += e;
    return kp*e + ki * i_base + kd * d_err;
}


#include "PID.h"



CPID::CPID()
{
    kp = 1;
    kd = 0;
    ki = 0;
    ts = 0.001;
    old_err = 0;
    frist_tag = true;

    ibase = 0;
}

CPID::~CPID()
{

}

double CPID::OnControl(double e)
{
    ve = (e - old_err) / ts;
    ibase += e;
    if(frist_tag == true)
    {
        frist_tag = false;
        ve = 0.0;
    }
    return kp * e + kd * ve + ki * ibase * ts;

}
void CPID::SetPID(double vkp,double vki,double vkd)
{
    kp = vkp;
    kd = vkd;
    ki = vki;
    ibase = 0;
}

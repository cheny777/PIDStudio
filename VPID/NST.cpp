
#include "NST.h"
#include "math.h"


CNST::CNST()
{

    b11 = 0;
    b12 = 0;
    a11 = 0;
    a12 = 0;


    b21 = 0;
    b22 = 0;
    a21 = 0;
    a22 = 0;


    z1_1 = 0;
    z1_2 = 0;
    z2_1 = 0;
    z2_2 = 0;

    x[0] = 0;
    x[1] = 0;
    x[2] = 0;

    y[0] = 0;
    y[1] = 0;
    y[2] = 0;
}

CNST::~CNST()
{

}

void CNST::setFreq(double smpfrq,double nstfrq)
{
    double omg = (CNSTPI*2 * nstfrq) / smpfrq;
    double co = cos(omg);
    a[0] = 1;
    a[1] = -2 * co;
    a[2] = 1;
    b[0] = 1;
    b[1] = -2*0.998* co;
    b[2] = 0.998*0.998;


}

double CNST::on_data(double v)
{
    double tmp1 = (v    + a11 * z1_1 + a12 * z1_2);

    z1_2 = z1_1;
    z1_1 = tmp1;


    double tmp2 = (tmp1 + a21 * z2_1 + a22 * z2_2);

    z2_2 = z2_1;
    z2_1 = tmp2;


    return tmp2;

}

double CNST::on_data2(double v)
{
    x[2] = x[1];
    x[1] = x[0];
    x[0] = v;

    y[0] = x[0] + a[1]*x[1] + a[2]*x[2] - b[1]*y[1] - b[2]*y[2];
    y[2] = y[1];
    y[1] = y[0];
    return y[0];

}

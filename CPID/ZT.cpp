
#include "ZT.h"


CZT::CZT()
{

    x_order = 0;
    y_order = 0;
}

CZT::~CZT()
{

}

double CZT::OnSerial(double v)
{
    x_serial[x_pos] = v;
    long x_d_pos;
    long i;
    double xv = 0;
    for(i = 0; i < x_order; i ++)
    {
        x_d_pos = (x_pos - i + x_order )%x_order;
        xv += x_serial[x_d_pos] * x_para[i];
    }
    x_pos += 1;
    x_pos %= x_order;

    y_serial[y_pos] = 0;
    long y_d_pos;
    double yv = 0;

    for(i = 0; i < y_order; i ++)
    {
        y_d_pos = (y_pos - i + y_order )%y_order;
        yv += y_serial[y_d_pos] * y_para[i];
    }
    double ret =  xv - yv;
    y_serial[y_pos] = ret;
    y_pos += 1;
    y_pos %= y_order;
    return ret;
}

bool CZT::InitZT(double * a,long n,double * b,long m)
{
    if(n <=0 || n >= MAXZORDER || m <=0 || m >= MAXZORDER)
    {
        return false;
    }
    if(b[0]> 1.0 + 1.0E-4 || b[0] < 1.0 - 1.0E-4)
    {
        return false;
    }
    x_order = n;
    y_order = m;
    long i;
    for( i = 0; i < MAXZORDER ; i ++)
    {
        x_serial[i] = 0;
        y_serial[i] = 0;
        x_para[i] = 0;
        y_para[i] = 0;
        if(i<n)
        {
            x_para[i] = a[i];
        }
        if(i < m)
        {
            y_para[i] = b[i];
        }
    }
    x_pos = 0;
    y_pos = 0;
    return true;
}


#ifndef _ZT_H_
#define _ZT_H_

#define MAXZORDER 100

class CZT
{
public:
    CZT();
    virtual ~CZT();
    bool InitZT(double * a,long n,double * b,long m);
    double OnSerial(double v);
protected:
    double x_serial[MAXZORDER];
    double y_serial[MAXZORDER];
    double x_para[MAXZORDER];
    double y_para[MAXZORDER];
    long x_order;
    long y_order;
    long   x_pos;
    long   y_pos;
};

#endif

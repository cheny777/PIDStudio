#ifndef _NST1_H_
#define _NST1_H_

#define CNSTPI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093845

class CNST
{
public:
    double on_data2(double v);
    CNST();
    virtual ~CNST();
    double on_data(double v);
    void setFreq(double smpfrq,double nstfrq);
protected:
    double b11,b12,a11,a12;
    double b21,b22,a21,a22;
    double z1_1;
    double z1_2;
    double z2_1;
    double z2_2;
    double a[3];
    double b[3];

    double x[3];
    double y[3];
};

#endif

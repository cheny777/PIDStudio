
#ifndef _PID_H_
#define _PID_H_


class CPID
{
public:
    CPID();
    virtual ~CPID();
    void init(double p,double i,double d);
    double onErr(double e);
protected:
    bool frist_tag;
    double i_base;
    double d_err;
    double old_err;
    double ts;
    double kp;
    double ki;
    double kd;

};

#endif

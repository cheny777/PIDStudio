
#ifndef _PID_H_
#define _PID_H_


class CPID
{
public:
    CPID();
    virtual ~CPID();
    double OnControl(double e);
    void SetPID(double vkp,double vki,double vkd);
protected:
    double kp;
    double ki;
    double kd;
    double old_err;
    double ve;
    double ibase;
    double ts;
    bool frist_tag;

};

#endif

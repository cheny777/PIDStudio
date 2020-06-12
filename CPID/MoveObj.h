
#ifndef _MOVEOBJ_H_
#define _MOVEOBJ_H_



class CMoveObj
{
public:
    CMoveObj();
    virtual ~CMoveObj();
    void SetInitState(double p,double v);
    double OnStep(double f);
    double GetPos();
    double GetVel();
protected:
    double mass;
    double pos;
    double vel;
    double TS;
    double TS2;
};

#endif

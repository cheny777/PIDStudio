
#ifndef _ZPID_H_
#define _ZPID_H_

#include "ZT.h"
class CZPID
{
public:
    CZPID();
    virtual ~CZPID();
    bool InitPid(double KP,double Ts,double Td,double Ti);
    double OnPid(double e);
protected:
    CZT zt;

};

#endif

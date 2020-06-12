// ADPCONTROL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PID.h"
#include "MoveObj.h"
#include "ZT.h"
#include "ZPID.h"
int test3()
{
    CZPID zpid;
    zpid.InitPid(1.0,1.0,0.12,0.17);
     for(long i = 0; i < 10; i ++)
    {
        double v;

        if(i == 1){ v= zpid.OnPid(1);}
        if(i != 1){ v= zpid.OnPid(0);}


        printf("%lf\n",v);
    }
     return 1;

};

int test1()
{
    FILE * fp;
    fp = fopen("d:\\vibcont.txt","w");
    CMoveObj mo;
    CPID pid_p_v;
    CPID pid_v_t;
    double pos = 0.0;
    double e;
    double c;
    double tv;

    pid_p_v.SetPID(100,100,0.00);
    pid_v_t.SetPID(10,0,0.00);

    e = 0;
    for(long i = 0; i < 10000; i ++)
    {
        if(i>=0 && i<= 1000)
        {
            pos += 0.001;
        }
        if(i>=3000 && i <= 4000)
        {
            pos -= 0.001;
        }
        e = pos - mo.GetPos();
        tv = pid_p_v.OnControl(e);
        c  = pid_v_t.OnControl(tv - mo.GetVel());
        for(long k = 0; k < 10; k ++)
        {
           mo.OnStep(c);
        }

        fprintf(fp,"%lf %lf %lf\n",pos,pos - e,e);
    }

    fclose(fp);
    return 0;
}

#define A_SIZE 1
#define B_SIZE 2
int test2()
{
    CZT zt;
    double a[10];
    double b[10];
    a[0] = 0;
    a[1] = 1;
    b[0] = 1;
    b[1] = -0.5;
    b[2] = 0.5;
    zt.InitZT(a,2,b,2);
    for(long i = 0; i < 10; i ++)
    {
        double v;

        if(i == 1){ v= zt.OnSerial(1);}
        if(i != 1){ v= zt.OnSerial(0);}


        printf("%lf\n",v);
    }
    return 1;
}

int main(int argc, char* argv[])
{
    test1();

    return 0;
}


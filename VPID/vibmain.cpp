// vibration_control_sim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "NST.h"

#include "PID.h"
#include "MoveObj.h"

#define SIMPI 3.141592653589793

#include "math.h"


void sim1()
{

    FILE * fp;
    fp = fopen("d:\\sim_data\\viberation\\sim1.txt","w");
    if(fp == NULL)
    {
        printf("open file error\n");
        return;
    }
    CMoveObj mobj1;
    CMoveObj mobj2;
    CPID pid;
    mobj1.SetInitState(1,0);
    mobj2.SetInitState(2,0);
    pid.init(100,0,0);

    double d;
    double di;
    long size = 10000;
    double v;
    double t = 0.0025;

    double f = 0;
    double pos;
    double pos2;
    double len = 1;
    double df;
    double k = 5000;
    for(long i = 0; i < 2 * size; i ++)
    {

        t += 0.0001;
        di = i;
        if(i < size)
        {
            d = cos(di / size * 2 * SIMPI) + 1;
        }


        df = (len - 1.0 )*k;
        pos = mobj1.OnStep(f + df);
        pos2 = mobj2.OnStep(-df);

        len = pos2 - pos;


        if(t >= 0.0025)
        {
            t = 0;
            f = pid.onErr(d - pos2);
        }
        double ii = i; ii *= 0.001; fprintf(fp,"X%lf Y%lf\n",ii,d);fprintf(fp,"X%lf Y%lf\n",ii,pos2);
    }

    fclose(fp);
    printf("sim over\n");
}


void sim2()
{

    FILE * fp;
    fp = fopen("d:\\sim_data\\viberation\\sim2.txt","w");
    if(fp == NULL)
    {
        printf("open file error\n");
        return;
    }
    CMoveObj mobj1;
    CMoveObj mobj2;
    CPID pid;
    mobj1.SetInitState(1,0);
    mobj2.SetInitState(2,0);
    pid.init(100,0,0);

    double d;
    double di;
    long size = 10000;
    double v;
    double t = 0.0025;

    double f = 0;
    double pos;
    double pos2;
    double len = 1;
    double df;
    double k = 5;
    for(long i = 0; i < 2 * size; i ++)
    {

        t += 0.0001;
        di = i;
        if(i < size)
        {
            d = cos(di / size * 2 * SIMPI) + 1;
        }


        df = (len - 1.0 )*k;
        pos = mobj1.OnStep(f + df);
        pos2 = mobj2.OnStep(-df);

        len = pos2 - pos;


        if(t >= 0.0025)
        {
            t = 0;
            f = pid.onErr(d - pos2);
        }
        double ii = i; ii *= 0.001; fprintf(fp,"X%lf Y%lf\n",ii,d);fprintf(fp,"X%lf Y%lf\n",ii,pos2);
    }

    fclose(fp);
    printf("sim over\n");
}

void sim3()
{

    FILE * fp;
    fp = fopen("d:\\sim_data\\viberation\\sim3.txt","w");
    if(fp == NULL)
    {
        printf("open file error\n");
        return;
    }
    CMoveObj mobj1;
    CMoveObj mobj2;
    CPID pid;
    mobj1.SetInitState(1,0);
    mobj2.SetInitState(2,0);
    pid.init(100,0,0);

    double d;
    double di;
    long size = 10000;
    double v;
    double t = 0.0025;

    double f = 0;
    double pos;
    double pos2;
    double len = 1;
    double df;
    double k = 15;
    for(long i = 0; i < 2 * size; i ++)
    {

        t += 0.0001;
        di = i;
        if(i < size)
        {
            d = cos(di / size * 2 * SIMPI) + 1;
        }


        df = (len - 1.0 )*k;
        pos = mobj1.OnStep(f + df);
        pos2 = mobj2.OnStep(-df);

        len = pos2 - pos;


        if(t >= 0.0025)
        {
            t = 0;
            f = pid.onErr(d - pos2);
        }
        double ii = i; ii *= 0.001; fprintf(fp,"X%lf Y%lf\n",ii,d);fprintf(fp,"X%lf Y%lf\n",ii,pos2);
    }

    fclose(fp);
    printf("sim over\n");
}

void sim4()
{

    FILE * fp;
    fp = fopen("d:\\sim_data\\viberation\\sim4.txt","w");
    if(fp == NULL)
    {
        printf("open file error\n");
        return;
    }
    CMoveObj mobj1;
    CMoveObj mobj2;
    CPID pid;
    mobj1.SetInitState(1,0);
    mobj2.SetInitState(2,0);
    pid.init(50,0,0);

    double d;
    double di;
    long size = 10000;
    double v;
    double t = 0.0025;

    double f = 0;
    double pos;
    double pos2;
    double len = 1;
    double df;
    double k = 5;
    for(long i = 0; i < 2 * size; i ++)
    {

        t += 0.0001;
        di = i;
        if(i < size)
        {
            d = cos(di / size * 2 * SIMPI) + 1;
        }


        df = (len - 1.0 )*k;
        pos = mobj1.OnStep(f + df);
        pos2 = mobj2.OnStep(-df);

        len = pos2 - pos;


        if(t >= 0.0025)
        {
            t = 0;
            f = pid.onErr(d - pos2);
        }
        double ii = i; ii *= 0.001; fprintf(fp,"X%lf Y%lf\n",ii,d);fprintf(fp,"X%lf Y%lf\n",ii,pos2);
    }

    fclose(fp);
    printf("sim over\n");
}


void sim5()
{
    CNST  nst;
    nst.setFreq(10000,2100);

    FILE * fp;
    fp = fopen("d:\\sim_data\\viberation\\sim5.txt","w");
    if(fp == NULL)
    {
        printf("open file error\n");
        return;
    }
    CMoveObj mobj1;
    CMoveObj mobj2;
    CPID pid;
    mobj1.SetInitState(1,0);
    mobj2.SetInitState(2,0);
    pid.init(50,0,0);

    double d;
    double di;
    long size = 10000;
    double v;
    double t = 0.0025;

    double f = 0;
    double pos;
    double pos2;
    double len = 1;
    double df;
    double k = 5;
    for(long i = 0; i < 2 * size; i ++)
    {

        t += 0.0001;
        di = i;
        if(i < size)
        {
            d = cos(di / size * 2 * SIMPI) + 1;
        }


        df = (len - 1.0 )*k;
        pos = mobj1.OnStep(f + df);
        pos2 = mobj2.OnStep(-df);

        len = pos2 - pos;


        if(t >= 0.0025)
        {
            t = 0;
            f = pid.onErr(d - pos2);
            f = nst.on_data2(f);
        }
        double ii = i; ii *= 0.001 ;fprintf(fp,"X%lf Y%lf\n",ii,d);fprintf(fp,"X%lf Y%lf\n",ii,pos2);
    }

    fclose(fp);
    printf("sim over\n");
}
int main(int argc, char* argv[])
{
    sim1();
    sim2();
    sim3();
    sim4();
    sim5();
    return 0;
}


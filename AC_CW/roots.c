#include "roots.h"

int  sign_f(double x, double (*f)(double))
{
    return f(x) == 0 ? 0 : (f(x) < 0 ? -1: +1);
}

double root(double (*f)(double), double xl, double xr, double eps) 
{
    int stepcount = 0;
    double xm;
    while(fabs(xr - xl) > eps) 
    { 
        stepcount++;
        xm=(xl + xr)/2; 
        if(sign_f(xl, f) != sign_f(xm, f))
            xr = xm;
        else
            xl = xm;
    }
    printf("\nSteps number: %d", stepcount);
    return (xl + xr) / 2;
}
#ifndef ROOTS_H
#define ROOTS_H
double trapezoidal_rule(double (*func)(double), double a, double b, int n);
double integral(double (*func)(double), double a, double b, double eps2);
#endif

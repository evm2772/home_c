#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "roots.h"

/*
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
*/
// Trapezoidal Rule function
double trapezoidal_rule(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = 0.5 * (func(a) + func(b)); // Initialize sum with the first and last terms

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }
    return sum * h;
}

// Function to compute integral with accuracy epsilon
double integral(double (*func)(double), double a, double b, double eps2) {
    int n = 1; // Start with 1 interval
    double prev_integral = trapezoidal_rule(func, a, b, n);
    double current_integral;
    while (1) {
        n *= 2; // Double the number of intervals for better accuracy
        current_integral = trapezoidal_rule(func, a, b, n);

        // Check if the difference between successive integrals is less than epsilon
        if (fabs(current_integral - prev_integral) < eps2) {
            break;
        }

        prev_integral = current_integral; // Update previous integral
    }

    return current_integral;
}

double f(double x) {
    return sin(x); // Example: integral of sin(x)
}


double f_true(double a, double b) {
    return cos(a) - cos(b); // Example: integral of sin(x)
}


double f1(double x) // 1-st function
{
    return 0.6 * x + 3.;
}

double f2(double x) // 2-nd function
{
    return pow ((x - 2.), 3) - 1;
}

double f3(double x) // 3-d function
{
    return 3. / x;
}

double intersect_f2_f3(double x) // function for culculating f2 and f3 intersection 
{
    return f2(x) - f3(x);
}


double intersect_f1_f3(double x) // function for culculating f1 and f3 intersection 
{
    return f1(x) - f3(x);
}

double test_sin(double x) // Test function 
{
    return sin(x);
}

void test()
{
    double x0, sigma;
    double a = 0.1;
    double b = 5.0;
    double epsilon = 0.0001;
    printf("\nTesting f(x) = sin(x)");
    printf("\nTest 1: Roots for sin(x) = 0\n");
    x0 = root(test_sin, a, b, epsilon); 
    printf("Root sin(x) in range [%3lf; %3lf] = %lf\n", a, b, x0); 
    a = 0.;
    b = M_PI;
    printf("\nTest 2: Integral for sin(x) = 0\n");
    sigma = integral(test_sin, a, b, epsilon); 
    printf("Integral sin(x) in range [%3lf; %3lf] = %lf\n", a, b, sigma); 
}


void help()
{
    printf ("Help ....\n");
}

int main(int argc, char *argv[])
 {
    
    int opt = 0, calc_roots=0;
    double epsilon = 0.00001;
    char cvs_path[256];
    int h = 0;
    // Parse options
    while ((opt = getopt(argc, argv,"htre:")) != -1)
    {
        switch (opt)
        {
            case 'h':
                // Help 
                help();
                return 0;
            case 't':
                // Testing  
                test();
                return 0;
            case 'r':
                // Roots
                calc_roots = 1;
                break;
            case 'e':
                epsilon = (double)atof(optarg);
                break;
            case '?': 
                printf("\nUnknown option!");
                return 1;
        }
    };

    // test();
    double sigma;
    double a;
    double b;
    double x_l, y_l, x_r, y_r, x_t, y_t, x_b, y_b;
    printf("\nepsilon = %lf", epsilon);
    // For f2 and f3 inresection:
    // 2 roots in [-5, 0.0001] and [2; 6] 
    printf("\n------------------------- Graphs Intersections -------------------------");
    // Bottom:
    a = -.5;
    b = -0.00001;
    x_b = root(intersect_f2_f3, a, b, epsilon);
    y_b = f2(x_b); 
    printf("\n[1]Intersection f2 and f3 [%lf; %lf] ~ (%lf, %lf)\n", a, b, x_b, y_b); 
   
    // Right
    a = 2.;
    b = 6.;    
    x_r = root(intersect_f2_f3, a, b, epsilon); 
    y_r = f2(x_r);
    printf("\n[2]Intersection f2 and f3 [%lf; %lf] ~ (%lf, %lf)\n", a, b, x_r, y_r); 
   

    // For f1 and f3 inresection:
    // 2 roots in [-10, -0.0001] and [0.0001; 10] 

    // Left
    a = -10.;
    b = -0.00001;
    x_l = root(intersect_f1_f3, a, b, epsilon);
    y_l = f1(x_l);
    printf("\n[1]Intersection f1 and f3 [%lf; %lf] ~ (%lf, %lf)\n", a, b, x_l, y_l); 

    //Top
    a = 0.00001;
    b = 10.;    
    x_t = root(intersect_f1_f3, a, b, epsilon); 
    y_t = f1(x_t);
    printf("\n[2]Intersection f1 and f3 [%lf; %lf] ~ (%lf, %lf)\n", a, b, x_t, y_t);
    double fig_s;
    if (!calc_roots)
    {
        printf("\n------------------------- Figure Area -------------------------");
        fig_s = 0.;
        fig_s += integral(f1, x_l, x_t, epsilon);
        //printf("\ni_1 = %lf", fig_s);
        fig_s += integral(f3, x_t, x_r, epsilon);
        //printf("\ni_2 = %lf", fig_s);
        fig_s -= integral(f3, x_l, x_b, epsilon);
        //printf("\ni_3 = %lf", fig_s);
        fig_s -= integral(f2, x_b, x_r, epsilon);
        printf("\nArea value = %lf", fig_s);
    }
    
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "roots.h"
#include "itrapez.h"


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
    printf("\nRoot sin(x) in range [%3lf; %3lf] = %lf\n", a, b, x0); 
    a = 0.;
    b = M_PI;
    printf("\nTest 2: Integral for sin(x) = 0\n");
    sigma = integral(test_sin, a, b, epsilon); 
    printf("\nIntegral sin(x) in range [%3lf; %3lf] = %lf\n", a, b, sigma); 
}


void help()
{
    printf("\nNumerical integration application.\n");
    printf("-----------------------------------------\n");
    printf("Numerical integration is used to calculate a numerical approximation for the value S , \nthe area under the curves defined by:\n");
    printf("f1(x) = 0.6 * x + 3\n");
    printf("f2(x) = pow ((x - 2.), 3) - 1\n");
    printf("f3(x) = 3/x\n");
    printf("-----------------------------------------\n");
    printf("\tUsage: integral [-h]  [-e <epsilon value>] [r] \n");
    printf("\t\t-h \t Show this help.\n");
    printf("\t\t-t \t Test.\n");
    printf("\t\t-e \t Accuracy. Epsilon is a float value. Default value is 0.00001\n");
    printf("\t\t-r \t Roots. Points of intersection of the functions plots.\n");

    printf("\tExamples:\n");
    printf("\t\tintegral -h\n");
    printf("\t\tintegral -t\n");
    printf("\t\tintegral -r -e 0.01\n");
    printf("\t\tintegral -e 0.001\n");
};


int main(int argc, char *argv[])
 {
    
    int opt = 0, calc_roots=0;
    double epsilon = 0.00001;
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
                printf("\nUnknown option!\n");
                help();
                return 1;
        }
    };

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
        printf("\nArea value = %lf\n\n", fig_s);
    }
    
}

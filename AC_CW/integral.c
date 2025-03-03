#include <stdio.h>
#include <math.h>


double root222(double (*func)(double), double a, double b, double eps)
 {
    int stepcount = 0; 
    while(fabs(b - a) > eps) {
        a = b - (b - a) * func(b) / (func(b) - func(a));
        b = a - (a - b) * func(a) / (func(a) - func(b));
        printf("\na: %10lf b: %10lf", a, b);
        stepcount++;
    }
    printf("\nRoot found for %d steps\n", stepcount);
    return b;
}


int  sign_f(double x, double (*f)(double))
{
    return f(x) == 0 ? 0 : (f(x) < 0 ? -1: +1);
}


double root(double (*f)(double), double xl, double xr, double eps) 
{
    int stepcount = 0; //число шагов
    double xm;
    while(fabs(xr-xl) > eps) 
    { //вещественный модуль разницы или floatabs
        stepcount++;
        xm=(xl + xr)/2; // середина отрезка
        if(sign_f(xl, f) != sign_f(xm, f)) //если знак отличается
            xr = xm;
        else
            xl = xm;
    }
    printf("\nFound root for %d steps\n", stepcount); //статистика
    return (xl + xr) / 2;

}



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
        //printf("..%d", n);
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

/*
float rootFindTangent(float xn, float eps, function f, function df ) {
    float x1  = xn - f(xn)/df(xn);
    float x0 = xn;
    while(fabs(x0-x1) > eps) {
       x0 = x1;
       x1 = x1 - f(x1)/df(x1);
    }
    return x1;
 }
 */


//=======================================
// Define the function to integrate
double f(double x) {
    return sin(x); // Example: integral of sin(x)
}


double f_true(double a, double b) {
    return cos(a) - cos(b); // Example: integral of sin(x)
}


double f1(double x)
{
    return 0.6 * x + 3.;
}

double f2(double x)
{
    return pow ((x - 2.), 3) - 1;
}

double f3(double x)
{
    return 3. / x;
}

double intersect_f2_f3(double x)
{
    return f2(x) - f3(x);
}


double intersect_f1_f3(double x)
{
    return f1(x) - f3(x);
}




double test_sin(double x)
{
    return sin(x);
    //return x*x - x;
}

void test()
{
    double x0, sigma;
    double a = 0.1;
    double b = 5.0;
    double epsilon = 0.0001;
    printf("\nRoots sin(x)");

    x0 = root(test_sin, a, b, epsilon); 
    printf("Root sin [%3lf; %3lf] ~ %lf", a, b, x0); 

    a = 0.;
    b = M_PI;

    sigma = integral(test_sin, a, b, epsilon); 
    printf("\nIntegral sin [%3lf; %3lf] ~ %lf", a, b, sigma); 
    
}



int main() {
    test();
    double x0, sigma;
    double a;
    double b;
    double epsilon = 0.00001;
 

    // f2 and f3 inresection:
    // 2 roots in [-5, 0.0001] and [2; 6]
    
    printf("\n>> Intersection f2 - f3");
    a = -.5;
    b = -0.00001;
    x0 = root(intersect_f2_f3, a, b, epsilon); 
    printf("\nIntersection f2 and f3 [%lf; %lf] ~ %lf", a, b, x0); 
    printf("\nf2(x0) = %lf f3(x0) = %lf  ", f2(x0), f3(x0)); 


    a = 2.;
    b = 6.;    
    x0 = root(intersect_f2_f3, a, b, epsilon); 
    printf("\nIntersection f2 and f3 [%lf; %lf] ~ %lf", a, b, x0); 


    printf("\n>> Intersection f1 - f3");
    a = -10.;
    b = -0.00001;
    x0 = root(intersect_f1_f3, a, b, epsilon); 
    printf("\nIntersection f1 and f3 [%lf; %lf] ~ %lf", a, b, x0); 

    a = 0.00001;
    b = 10.;    
    x0 = root(intersect_f1_f3, a, b, epsilon); 
    printf("\nIntersection f1 and f3 [%lf; %lf] ~ %lf", a, b, x0); 

 


    
    // // Input: lower limit, upper limit, and number of intervals
    // printf("Enter lower limit of integration: ");
    // scanf("%lf", &a);
    // printf("Enter upper limit of integration: ");
    // scanf("%lf", &b);
    // printf("Enter epsilon (eps): ");
    // scanf("%lf", &eps);

    // // Compute the integral using the trapezoidal rule
    // double result = integral(f, a, b, eps);
    // double result_true = f_true(a, b);


    // // Output the result
    // printf("Approximate integral: %.6lf\n", result);
    // printf("\nReal integral: %.6lf\n", result_true);

    // return 0;
}
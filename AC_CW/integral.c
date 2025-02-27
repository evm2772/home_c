#include <stdio.h>
#include <math.h>

// double root(f, g, a, b, eps1)
// {
//     return 0;
// } 


double root(double (*func)(double), double a, double b, double eps)
 {
    int stepcount = 0; 
    while(fabs(b - a) > eps) {
        a = b - (b - a) * func(b) / (func(b) - func(a));
        b = a - (a - b) * func(a) / (func(a) - func(b));
        stepcount++;
    }
    printf("\nRoot found for %d steps\n", stepcount);
    return b;
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
        printf("..%d", n);
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


int main() {
    double a, b, eps;

    // Input: lower limit, upper limit, and number of intervals
    printf("Enter lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &b);
    printf("Enter epsilon (eps): ");
    scanf("%lf", &eps);

    // Compute the integral using the trapezoidal rule
    double result = integral(f, a, b, eps);
    double result_true = f_true(a, b);


    // Output the result
    printf("Approximate integral: %.6lf\n", result);
    printf("\nReal integral: %.6lf\n", result_true);

    return 0;
}
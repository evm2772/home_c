#include <stdio.h>
#include <math.h>
#include "itrapez.h"

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

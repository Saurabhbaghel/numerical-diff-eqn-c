// Write a program using Euler's method to solve the initial value problem
// y' = f(x, y), y(x_0) = y_0
// Input the step length h and the number of steps of integration.
// Test your program on exercise E1


/*
Euler's Method - First order Taylor's Method

y_i_plus_1 = y_i + h * y_i'

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INVALID_STEP_LENGTH_WARNING "Enter a valid integral step length"
#define INVALID_NUM_STEP_INTEGRATIONS "Enter valid integral num of steps of integrations"
#define y_dash(x, y) (2 * (x) * (y) * (y)) // 2xy^2


double get_step_length() {
    double h = 0.1;

    printf("\nEnter the step length \'h\' (Default = 0.1):\n");
    
    // sanity checks on step length
    if (scanf("%lf", &h) == 0) {
        printf("Using Default value of h");
        return 0.1;
    }
    if (h <= 0) {
        printf(INVALID_STEP_LENGTH_WARNING);
        return 0.1;
    }

    return h;
}

int get_num_step_integration() {
    int N = 1;

    printf("\nEnter the number of steps of integration \'N\' (Default = 1):\n");
    // sanity checks on step length
    if (scanf("%d", &N) == 0) {
        printf("Using default value of N");
        return 1;
    }
    if (N <= 0) {
        printf(INVALID_NUM_STEP_INTEGRATIONS);
        return 1;
    }

    return N;
}

void y_i_plus_1(double*x_i, double* y_i, double h) {
    // update y
    *y_i = (*y_i) + (h) * (y_dash(*x_i, *y_i));

    // update x
    *x_i = (*x_i) + h;
}

void print_header() {
    printf("\n%-5s %-12s %-15s %-15s %-15s\n",
           "i", "x_i", "y_i", "f(x_i,y_i)", "y_{i+1}");
    printf("---------------------------------------------------------------\n");
}

void eulers_method(double* x, double* y, int N, double h) {
    print_header();

    for (int i = 0; i < N; ++i) {
        double f = y_dash(*x, *y);
        double y_next = *y + h * f;

        printf("%-5d %-12.6f %-15.8f %-15.8f %-15.8f\n",
               i, *x, *y, f, y_next);

        // advance state
        *y = y_next;
        *x = *x + h;
    }
}



int main() {

    // input step length
    float h = get_step_length();

    // input number of steps of integration
    int N = get_num_step_integration();

    // Calculate y_dash_0
    double x_0 = 1.0;
    double y_0 = 1.0;
    // double y_dash_0 = y_dash(x_0, y_0);

    // Euler's Method
    double* x = &x_0;
    double* y = &y_0;
    eulers_method(x, y, N, h);
    
}

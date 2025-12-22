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

int get_step_length() {
    int h = 0.1;

    printf("\nEnter the step length \'h\' (Default = 0.1):\n");
    
    // sanity checks on step length
    if (scanf("%d", &h) == 0) {
        printf(INVALID_STEP_LENGTH_WARNING);
        return 0;
    }
    if (h <= 0) {
        printf(INVALID_STEP_LENGTH_WARNING);
        return 0;
    }

    return h;
}

int get_num_step_integration() {
    int N = 1;

    printf("\nEnter the number of steps of integration \'N\' (Default = 1):\n");
    // sanity checks on step length
    if (scanf("%d", &N) == 0) {
        printf(INVALID_NUM_STEP_INTEGRATIONS);
        return 0;
    }
    if (N <= 0) {
        printf(INVALID_NUM_STEP_INTEGRATIONS);
        return 0;
    }

    return N;
}

double y_i_plus_1(double y_i, int h) {
    return y_i + ((double) h) * y_i;
}

double eulers_method(double x_0, double y_0) {
    
}
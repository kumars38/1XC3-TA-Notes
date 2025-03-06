// operations.c
#include "calculator.h"
#include <stdio.h>

// Implement the functions from the header
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
    /*if (b==0) {
        printf("Error: Division By 0.\n");
        return -1;
    }*/
}
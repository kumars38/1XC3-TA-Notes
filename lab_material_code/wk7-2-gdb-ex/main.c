// main.c
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

void print_result(int result) {
    printf("Result: %d\n", result);
}

void main() {
    int n1 = 10;
    int n2 = 5;
    int res[4];

    res[0] = add(n1,n2);
    res[1] = subtract(n1,n2);
    res[2] = multiply(n1,n2);
    res[3] = divide(n1,n2);

    for (int i=0; i<4; i++) {
        print_result(res[i]);
    }
}
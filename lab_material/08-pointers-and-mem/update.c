#include <stdio.h>

// takes in pointer as argument
void update(int *pX) {
    // de-reference the pointer
    // directly double the value
    *pX *= 2;
}

void main() {
    int x = 5;
    printf("%d\n",x);
    // pass reference to x
    update(&x);
    printf("%d\n",x);
}
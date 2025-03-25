#include <stdio.h>

// takes in pointer as argument
int update(int x) {
    return x*2;
}

void main() {
    int x = 5;
    printf("%d\n",x);
    // pass by value, then update based on result
    x = update(x);
    printf("%d\n",x);
}
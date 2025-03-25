#include <stdio.h>
#include <math.h>

// macro example in GCD
// uses ternary operator
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int gcd(const int a, const int b) {
    int gcd=1;
    // Start the for loop at MIN(a,b) directly thanks to macro
    for (int i = MIN(a,b); i > 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

int main(void) {
    const int n1 = 48;
    const int n2 = 18;
    const int res = gcd(n1,n2);
    printf("GCD of %d and %d is: %d\n",n1,n2,res);
}
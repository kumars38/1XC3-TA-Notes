#include <stdio.h>
#include <math.h>

int gcd(const int a, const int b) {
    int gcd=1;
    int lower_val;
    if (a>b)
        lower_val=b;
    else
        lower_val=a;
    for (int i = lower_val; i > 1; i--) {
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
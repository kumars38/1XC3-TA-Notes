#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main() {
    int num1=48;
    int num2=18;
    int res = gcd(num1,num2);
    printf("GCD of %d and %d is: %d\n",num1,num2,res);
}
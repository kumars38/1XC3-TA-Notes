#include <stdio.h>
#include <math.h>

// Task 1: 1 - cos(x) calculations
double one_minus_cos_naive(double x) {
    return 1.0 - cos(x);
}

double one_minus_cos_stable(double x) {
    // Double angle formula
    // cos(2x) = 1 - 2*sin^2(x)
    // cos(x) = 1 - 2*sin^2(x/2)
    // 1 - cos(x) = 2*sin^2(x/2)
    double s = sin(x/2.0);
    return 2.0 * s * s;  // 2*sin^2(x/2)
}

// Task 2: Summation methods
double naive_sum(const double arr[], int n) {
    // Standard summation
    double sum = 0.0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

double pairwise_sum(const double arr[], int n) {
    // Implemented for you
    if(n == 1) return arr[0];
    int m = n/2;
    return pairwise_sum(arr, m) + pairwise_sum(arr+m, n-m);
}

int main() {
    // Task 1 Test: Small angle value
    double x = 1e-8;
    printf("Task 1: 1 - cos(%.1e)\n", x);
    printf("Naive:  %.15e\n", one_minus_cos_naive(x));
    printf("Stable: %.15e\n\n", one_minus_cos_stable(x));

    // Task 2 Test: Large array summation
    const int size = 1000000;
    double arr[size];
    for(int i = 0; i < size; i++) {
        arr[i] = 0.1;    
    }
    printf("Task 2:\nNaive sum:   %.15lf\n", naive_sum(arr, size));
    printf("Pairwise sum: %.15lf\n", pairwise_sum(arr, size));
    return 0;
}
#include <stdio.h>

// // ---------------------------------------------------------------------------
// // Finite Precision (Rounding Errors)
int main() {
    printf("size of float: %zu\n",sizeof(float));
    printf("size of double: %zu\n",sizeof(double));
    printf("size of long double: %zu\n",sizeof(long double));

    float a = 0.1f;
    double b = 0.1;
    long double c = 0.1;

    printf("float a  = %.20f\n", a);
    printf("double b = %.20lf\n", b);
    printf("long double c = %.20Lf\n", c);

    // The addition of these numbers obviously can create rounding errors:
    printf("b+c = %.20Lf\n", b+c);
    return 0;
}
// Float a  = 0.10000000149011611938
// Double b = 0.10000000000000000555
// a+b = 0.20000000149011612494

// // ---------------------------------------------------------------------------
// Accumulation of Errors:
// int main() {
//     float sum = 0.0f;
//     for (int i = 0; i < 1000000; i++) {
//         sum += 0.0001;  // Adding a small value repeatedly (the small value already has round-off)
//     }

//     printf("Expected: 100.0\n");
//     printf("Actual  : %.20f\n", sum);

//     return 0;
// }

// Solutions
// 0) Switch to double
// int main() {
//     double sum = 0.0;
//     for (int i = 0; i < 1000000; i++) {
//         sum += 0.0001;  // Adding a small value repeatedly (the small value already has round-off)
//     }
//     printf("Expected: 100.0\n");
//     printf("Actual  : %.20lf\n", sum);
//     return 0;
// }
// 1) Rearrange calc: Since adding a constant value, not relevant for this example
// But in general, you could sort an array in ascending order and add in order of smallest -> greatest
// int main() {
//     float sum = 0.0f;
//     float sum2 = 0.0f;
//     double sum3 = 0.0;

//     // UNSORTED: Large values first, small values last (small values get lost)
//     float arr[] = {10000000.0f, 0.5f, 0.5f, 0.5f, 0.5f}; 

//     // SORTED: Small values first (they accumulate before large values are added)
//     // By the way, stdlib.h has a built-in qsort() if you want to sort a large array
//     float arr2[] = {0.5f, 0.5f, 0.5f, 0.5f, 10000000.0f}; 

//     for (int i = 0; i < 6; i++) {
//         sum += arr[i];    // Naive summation: small values lost after large ones
//         sum2 += arr2[i];  // Small values summed first
//         sum3 += arr[i];   // More precise summation in double
//     }
//     printf("Unsorted sum (float): %.20f\n", sum);
//     printf("  Sorted sum (float): %.20f\n", sum2);
//     printf("Precise sum (double): %.20lf\n", sum3);
//     return 0;
// }

// 2) Kahan's Summation Algo
// int main() {
//     float sum = 0.0f;
//     float compensation = 0.0f; // Tracks lost precision
//     double val = 0.0001;
//     for (int i = 0; i < 1000000; i++) {
//         float y = val - compensation;    // Adjust value with previous error
//         float t = sum + y;               // New sum
//         compensation = (t - sum) - y;    // Calculate new error
//         sum = t;
//     }
//     printf("Actual: %.10f\n", sum); // 100.000000
// }

// 3) Pairwise Summation -- Costly in memory (extra arr + recursive stack)
// float pairwise_sum(float arr[], int n) {
//   if (n == 1) return arr[0];
//   int mid = n / 2;
//   return pairwise_sum(arr, mid) + pairwise_sum(arr + mid, n - mid);
//   // first sum is 0.0001 + 0.0001 (n/2 times)
//   // then 0.0002 + 0.0002 (n/4 times)
//   // 0.0004 + 0.0004 (n/8 times)
//   // ...
// }
// int main() {
//     float arr[1000000];
//     float val = 0.0001f;
//     for (int i=0; i<1000000; i++) {
//         arr[i] = val;
//     }
//     float sum = pairwise_sum(arr, 1000000);
//     printf("Actual: %.20f\n", sum); // 100.000000
// }

// // ---------------------------------------------------------------------------
// // // Catastrophic Cancellation:

// int main() {
//     double a = 1.0000001;
//     double b = 1.0000000;
//     double result = (a - b);

//     double Expected = 1e-7; // 1.0000001 - 1.0000000 = 0.0000001 OR = 1e-7

//     printf("With .15lf:\n");
//     printf("Expected: %.15lf\n", Expected);
//     printf("Actual  : %.15lf\n", result);

//     // However, with 15 decimals the difference cannot be seen. So:
//     printf("\nWith .20lf:\n");
//     printf("Expected: %.20lf\n", Expected);
//     printf("Actual  : %.20lf\n", result);

//     // But how many decimals are accurate to be compared?
//     // We need to use floating point representation.
//     // Then always 15 decimals are accurate
//     printf("\nWith .15e:\n");
//     printf("Expected: %.15e\n", Expected);
//     printf("Actual  : %.15e\n", result);

//     // Now the difference is easy to see

//     return 0;
// }

// With .15lf:
// Expected: 0.000000100000000
// Actual  : 0.000000100000000

// With .20lf:
// Expected: 0.00000010000000000000
// Actual  : 0.00000010000000005839

// With .15e:
// Expected: 1.000000000000000e-07
// Actual  : 1.000000000583867e-07

// // ---------------------------------------------------------------------------
// // // Precision Loss in Large and Small Values (Underflow & Overflow): 
// #include <float.h>

// int main() {
//     float large = FLT_MAX;
//     float small = FLT_MIN;
    
//     printf("Large: %e\n", large);
//     printf("Small: %e\n", small);

//     float overflow = large * 2.0f;
//     float underflow = small / 2.0f;

//     printf("Overflow: %e\n", overflow);  // Infinity
//     printf("Underflow: %e\n", underflow); // 0

//     return 0;
// }

// Large: 3.402823e+38
// Small: 1.175494e-38
// Overflow: inf
// Underflow: 5.877472e-39
// // ---------------------------------------------------------------------------
// // // Floating-Point Division (Non-Terminating Decimals):
// int main() {
//     float a = 1.0f / 3.0f;
//     double b = 1.0 / 3.0;

//     printf("Float a  = %.20f\n", a);
//     printf("Double b = %.20lf\n", b);

//     return 0;
// }

// Float a  = 0.33333334326744079590
// Double b = 0.33333333333333331483
// // ---------------------------------------------------------------------------
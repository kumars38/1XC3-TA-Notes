#include <stdio.h>


// // ---------------------------------------------------------------------------
// // Finite Precision (Rounding Errors)
int main() {
    float a = 0.1;
    double b = 0.1;

    printf("Float a  = %.20f\n", a);
    printf("Double b = %.20lf\n", b);

    // The addition of these numbers obviously can create rounding errors:
    printf("a+b = %.20lf\n", a+b);

    return 0;
}

// Float a  = 0.10000000149011611938
// Double b = 0.10000000000000000555
// a+b = 0.20000000149011612494

// // ---------------------------------------------------------------------------
// // Accumulation of Errors:
// int main() {
//     float sum = 0.0;
//     for (int i = 0; i < 1000000; i++) {
//         sum += 0.0001;  // Adding a small value repeatedly (the small value already has round-off)
//     }

//     printf("Expected: 100.0\n");
//     printf("Actual  : %.10f\n", sum);

//     return 0;
// }

// Expected: 100.0
// Actual  : 99.3273086548
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
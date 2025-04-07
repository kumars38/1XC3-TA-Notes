#include <stdio.h>

// assume 64-bit ans (ans <= 2^63 - 1)
// we need a type with 8 bytes of data
// int             - at least 2 bytes, usually 4 bytes on modern CPU
// long (int)      - at least 4 bytes, usually 8 bytes on Linux/macOS
// long long (int) - at least 8 bytes, "safe" across OS

// on most systems, long is sufficient
// but to be safe across different OS, we can use long long
// or use fixed-width, uint64_t from <stdint.h>
unsigned long long tribonacci(const int n) {
    unsigned long long prev[] = {0,1,1};
    unsigned long long next;
    int c=2; // subscript counter: c=2 ==> T_2 is in prev[2];
    while (c<n) {
        // compute next, then shift array
        // T0, T1, T2 ==> T1, T2, T3 (next)
        next = prev[0] + prev[1] + prev[2];
        prev[0] = prev[1];
        prev[1] = prev[2];
        prev[2] = next;
        c++;
    }
    return prev[2]; // trib n will always be in last spot of prev
}

int main() {
    int input = 40;
    printf("T_%d = %llu\n", input, tribonacci(input));
}
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// assume 64-bit ans (ans <= 2^63 - 1)
// we need a type with 8 bytes of data
// int             - at least 2 bytes, usually 4 bytes on modern CPU
// long (int)      - at least 4 bytes, usually 8 bytes on Linux/macOS
// long long (int) - at least 8 bytes, "safe" across OS

// on most systems, long is sufficient
// but to be safe across different OS, we can use long long
// or use fixed-width, uint64_t from <stdint.h>
unsigned long long tribonacci(const int n) {
    unsigned long long ans = 0;
    // base case
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    // recursive step
    return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
}

int main() {
    int n = 5;
    long long out = tribonacci(n);
    printf("T_%d = %llu\n", n, out);
}
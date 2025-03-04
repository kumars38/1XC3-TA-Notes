#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR_LEN (20)

// String-based palindrome check
bool isPalindrome(const char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Mathematical palindrome check for integers
bool isPalindromeNum(int n) {
    int original = n;
    int reversed = 0;
    // Loop until reversed matches # digits of n
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10; // Int division, basically gets rid of the ones digit
    }
    return original == reversed;
}

int main() {
    // Test cases for string palindrome
    const char testStrings[][MAX_STR_LEN] = {"racecar", "hello", "mcmaster", "", "noon", "abab", "abba"};
    // equiv:
    //const char* testStrings[] = {"racecar", "hello", "mcmaster", "", "noon", "abab", "abba"};
    int numTestStrings = sizeof(testStrings) / sizeof(testStrings[0]);
    
    printf("String Palindrome Tests:\n");
    for (int i = 0; i < numTestStrings; i++) {
        printf("\"%s\" -> %s\n", testStrings[i], isPalindrome(testStrings[i]) ? "true" : "false");
    }
    
    // Test cases for numeric palindrome
    int testNums[] = {121, 12321, 100, 0, 1221, 412051850};
    int numTestNums = sizeof(testNums) / sizeof(testNums[0]);
    
    printf("\nNumeric Palindrome Tests:\n");
    for (int i = 0; i < numTestNums; i++) {
        printf("%d -> %s\n", testNums[i], isPalindromeNum(testNums[i]) ? "true" : "false");
    }
    
    return 0;
}

#include <stdio.h>
#include <stddef.h>
#include <string.h>
void ex1() {
    char a[] = "Hi";  // Simple string declaration: b = ['H','i','\0']
    char b[3] = "Hi"; // If we want to specify the size, need to be n+1 = 3
    char c[3];
    c[0] = 'H';
    c[1] = 'i';
    
    printf("%s\n",a);
    printf("%s\n",b);
    printf("%s\n",c);
    printf("%c\n",c[2]); // This is the null character, '\0'
    return;
}

void ex2() {
    size_t size_of_int = sizeof(int);
    size_t size_of_short = sizeof(short);
    size_t size_of_char = sizeof(char);
    size_t size_of_float = sizeof(float);
    size_t size_of_double = sizeof(double);
    // Machine-dependent
    printf("Size of char: %zu bytes\n", size_of_char);
    printf("Size of short: %zu bytes\n", size_of_short);
    printf("Size of int: %zu bytes\n", size_of_int); 
    printf("Size of float: %zu bytes\n", size_of_float);
    printf("Size of double: %zu bytes\n", size_of_double);
    return;
}

void ex3() {
    char dest1[20];
    char dest2[5];
    unsigned const char numToCopy = 4;
    strcpy(dest1, "Hello World");  // Full copy
    strncpy(dest2, "McMaster", numToCopy); // Copies "McMa" when numToCopy = 4
    printf("%s\n",dest1);
    printf("%s\n",dest2);

    // What would happen if we change numToCopy to 6?
}

void ex4() {
    // character by character lexicographic comparison
    printf("%d\n", strcmp("Apple", "Apple"));    //  0, all characters match up to '\0'
    printf("%d\n", strncmp("App", "Apple", 3));  //  0, the first n chars match for n = 3
    printf("%d\n", strcmp("Apple", "Bpple"));    // -1, 'A' < 'B'
    printf("%d\n", strcmp("Apple", "apple"));    // -1, 'A' < 'a'

    // ['A','p','p','l','e','\0']
    // vs. []'A','p','p','\0']
    printf("%d\n", strcmp("Apple", "App"));      //  1, 'l' > '\0', i.e. null char is "smaller"
}

void ex5() {
    const char str[] = "McMaster";
    char *pos1 = strchr(str, 'M');  // Points to first 'M'
    char *pos2 = strrchr(str, 'M'); // Points to second 'M'
    printf("%s\n",pos2);            // Since pos is a pointer, prints string from pos2 until '\0'

    const char lookFor = 'D';
    char *pos = strchr(str, lookFor);
    if (pos) {
        printf("Found character at: %s\n", pos);
    } else {
        printf("Character %c not found in %s\n", lookFor, str);
    }
    return;
}

void ex6() {
    char str[] = "C Programming Is Fun";
    char *token = strtok(str, " ");      // The delimiter is ' ' (space)
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");       // Passing in NULL tells it to keep looking for the next delim until '\0' 
    }
}

void ex7() {
    char a[20] = "Goodbye"; 
    // Works for overlap
    memmove(a + 4, a, strlen(a)+1); // Note the strlen+1 to include null char '\0'
    printf("%s\n", a); 
    return; 
}

void ex8() {
    char buf[10];
    memset(buf, 'A', 5);                      // "AAAAA"
    memset(buf + 5, 'B', 3);                  // "AAAAABBB"
    printf("%s\n",buf);
    printf("%d\n", memcmp("AAA", "AAB", 3));  // Negative (-1) since 'A' < 'B'

    int n1[] = {10, 20, 30, 40};
    int n2[] = {10, 20, 35, 40};

    // Compare first sizeof(s1) bytes of s1 and s2
    int res = memcmp(n1, n2, sizeof(n1)); // Using sizeof() to supply the # bytes to memcmp
    // Question: what does sizeof(n1) return?
    // Hint: think about the size of int in memory (typically), and how an array works
    printf("%zu\n",sizeof(n1));

    if (res == 0)
        printf("Arrays are identical");
    else
        printf("Arrays differ");
    return;
}

// Driver
int main() {
    ex1();
    //ex2();
    //ex3();
    //ex4();
    //ex5();
    //ex6();
    //ex7();
    //ex8();
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main takeaways: 
// can pass arrays into function as pointers
// no de-reference is needed

// pointer as argument
void printInts(int *arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");    
}

// pointer as argument
void printChars(char *arr) {
    // arr can be directly treated as string (character array)
    int len = strlen(arr);
    for (int i=0; i<len; i++) {
        printf("%c ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr1)/sizeof(int);
    // arr2 is now a pointer to the same address as arr1
    int *arr2 = arr1;
    // arrays decay to pointers when passed into function
    // this is why we can pass (arr2) and don't need (&arr2)
    printInts(arr2, size);
    
    char arr3[] = "Hello";
    // arr4 is now a pointer to the same address as arr3
    char *arr4 = arr3;
    // again, pass arr4 (decays to pointer) directly into function
    printChars(arr4);

    return 0;
}
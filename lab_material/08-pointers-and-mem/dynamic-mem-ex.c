#include <stdio.h>
// need stdlib.h for memory allocation functions
#include <stdlib.h>

void main() {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    // first, we need to know how many bytes of memory to allocate
    // we use sizeof(int) and multiply by number of array elements (n)
    int nBytes = n * sizeof(int);
    
    // malloc allocates nBytes of memory and returns a void pointer to the starting address
    // you should explicitly cast the returned pointer to the correct type (int*)
    // but it would still compile without (int*) due to implicit casting
    int *arr = (int*) malloc(nBytes);

    // An alternative using calloc: worse performance but guarantees bits are set to 0
    // Note it takes in the number of elements and size of data in 2 arguments
    int *arrC = (int*) calloc(n, sizeof(int));

    // Important, check for memory allocation failure right away
    if (arr == NULL || arrC == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Simple assignment and print
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        printf("Address: %p, Value: %d\n", arr + i, arr[i]);
        // Note arr + i is equivalent to &arr[i] due to pointer arithmetic
        // Basically, the compiler scales i by sizeof(data): 
        // For our int arr, arr+i becomes arr+0, arr+4, arr+8, ...
    }
    printf("\n");

    // Resize example
    int n2;
    printf("Enter the new size: ");
    scanf("%d", &n2);

    // Resize the array using realloc()
    // Pass the pointer to first address of arr and new size
    // What is it doing?
        // 1) If there's space in the same continuous block, it preserves old memory
        // and allocates the extra (n2 - n) bytes
        // 2) If there's no space, it will copy the existing n bytes and allocate the total n2 bytes
        // somewhere else (fresh address)
    int *arr2 = realloc(arr, n2*sizeof(int));

    // Check for errors
    if (arr2 == NULL) {
        printf("Memory re-allocation failed\n");
        return;
    }
    // If no error, let's update our original array to new one
    arr = arr2;

    // Print values in resized array
    for (int i = 0; i < n2; i++) {
        printf("Address: %p, Value: %d\n", arr + i, arr[i]);
    }

    // Free any allocated (heap) memory at the end
    // Otherwise, prone to memory leaks
    free(arr);
    free(arrC);
}
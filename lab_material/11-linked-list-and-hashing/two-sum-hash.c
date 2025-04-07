#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 2000

// In our two sum approach:
// Array values will each have a HashEntry key
// Array indices will be the associated value
typedef struct {
    int key;
    int value;
} HashEntry;

int hashFunction(int key) {
    return key % TABLESIZE;
}

void insert(HashEntry *hashTable[], int key, int value) {
    int index = hashFunction(key);
    // there was a collision, so find next non-null entry
    while (hashTable[index] != NULL) {
        index = (index + 1) % TABLESIZE;
    }
    hashTable[index] = (HashEntry *) malloc(sizeof(HashEntry));
    hashTable[index]->key = key;
    hashTable[index]->value = value;
}

int search(HashEntry *hashTable[], int key) {
    int index = hashFunction(key);
    // Loop to deal with collisions
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }
        index = (index + 1) % TABLESIZE;
    }
    return -1;
}

// since the heap is used (via malloc) for our hash table entries
void freeTable(HashEntry *hashTable[]) {
    for (int i = 0; i < TABLESIZE; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }
}

void twoSum(int arr[], int size, int target) {
    HashEntry *hashTable[TABLESIZE];
    // Allocate our hash map to null entries
    for (int i = 0; i < TABLESIZE; i++) {
        hashTable[i] = NULL;
    }

    // Find the matching pair if it exists
    // This is now O(n), why?
    for (int i = 0; i < size; i++) {
        int numToFind = target - arr[i];

        // What is the complexity of HashMap search?
        int index = search(hashTable, numToFind);
        if (index != -1) {
            printf("Target= sum of arr[%d] and arr[%d]\n", index, i);
            // free before we return
            freeTable(hashTable);
            return;
        }
        // Now, insert into HashMap
        // What is the complexity of HashMap insert?
        insert(hashTable, arr[i], i);
    }
    
    printf("No pair found\n");
    freeTable(hashTable);
}

int main() {
    int arr[1000];
    for (int i=0; i<1000; i++) {
        arr[i] = i;
    }
    int target = 601;
    int size = sizeof(arr) / sizeof(int);
    twoSum(arr, size, target);
    return 0;
}

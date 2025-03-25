#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member {
    char *name;  // Will accept code that works with char name[size];
    int SN;      // Student Number
    char *macID; // Will accept code that works with char macID[size];
    int dob;     // Date of Birth
};

void addMember(struct member* Library, char name[], int SN, char macID[], int dob, int i) {
    // Library[i] represents the new member

    // Option 1: not always safe (if values change), but accepted for quiz
    // struct member m1 = {name, SN, macID, dob};
    // Library[i] = m1;

    // Option 2: not always safe (if values change), but accepted for quiz
    /*
    Library[i].name = name;
    Library[i].SN = SN;
    Library[i].macID = macID;
    Library[i].dob = dob; 
    */

    // Option 3 (safe/best option)
    // (len + 1 to include null char, '\0')
    // I'll still accept this answer if you didn't malloc for name, macID
    Library[i].name = malloc(strlen(name) + 1);
    Library[i].macID = malloc(strlen(macID) + 1);
    Library[i].SN = SN;
    Library[i].dob = dob; 
    strcpy(Library[i].name, name);
    strcpy(Library[i].macID, macID);
}

void printMember(struct member* Library, int i) {
    // Get the member at specified index (assume index is valid)
    // Also assume there is a valid member at this index
    // Print each field on a new line
    printf("Name: %s\n", Library[i].name);
    printf("Student number: %d\n", Library[i].SN);
    printf("macID: %s\n", Library[i].macID);
    printf("Date of birth: %d\n", Library[i].dob);
}

int main() {
    int Size = 10;
    // CODE: Allocate mem for Library array of member struct with given Size
    // Important: the # bytes is the size of each member multiplied by number of elements (Size)
    struct member* Library = malloc(Size * sizeof(struct member));

    // Alternative: explicit casting (good practice), not needed for quiz
    // struct member* Library = (struct member*) malloc(Size * sizeof(struct member));

    // Not needed on quiz, you should do this in practice
    if (Library == NULL) {
        printf("Error during allocation of Library\n");
        return -1;
    }

    char ugName[]   = "John";  // ug: User Given
    int ugSN        = 123456;
    char ugmacID[]  = "WickJ";
    int ugdob       = 1964;

    int InsertIndex = 2; // assume 0 <= Index < Size
    // CODE: call addMember() to insert the above member at a given InsertIndex
    addMember(Library, ugName, ugSN, ugmacID, ugdob, InsertIndex);

    int PrintIndex = 2; // assume 0 <= Index < Size
    // CODE: call printMember() to print an element for a given PrintIndex
    printMember(Library, PrintIndex);

    // Not needed on quiz, you should do this in practice
    free(Library);

    return 0;
}


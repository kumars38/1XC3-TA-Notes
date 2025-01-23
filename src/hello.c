#include <stdio.h>
void main() {
   char name[60];
   printf("Please enter your first name: ");
   scanf("%s", name);
   printf("Hello, %s!\n", name);
   return;
}

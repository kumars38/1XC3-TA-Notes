#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// O(n)
bool isAnagram(char* s, char* t) {
    const unsigned int len = strlen(s);
    if (len != strlen(t)) {
        return false;
    }
    int map[26] = {0}; // initialize all 0s
    // frequency counter for chars in s
    for (int i=0; i<len; i++) {
        char currChar = s[i];
        map[currChar-'a']++;
    }
    // check chars in t
    for (int i=0; i<len; i++) {
        char currChar = t[i];
        map[currChar-'a']--;
    }
    // compare maps
    for (int i=0; i<26; i++) {
        // printf("%d ",map[i]);
        if (map[i] != 0)
            return false;
    }
    // printf("\n");
    return true;
}

int main() {
    char s1[] = "listen";
    char s2[] = "silent";
    bool res = isAnagram(s1, s2);
    printf("Is anagram: %s\n", res ? "true" : "false");
}
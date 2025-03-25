# include <stdio.h>
# include <string.h>

// Implement your functions here
int has_exact_n_chars ( const char *str, int n) {
    return strlen (str) == n;
}

int contains_char ( const char * str , char c ) {
    return strchr (str, c) != NULL;
}

int starts_with ( const char *str, const char *sub) {
    if (strlen(sub) > strlen(str)) return 0;
    return strncmp (str, sub, strlen(sub)) == 0;
}

int ends_with ( const char * str , char c ) {
    if (strlen(str) == 0) return 0;
    return str [strlen(str) - 1] == c;
}

int exactly_one_occurrence (const char *str, char c) {
    const char *first = strchr (str, c);
    return first != NULL && first == strrchr(str, c);
    // Or more simple solution: just loop through str and count occurences of c
    // return count of c == 1
}

int main () {
    // Test has_exact_n_chars
    printf ("'Hello' has 5 chars? %d\n",
    has_exact_n_chars ("Hello", 5));
    printf ("'Hi' has 5 chars? %d\n",
    has_exact_n_chars ("Hi", 5));   
    printf ("empty str has 0 chars? %d\n",
    has_exact_n_chars ("", 0));     
    // Test contains_char
    printf ("'Apple' contains 'z'? %d\n",
    contains_char("Apple", 'z'));
    printf ("'Apple' contains 'p'? %d\n",
    contains_char("Apple", 'p'));
    // Test starts_with
    printf ("'Apple' starts with 'z'? %d\n",
    starts_with("Apple", "z"));
    printf ("'Apple' starts with 'Ap'? %d\n",
    starts_with("Apple", "Ap"));
    // Test ends_with
    printf ("'Apple' ends with 'z'? %d\n",
    ends_with("Apple", 'z'));
    printf ("'Apple' ends with 'e'? %d\n",
    ends_with("Apple", 'e'));
    printf ("empty str ends with 'h'? %d\n",
    ends_with("", 'h'));
    // Test exact occurrence
    printf("'Apple' has exactly one occurrence of 'A'? %d\n",
    exactly_one_occurrence("Apple",'A'));
    printf("'Apple' has exactly one occurrence of 'p'? %d\n",
    exactly_one_occurrence("Apple",'p'));
    printf("empty str has exactly one occurrence of 'k'? %d\n",
    exactly_one_occurrence("",'k'));
    return 0;
}
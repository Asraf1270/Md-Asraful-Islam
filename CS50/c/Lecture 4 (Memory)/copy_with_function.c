#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
    char s[100];
    printf("s: ");
    scanf("%99s", s);
    
    char *t = malloc(strlen(s) + 1);  // Allocate memory for t based on the length of s
    if(t == NULL)
    {
        return 1;  // Exit if memory allocation fails
    }
    int n = strlen(s);
    
    strcpy(t, s);  // Copy the string from s to t using strcpy

    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);  // Capitalize the first character of t
    }

    printf("t: %s\n", t);
    free(t);  // Free the allocated memory
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    char s[4];
    printf("What is your name? ");
    scanf("%s", s);
    printf("Before: %s\n", s);
    printf("After : ");
    // print in uppercase
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
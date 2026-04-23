#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[4];
    printf("What is your name? ");
    scanf("%s", s);
    printf("Before: %s\n", s);
    printf("After:  ");
    // print in uppercase
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // change to uppercase
            s[i] = s[i] - ('a' - 'A');
            printf("%c", s[i]);
        }
        else
        {
            // just print the character
            s[i] = s[i];
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
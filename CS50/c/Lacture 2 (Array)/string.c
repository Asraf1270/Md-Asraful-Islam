#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[1];
    printf("What is your name? \n");
    scanf("%s", s);
    printf("Hello, %s\n", s);

    // print each character of string   
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c\n", s[i]);
    }
    printf("\n");
}
#include <stdio.h>
int main(void)
{
    char name[4];
    printf("What is your name? \n");
    scanf("%s", name);
    printf("Hello, %s\n", name);

    // count chatecter
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("Length of name: %i\n", n);

    return n;
}
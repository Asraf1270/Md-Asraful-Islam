#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[4];
    printf("What is your name? \n");
    scanf("%s", name);
    printf("Hello, %s\n", name);

    // count chatecter
    int n = strlen(name);
    printf("Length of name: %i\n", n);
}
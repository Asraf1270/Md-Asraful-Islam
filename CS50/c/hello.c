#include <stdio.h>
int main(void) 
{
    char name[50];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    printf("Welcome to CS50!\n");
    return 0;
}
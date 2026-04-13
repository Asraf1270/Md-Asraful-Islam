#include <stdio.h>
int main(void) 
{
    char name[50];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    printf("Welcome to CS50!\n");
    printf("Do you ready to enjoy learning C?\nLet's get started!\n");
    return 0;
}
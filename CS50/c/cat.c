#include <stdio.h>

void meow(void)
{
    printf("Meow\n");
}

int main(void)
{
    /*int i, j;
    printf("Enter the number of cats: ");
    scanf("%d", &j);
    for(i = 0; i < j; i++)  
    printf("Meow\n");*/

    /*int i = 1;
    while (i <= 3)
    {
        printf("Meow\n");
        i++;
    }*/
    
    for(int i = 0; i < 3; i++)
    {
        meow();
    }
    return 0;
}
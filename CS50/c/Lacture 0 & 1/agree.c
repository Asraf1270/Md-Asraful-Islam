#include <stdio.h>
int main(void)
{
    char answer[10];
    printf("Do you agree? ");
    scanf("%s", answer);
    if(answer[0] == 'y' || answer[0] == 'Y')
    {
        printf("Agreed!\n");
    }
    else if(answer[0] == 'n' || answer[0] == 'N')
    {
        printf("Not agreed!\n");
    }
    else
    {
        printf("Invalid input! Please enter 'yes' or 'no'.\n");
    }
    return 0;
}
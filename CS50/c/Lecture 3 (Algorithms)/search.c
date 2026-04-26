#include <stdio.h>
int main(void)
{
    int numbers[10] = {20, 500, 10, 5, 100, 5, 50, 5, 500, 20};
    int n;
    printf("Number: ");
    scanf("%i", &n);
    for(int i = 0; i <10; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

#include <stdio.h>
int main(void)
{
    int x, y, z;
    printf("Enter first integers: ");
    scanf("%d", &x);
    printf("Enter second integers: ");
    scanf("%d", &y);
    printf("Enter third integers: ");
    scanf("%d", &z);
    if(x > y && x > z)
    {
        printf("%d is the greatest among %d and %d\n", x, y, z);
    }
    else if(y > x && y > z)
    {
        printf("%d is the greatest among %d and %d\n", y, x, z);
    }
    else
    {
        printf("%d is the greatest among %d and %d\n", z, x, y);
    }
    return 0;
}
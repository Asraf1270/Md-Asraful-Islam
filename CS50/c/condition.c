#include <stdio.h>
int main(void)
{
    int x, y, z;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
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
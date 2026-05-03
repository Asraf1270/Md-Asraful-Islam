#include <stdio.h>

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %d, y is %d\n", x, y);
    int temp = x;
    x = y;
    y = temp;
    printf("x is %d, y is %d\n", x, y);
}

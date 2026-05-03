#include <stdio.h>

void swap(int *a, int *b);
int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
this is wrong because we are passing the values of x and y to the swap function,
not their addresses. So, the swap function is swapping the values of a and b, 
which are copies of x and y, but it does not affect the original variables x and y in the main function. 
To fix this, we need to pass the addresses of x and y to the swap function, 
and then dereference them inside the swap function to swap their values.

#include <stdio.h>

void swap(int a, int b);
int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
*/
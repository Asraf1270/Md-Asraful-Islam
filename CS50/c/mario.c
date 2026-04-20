#include <stdio.h>

void print_row(int n);

int main(void)
{
    int n = 4;
    for(int row = 0; row < 4; row++)
    {
        print_row(n);
    }
}

void print_row(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
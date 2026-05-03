#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *x = malloc(3 * sizeof(int));  // Allocate memory for an array of 3 integers
    x[0] = 72;  // Assign values to the allocated memory
    x[1] = 73;
    x[2] = 33;
    free(x);  // Free the allocated memory
}